#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void bubblesort(int *v, int n);

int main(void){
    int i;
    int v[8] = {-1, 7, -3, 11, 4, -2, 4, 8};
    int v2[MAX - 1];

    // Gerar numeros aleatórios
    for (i = 0; i < MAX; i++)
    {
        v2[i] = rand() % 10;
        // printf("%d ", rand() % 10);
    }
    // imprimir o array de numeros aleatórios
    printf("\n Elementos desordenados: \n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", v2[i]);
    }
    printf("\n Click para ordenar: \n");
    getch();

    bubblesort(v2, MAX - 1);
    for (i = 0; i < MAX; i++) printf("%d ", v2[i]);

    putchar('\n');
    return 0;
};

void bubblesort (int vetor[], int n) {
    int k, j, aux;
    for (k = 1; k < n; k++) {
        //printf("\n[%d] ", k);
        for (j = 0; j < n - 1; j++) {
            //printf("%d, ", j);
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}