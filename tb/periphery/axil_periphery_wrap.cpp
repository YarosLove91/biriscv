#include "axil_periphery_wrap.h"
#include "Vaxil_periphery_wrap.h"

#if VM_TRACE
#include "verilated.h"
#include "verilated_vcd_c.h"
#endif

//-------------------------------------------------------------
// Constructor
//-------------------------------------------------------------
axil_periphery_wrap::axil_periphery_wrap(sc_module_name name): sc_module(name)
{
    s_rtl = std::make_unique<Vaxil_periphery_wrap>("Vaxil_periphery_wrap");

    s_rtl->clk_i(s_clk_in);
    s_rtl->rst_ni(s_rst_in);
    s_rtl->axi_awready(s_axi_awready_out);
    s_rtl->axi_wready(s_axi_wready_out);
    s_rtl->axi_bvalid(s_axi_bvalid_out);
    s_rtl->axi_bresp(s_axi_bresp_out);
    s_rtl->axi_arready(s_axi_arready_out);
    s_rtl->axi_rvalid(s_axi_rvalid_out);
    s_rtl->axi_rdata(s_axi_rdata_out);
    s_rtl->axi_rresp(s_axi_rresp_out);

    s_rtl->axi_awvalid(s_axi_awvalid_in);
    s_rtl->axi_awaddr(s_axi_awaddr_in);
    s_rtl->axi_wvalid(s_axi_wvalid_in);
    s_rtl->axi_wdata(s_axi_wdata_in);
    s_rtl->axi_wstrb(s_axi_wstrb_in);
    s_rtl->axi_bready(s_axi_bready_in);
    s_rtl->axi_arvalid(s_axi_arvalid_in);
    s_rtl->axi_araddr(s_axi_araddr_in);
    s_rtl->axi_rready(s_axi_rready_in);

    s_rtl->ef_tcc32_ext_clk(s_ef_tcc32_ext_clk_in);
    s_rtl->ef_tcc32_irq(s_ef_tcc32_irq_out);
    s_rtl->ef_tcc32_pwm(s_ef_tcc32_pwm_out);
    s_rtl->rtc_irq(s_rtc_irq_out);

    SC_METHOD(async_outputs);
    sensitive << clk_in;
    sensitive << rst_in;
    sensitive << axi_s_in;

    sensitive << s_axi_awready_out;
    sensitive << s_axi_wready_out;
    sensitive << s_axi_bvalid_out;
    sensitive << s_axi_bresp_out;
    sensitive << s_axi_arready_out;
    sensitive << s_axi_rvalid_out;
    sensitive << s_axi_rdata_out;
    sensitive << s_axi_rresp_out;

    sensitive << s_ef_tcc32_irq_out;
    sensitive << s_ef_tcc32_pwm_out;
    sensitive << s_rtc_irq_out;

#if VM_TRACE
    s_vcd         = NULL;
    s_delay_waves = false;
    SC_METHOD(trace_rtl);
    sensitive << clk_in;
#endif
}
//-------------------------------------------------------------
// trace_rtl
//-------------------------------------------------------------
void axil_periphery_wrap::trace_rtl(void)
{
#if VM_TRACE
    if (s_delay_waves)
    {
        if (sc_time_stamp() > s_waves_start)
        {
            cout << "WAVES: Delayed start reached - " << sc_time_stamp() << endl;
            s_delay_waves = false;
        }
    }
    else if (s_vcd)
        s_vcd->dump((int)(sc_time_stamp().to_double()));
#endif
}
//-------------------------------------------------------------
// trace_enable
//-------------------------------------------------------------
void axil_periphery_wrap::trace_enable(VerilatedVcdC * p)
{
#if VM_TRACE
    s_vcd.reset(p); // Устанавливаем новый указатель
    s_rtl->trace (s_vcd.get(), 99);
#endif
}
void axil_periphery_wrap::trace_enable(VerilatedVcdC *p, sc_core::sc_time start_time)
{
#if VM_TRACE
    s_vcd.reset(p); // Устанавливаем новый указатель
    s_delay_waves = true;
    s_waves_start = start_time;
    s_rtl->trace (s_vcd.get(), 99);
#endif
}
//-------------------------------------------------------------
// async_outputs
//-------------------------------------------------------------
void axil_periphery_wrap::async_outputs(void)
{
    s_clk_in.write(clk_in.read());
    s_rst_in.write(rst_in.read());

    axi4_lite_master axi_s_mosi = axi_s_in.read(); // master - biriscv, slave - periphery
    s_axi_awvalid_in.write(axi_s_mosi.AWVALID);
    s_axi_awaddr_in.write(axi_s_mosi.AWADDR);
    s_axi_wvalid_in.write(axi_s_mosi.WVALID);
    s_axi_wdata_in.write(axi_s_mosi.WDATA);
    s_axi_wstrb_in.write(axi_s_mosi.WSTRB);
    s_axi_bready_in.write(axi_s_mosi.BREADY);
    s_axi_arvalid_in.write(axi_s_mosi.ARVALID);
    s_axi_araddr_in.write(axi_s_mosi.ARADDR);
    s_axi_rready_in.write(axi_s_mosi.RREADY);


    axi4_lite_slave axi_s_miso; // master - biriscv, slave - periphery
    axi_s_miso.AWREADY  = s_axi_awready_out.read();
    axi_s_miso.WREADY   = s_axi_wready_out.read();
    axi_s_miso.BVALID   = s_axi_bvalid_out.read();
    axi_s_miso.BRESP    = s_axi_bresp_out.read();
    axi_s_miso.ARREADY  = s_axi_arready_out.read();
    axi_s_miso.RVALID   = s_axi_rvalid_out.read();
    axi_s_miso.RDATA    = s_axi_rdata_out.read();
    axi_s_miso.RRESP    = s_axi_rresp_out.read();
    axi_s_out.write(axi_s_miso);

    s_ef_tcc32_ext_clk_in.write(ef_tcc32_ext_clk_in.read());
    ef_tcc32_irq_out.write(s_ef_tcc32_irq_out.read());
    ef_tcc32_pwm_out.write(s_ef_tcc32_pwm_out.read());
    rtc_irq_out.write(s_rtc_irq_out.read());
}
