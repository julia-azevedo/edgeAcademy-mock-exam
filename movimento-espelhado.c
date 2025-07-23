#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// questão de array bidimensional

int main() { 
    int n;
    char coord[500];
    char *ptr = coord;
    int chars_read;
    scanf("%d", &n);
    getchar(); // Limpa o buffer do teclado.
    fgets(coord, sizeof(coord), stdin); 
    coord[strcspn(coord, "\n")] = 0; // ignora o caractere de nova linha caso seja encontrado



    int is_first_coord = 1;
    int x, y;

    while (sscanf(ptr, "(%d,%d)%n", &x, &y, &chars_read) == 2) { // retorna o numero de items que foram lidos e atribuidos com sucesso.

        int y_mirrored;

        y_mirrored = (n + 1) - y;
        if(!is_first_coord) {
            printf(",");
        }
        printf("(%d,%d)", x, y_mirrored);
        is_first_coord = 0;
        ptr += chars_read; //avançar o ponteiro exatamente para a proxima coordeanda depois de ler todos os carecteres da primeira coordenada

        if(*ptr == ',') { //avançar
            ptr++;
        }
    }

    printf("\n");
    return 0;
}