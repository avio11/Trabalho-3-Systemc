#include "sqrt.h"

SC_MODULE(sqrt_tb){
    sc_in<bool> ready, clk;
    sc_in<sc_uint<32> > R;
    sc_out<bool> rst, start;
    sc_out<sc_uint<32> > A;

    void aciona();

    SC_CTOR(sqrt_tb){
        SC_CTHREAD(aciona, clk.neg());
    }
};
