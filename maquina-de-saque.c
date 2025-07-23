#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() { // core of the program; executions starts here;
    int k; // total de dinheiro disponivel na maquina
    int n;  // numero de pessoas a sacar dinheiro
    int T; // numero de casos teste

    scanf("%d", &T); // leitura do num de casos teste

    // loop de um while para cada caso teste T, que irá ler os valores de k e n para cada caso teste.

    while(T--) { //quando T for zero, o loop para, iterando somente os casos necessários
        scanf("%d %d", &n, &k);
        int *money = (int *)malloc(n * sizeof(int)); // alocando dinamicamente o vetor de dinheiro
        int i;
        char *result = (char *)malloc(n * sizeof(char)); // alocando dinamicamente o vetor de resultados, para imprimir 1 ou zero se a pessoa consegiu sacar o dinheiro, ou na

        for(i = 0; i < n; i++) {
           scanf("%d", &money[i]);// leitura do valor que cada pessoa quer sacar

            if(money[i] <= k){ // nessa situação, a pessoa consegue sacar o dinheiro pois existe credito na maquina
                k -= money[i];
                result[i] = '1';
            }
            else {
                result[i] = '0';
            }
        }
        printf("%s\n", result);
        free(money); 
        free(result); 
    }
    return 0;
}