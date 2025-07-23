#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Chef and Dolls problem, solve using XOR operation

int main(){

    int T;
    scanf("%d", &T); //número de casos teste de entrada

    while(T--) {
        int n;
        scanf("%d", &n); 
        int i;
        int xor_var = 0;
        for (i = 0; i < n; i++) {
            int doll;
            scanf("%d", &doll);
            xor_var ^= doll;
        }
        if (xor_var == 0) {
            //número de bonecas é par, entao nao há bonecas perdidas
        } else {
            printf("%d\n", xor_var); 
        }
    }
    return 0;
}