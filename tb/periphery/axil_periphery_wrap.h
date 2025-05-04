#ifndef AXIL_PERIPHERY_WRAP_H
#define AXIL_PERIPHERY_WRAP_H

#include <systemc.h>

#include "verilated.h"
#include "verilated_vcd_sc.h"
#include "axi4_lite.h"
#include "axi4.h"

class Vaxil_periphery_wrap;
class VerilatedVcdC;

//-------------------------------------------------------------
// axil_periphery_wrap: RTL wrapper class
//-------------------------------------------------------------
class axil_periphery_wrap: public sc_module
{
public:
    sc_in <bool> clk_in;
    sc_in <bool> rst_in;

    sc_out <axi4_lite_slave>  axi_s_out;
    sc_in <axi4_lite_master> axi_s_in;

    sc_in  <bool> ef_tcc32_ext_clk_in;
    sc_out <bool> ef_tcc32_irq_out;
    sc_out <bool> ef_tcc32_pwm_out;
    sc_out <bool> rtc_irq_out;
    

    //-------------------------------------------------------------
    // Constructor
    //-------------------------------------------------------------
    SC_HAS_PROCESS(axil_periphery_wrap);
    axil_periphery_wrap(sc_module_name name);

    //-------------------------------------------------------------
    // Trace
    //-------------------------------------------------------------
    virtual void add_trace(sc_trace_file *vcd, std::string prefix)
    {
        #undef  TRACE_SIGNAL
        #define TRACE_SIGNAL(s) sc_trace(vcd,s,prefix + #s)

        TRACE_SIGNAL(clk_in);
        TRACE_SIGNAL(rst_in);
        TRACE_SIGNAL(axi_s_out);
        TRACE_SIGNAL(axi_s_in);

        #undef  TRACE_SIGNAL
    }

    void async_outputs(void);
    void trace_rtl(void);
    void trace_enable(VerilatedVcdC *p);
    void trace_enable(VerilatedVcdC *p, sc_core::sc_time start_time);

    //-------------------------------------------------------------
    // Signals
    //-------------------------------------------------------------
private:
    sc_signal <bool> s_clk_in;
    sc_signal <bool> s_rst_in;
    // axil inputs
    sc_signal <bool>         s_axi_awvalid_in;
    sc_signal <sc_uint<32> > s_axi_awaddr_in;
    sc_signal <bool>         s_axi_wvalid_in;
    sc_signal <sc_uint<32> > s_axi_wdata_in;
    sc_signal <sc_uint<4> >  s_axi_wstrb_in;
    sc_signal <bool>         s_axi_bready_in;
    sc_signal <bool>         s_axi_arvalid_in;
    sc_signal <sc_uint<32> > s_axi_araddr_in;
    sc_signal <bool>         s_axi_rready_in;

    // axil outputs
    sc_signal <bool>         s_axi_awready_out;
    sc_signal <bool>         s_axi_wready_out;
    sc_signal <bool>         s_axi_bvalid_out;
    sc_signal <sc_uint<2> >  s_axi_bresp_out;
    sc_signal <bool>         s_axi_arready_out;
    sc_signal <bool>         s_axi_rvalid_out;
    sc_signal <sc_uint<32> > s_axi_rdata_out;
    sc_signal <sc_uint<2> >  s_axi_rresp_out;

    sc_signal <bool> s_ef_tcc32_ext_clk_in;
    sc_signal <bool> s_ef_tcc32_irq_out;
    sc_signal <bool> s_ef_tcc32_pwm_out;
    sc_signal <bool> s_rtc_irq_out;

public:
    std::unique_ptr<Vaxil_periphery_wrap> s_rtl;
#if VM_TRACE
    std::unique_ptr<VerilatedVcdC>  s_vcd;
    bool             s_delay_waves;
    sc_core::sc_time s_waves_start;
#endif 
};

#endif