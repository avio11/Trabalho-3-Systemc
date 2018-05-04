#include "sqrt_tb.h"

void sqrt_tb::aciona(){
    int flag;
    wait(1);
    start.write(true);
    rst.write(false);
    A.write(49);
    wait(1);

    while(!flag){   // fica no loop enquanto o resultado nao estiver disponivel na porta "R"
        if(ready){
            cout << "time:" << sc_time_stamp() << " " << "SQRT(" << A << ") = " << R << endl;
            flag = 1;
        }
        if(!start){
            wait(4);
            start.write(true);
        }
        wait(1);
    }
    //wait(1);
    start.write(1);
    flag = 0;
    A.write(64);
    wait(1);
    while(!flag){
        if(ready){
            cout << "time:" << sc_time_stamp() << " " << "SQRT(" << A << ") = " << R << endl;
            flag = 1;
        }
        if(!start){
            wait(4);
            start.write(true);
        }
        wait(1);
    }
    //wait(1);
    start.write(1);
    flag = 0;
    A.write(9);
    wait(1);
    while(!flag){
        if(ready){
            cout << "time:" << sc_time_stamp() << " " << "SQRT(" << A << ") = " << R << endl;
            flag = 1;
        }
        if(!start){
            wait(4);
            start.write(true);
        }
        wait(1);
    }
}
