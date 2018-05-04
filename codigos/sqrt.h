#include "systemc.h"


SC_MODULE(raiz){
    sc_in<bool> clk, rst, start;
    sc_in<sc_uint<32> > A;  //inteiro unsigned de 32 bits de entrada do modulo sqrt
    sc_out<bool> ready;
    sc_out<sc_uint<32> > R; //Resultado da operacao sqrt(A)

    void sqrt_root();

    SC_CTOR(raiz){
        SC_CTHREAD(sqrt_root, clk.pos());
    }
};
