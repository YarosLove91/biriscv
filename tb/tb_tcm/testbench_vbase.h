#ifndef TESTBENCH_VBASE_H
#define TESTBENCH_VBASE_H

#include <systemc.h>
#include "verilated.h"
#include "verilated_vcd_sc.h"
#include <memory> // Для std::unique_ptr

#define verilator_trace_enable(vcd_filename, dut) \
        if (waves_enabled()) \
        { \
            Verilated::traceEverOn(true); \
            auto v_vcd = std::make_unique<VerilatedVcdC>(); \
            sc_core::sc_time delay_us; \
            if (waves_delayed(delay_us)) \
                dut->trace_enable(v_vcd.get(), delay_us); \
            else \
                dut->trace_enable(v_vcd.get()); \
            v_vcd->open(vcd_filename); \
            this->m_verilate_vcd = std::move(v_vcd); \
        }

//-----------------------------------------------------------------
// Module
//-----------------------------------------------------------------
class testbench_vbase: public sc_module
{
public:
    sc_in <bool>    clk;
    sc_in <bool>    rst;

    virtual void set_testcase(int tc) { }
    virtual void set_delays(bool en) { }
    virtual void set_iterations(int iterations) { }
    virtual void set_argcv(int argc, char* argv[]) { }

    virtual void process(void) { while (1) wait(); }
    virtual void monitor(void) { while (1) wait(); }

    SC_HAS_PROCESS(testbench_vbase);
    testbench_vbase(sc_module_name name): sc_module(name), m_verilate_vcd(nullptr) // Инициализация
    {    
        SC_CTHREAD(process, clk);
        SC_CTHREAD(monitor, clk);
    }

    virtual void add_trace(sc_trace_file * fp, std::string prefix) { }

    virtual void abort(void)
    {
        cout << "TB: Aborted at " << sc_time_stamp() << endl;
        if (m_verilate_vcd)
        {
            m_verilate_vcd->flush();
            m_verilate_vcd->close();
            m_verilate_vcd.reset(); // Установка в nullptr
        }
    }

    bool waves_enabled(void)
    {
        char *s = getenv("ENABLE_WAVES");
        return !(s && !strcmp(s, "no")); // Упрощенный код
    }

    bool waves_delayed(sc_core::sc_time &delay)
    {
        char *s = getenv("WAVES_DELAY_US");
        if (s != NULL)
        {
            uint32_t us = strtoul(s, NULL, 0);
            printf("WAVES: Delay start until %duS\n", us);
            delay = sc_core::sc_time(us, SC_US);
            return true;
        }
        return false; // Упрощенный код
    }    

    std::string getenv_str(std::string name, std::string defval)
    {
        char *s = getenv(name.c_str());
        return (!s || (s && !strcmp(s, ""))) ? defval : std::string(s); // Упрощенный код
    }

protected:
    std::unique_ptr<VerilatedVcdC> m_verilate_vcd; // Использование unique_ptr
};

#endif
