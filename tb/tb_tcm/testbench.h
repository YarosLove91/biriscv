#include "testbench_vbase.h"
#include "elf_load.h"
#include <getopt.h>
#include <unistd.h>
#include <iomanip>

#include "riscv_tcm_top_rtl.h"
#include "Vriscv_tcm_top.h"
#include "Vriscv_tcm_top___024root.h"

#include "verilated.h"
#include "verilated_vcd_sc.h"

#define MEM_BASE 0x00000000
#define MEM_SIZE (64 * 1024)

#define DEBUG_TCM

//-----------------------------------------------------------------
// Command line options
//-----------------------------------------------------------------
#define GETOPTS_ARGS "f:c:h"

static struct option long_options[] =
{
    {"elf",        required_argument, 0, 'f'},
    {"cycles",     required_argument, 0, 'c'},
    {"help",       no_argument,       0, 'h'},
    {0, 0, 0, 0}
};

static void help_options(void)
{
    fprintf (stderr,"Usage:\n");
    fprintf (stderr,"  --elf         | -f FILE       File to load\n");
    fprintf (stderr,"  --cycles      | -c NUM        Max instructions to execute\n");
    exit(-1);
}

//-----------------------------------------------------------------
// Module
//-----------------------------------------------------------------
class testbench: public testbench_vbase, public mem_api
{
public:
    //-----------------------------------------------------------------
    // Instances / Members
    //-----------------------------------------------------------------      
    riscv_tcm_top_rtl *m_dut; // Pointing to DUT (Design Under Test)
    
    int                          m_argc;
    char**                       m_argv;
    //-----------------------------------------------------------------
    // Signals
    //-----------------------------------------------------------------    
    sc_signal <bool>            rst_cpu_in;

    sc_signal <axi4_master>      axi_t_in;
    sc_signal <axi4_slave>       axi_t_out;

    sc_signal <axi4_lite_master> axi_i_out;
    sc_signal <axi4_lite_slave>  axi_i_in;

    sc_signal < sc_uint <32> >   intr_in;


    //-----------------------------------------------------------------
    // process: Main loop for CPU execution
    //-----------------------------------------------------------------
    void process(void) 
    {
        uint64_t       cycles         = 0;
        int64_t        max_cycles     = (int64_t)-1;
        const char *   filename       = NULL;
        int            help           = 0;
        int c;        

        int option_index = 0;
        while ((c = getopt_long (m_argc, m_argv, GETOPTS_ARGS, long_options, &option_index)) != -1)
        {
            switch(c)
            {
                case 'f':
                    filename = optarg;
                    break;
                case 'c':
                    max_cycles = (int64_t)strtoull(optarg, NULL, 0);
                    break;
                case '?':
                default:
                    help = 1;   
                    break;
            }
        }        

        if (help || filename == NULL)
        {
            help_options();
            sc_stop();
            return;
        }

        // Force CPU into reset
        rst_cpu_in.write(true);
        
        // Load Firmware
        printf("Running: %s\n", filename);
        elf_load elf(filename, this);
        if (!elf.load())
        {
            fprintf (stderr,"Error: Could not open %s\n", filename);
            sc_stop();
        }
        
        // Release CPU reset after TCM memory loaded
        wait();
        rst_cpu_in.write(false);

        while (true)
        {
            cycles += 1;
            if (cycles >= max_cycles && max_cycles != -1)
                break;

            wait();
        }

        sc_stop();        
    }

    void set_argcv(int argc, char* argv[]) { m_argc = argc; m_argv = argv; }

    //-----------------------------------------------------------------
    // Construction
    //-----------------------------------------------------------------
    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name name) : testbench_vbase(name), m_dut(nullptr) // DUT pointer initialize
    {
        init_dut(); 
    }

    /*
    The m_dut variable is now a class variable for 
    subsequent memory access via the `rootp` mechanism.
    The functions will be represented as follows in 
    the “Vriscv_tcm_top_tcm_mem.h” file
    
    // INTERNAL METHODS
    void __Vconfigure(bool first);
    uint32_t read(uint32_t addr);
    bool write(uint32_t addr, uint32_t data);
    */

    void init_dut() {
        m_dut = new riscv_tcm_top_rtl("DUT");
        m_dut->clk_in(clk);
        m_dut->rst_in(rst);
        m_dut->rst_cpu_in(rst_cpu_in);
        m_dut->axi_t_out(axi_t_out);
        m_dut->axi_t_in(axi_t_in);
        m_dut->axi_i_out(axi_i_out);
        m_dut->axi_i_in(axi_i_in);
        m_dut->intr_in(intr_in);
    }
    /* 
    Tracing of design work must now be enabled separately,
    so that it is possible to preset the system settings. 
    Otherwise, we get an error.
    */

    //Enabling the design tracer
    void enable_verilator_trace() {
        verilator_trace_enable("verilator.vcd", m_dut);
    }
    //-----------------------------------------------------------------
    // Trace
    //-----------------------------------------------------------------
    void add_trace(sc_trace_file * fp, std::string prefix)
    {
        if (!waves_enabled())
            return;

        // Add signals to trace file
        #define TRACE_SIGNAL(a) sc_trace(fp,a,#a);
        TRACE_SIGNAL(clk);
        TRACE_SIGNAL(rst);

        m_dut->add_trace(fp, "");
    }

    //-----------------------------------------------------------------
    // create_memory: Create memory region
    //-----------------------------------------------------------------
    bool create_memory(uint32_t base, uint32_t size, uint8_t *mem = NULL)
    {
        sc_assert(base >= MEM_BASE && ((base + size) < (MEM_BASE + MEM_SIZE)));
        return true;
    }
    //-----------------------------------------------------------------
    // valid_addr: Check address range
    //-----------------------------------------------------------------
    bool valid_addr(uint32_t addr) { return true; } 
    //-----------------------------------------------------------------
    // write: Write byte into memory
    //-----------------------------------------------------------------
    void write(uint32_t addr, uint8_t data)
    {

    #ifdef DEBUG_TCM
        static size_t count = 0;
        std::cout << "Try to write memory\n" 
                << " Addr: " << std::hex << addr 
                << " Data: " << std::setw(2) << std::setfill('0') << (int)data;

        count++;
        std::cout << "\tBytes written: " << count << std::endl;
#endif

        //Template fix. 
        //m_dut->m_rtl->__VlSymsp->TOP__v__u_tcm.write(addr, data);

        //Starting with version 4.2 verilator takes a different approach to memory access.
        // It is no longer possible to directly get write access to internal signals.
        // It is now necessary to access using “DPI-C” or “rootp” via a header file of the form:  “Vriscv_tcm_top.h”.
    }
    //-----------------------------------------------------------------
    // write: Read byte from memory
    //-----------------------------------------------------------------
    uint8_t read(uint32_t addr)
    {

#ifdef DEBUG_TCM
        std::cout << "Try to read memory" << std::endl;
#endif
        // Template fix.
        //return m_dut->m_rtl->__VlSymsp->TOP__v__u_tcm.read(addr);
        
        // Starting with version 4.2 verilator takes a different approach to memory access.
        // It is no longer possible to directly get write access to internal signals.
        // It is now necessary to access using “DPI-C” or “rootp” via a header file of the form:  “Vriscv_tcm_top.h”.
    }
};
