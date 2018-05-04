#include "sqrt_tb.h"

int sc_main(int argc, char* argv[]){
    sc_signal<bool> rst, ready, start;
    sc_signal<sc_uint<32> > A, R;
    sc_clock clk("clk", 1, SC_MS);

    raiz s("s");
    sqrt_tb tb("tb");

    s.rst(rst); s.ready(ready); s.A(A); s.R(R); s.clk(clk); s.start(start);
    tb.rst(rst); tb.ready(ready); tb.A(A); tb.R(R); tb.clk(clk); tb.start(start);


    sc_trace_file* trace_file = sc_create_vcd_trace_file("wave");

    trace_file->set_time_unit(1.0, SC_NS);
    sc_trace(trace_file, A, "A");
    sc_trace(trace_file, R, "R");
    sc_trace(trace_file, clk, "clk");
    sc_trace(trace_file, ready, "ready");
    sc_trace(trace_file, rst, "rst");

    sc_start(100, SC_MS);

    sc_close_vcd_trace_file(trace_file);
    cout << "Criou wave.vcd" << endl;
    return 0;
}
