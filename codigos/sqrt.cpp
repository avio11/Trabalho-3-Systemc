#include "sqrt.h"


#define temporizacao 1   //0 = atemporal, 1 = temporizacao aproximada

#if temporizacao == 0

void raiz::sqrt_root(){
    sc_uint<32> temp;
    ready.write(false);

    while(true){
        ready.write(false);

        while(!start){  // Enquanto nao chegar sinal de start o modulo nao inicia o calculo de sqrt
            wait(1);
        }

        unsigned int r=1, d=2, s=4;
        temp = A.read();

        while(s<=temp){ // Algoritmo do calculo da raiz quadrada
            r++;
            d += 2;
            s += (d+1);
        }
        R.write(r);     // escreve o resultado
        ready.write(true);  // abilita a leitura pelo monitor da porta R
        wait(1);

    }

}
#elif temporizacao == 1
void raiz::sqrt_root(){
    sc_uint<32> temp;
    ready.write(false);

    while(true){
        ready.write(false);
        wait(1);
        while(!start){  // Enquanto nao chegar sinal de start o modulo nao inicia o calculo de sqrt
            wait(1);
        }

        unsigned int r=1, d=2, s=4;
        temp = A.read();
        int counter = 0;
        while(s<=temp){
            counter++;
            r++;
            d += 2;
            s += (d+1);
        }
        R.write(r);
        wait(counter);      // espera os ciclos para o algoritmo rodar antes de enviar o resultado
        ready.write(true);
        wait(1);
        ready.write(false);

    }

}
#endif
