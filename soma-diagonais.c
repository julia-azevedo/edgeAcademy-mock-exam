#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


long long sum_ds_dp(char *ptr_m1, int *L, int diagonal_type)
 {
    long long current_sum = 0;
    char *ptr = ptr_m1;
    int chars_read; // aqui vamos armazenar o numero de caracteres lidos com sucesso para localizar o ponteiro
    int current_row = 0;
    int current_col = 0;
    // vamos incrementando os valores de current_row e current_col conforme avançamos os numeros na matriz
    int temp_val;
    if (*ptr == '[') {
        ptr++;
    } else {
        return -1;
    }
    while (*ptr == '[') { //loop de linhas
        ptr++; //pular o caractere de inicio de linha
        current_col = 0;

        //loop interno para ler os números de uma linha da matriz
        while(sscanf(ptr, "%d%n", &temp_val, &chars_read) == 1) {
            if(diagonal_type == 0) {
                if(current_row == current_col) {
                    current_sum += temp_val; //na variavel da soma, adicionei o primeiro valor lido pelo sscanf
                }
            }
            else { //diagonal_type == 1 que é a diganoal secundaria da segunda matriz
                if (current_col+current_row == *L - 1) {
                    
                    current_sum += temp_val; 
                    
                }
            }

            ptr += chars_read; // avançar o ponteiro para o próximo número
            current_col++;

            if (*ptr == ',') {
                ptr++; 
            } else {
                break;
            }
        } // Término do loop de colunas 

        if (*ptr == ']') {
            ptr++;
        } else {
            return -1; // erro no formato da matriz
        }

        // determinar o valor de L (tamanho da matriz) após o processamento da primeira linha
        if (current_row == 0) {
            *L = current_col; 
        } else if (*L != current_col){
            return -1; //matriz não é quadrada.
        }

        current_row++;

        if (*ptr == ',') {
            ptr++;
        } else {
            break;
        }
    } //fim do loop de linhas

    if (*ptr == ']') {
    } else {
        return -1;
    }
    if (current_row != *L || *L == 0) {
        return -1;
    }
    return current_sum; 
 }

int main() {
    char m1[500];
    char m2[500];
    char *ptr1 = m1;
    char *ptr2 = m2;
    int L_mat1 = 0;
    long long sum_diag1;
    long long sum_diag2;

    fgets(m1, sizeof(m1), stdin); //toda vez que ler uma matriz como string, aplica funcao "strcspn" para remover o \n
    m1[strcspn(m1, "\n")] = 0; 
    fgets(m2, sizeof(m2), stdin);
    m2[strcspn(m2, "\n")] = 0; 

    sum_diag1 = sum_ds_dp(ptr1, &L_mat1, 0);

    sum_diag2 = sum_ds_dp(ptr2, &L_mat1, 1);
    long answ = sum_diag1 + sum_diag2;
    printf("%lld\n", answ);
    

    return 0;
}