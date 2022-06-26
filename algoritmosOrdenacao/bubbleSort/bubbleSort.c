#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define MAX 10 // usar malloc

//void bubblesort(int *v_3, int n);

int main(void){
    int i;
    //int v[8] = {1,2,3,4, 0,5,6, 7};
    //int v_2[MAX - 1];
    int *v_3 =(int*)malloc(MAX*sizeof(int));

    //Gerar numeros aleatórios
    for (i = 0; i < MAX; i++) {
        v_3[i] = rand() % 10;
    }
    // imprimir o array de numeros aleatórios
    printf("\n Elementos desordenados: \n");
    for (i = 0; i < MAX; i++) {
        printf("%d ", v_3[i]);
    }
    printf("\n Click para ordenar: \n");
    getch();

    bubblesort(v_3, MAX );
    printf("\n Array ordenado: ");
    for (i = 0; i < MAX; i++) printf("%d ", v_3[i]);

    putchar('\n');
    return 0;
};

void bubblesort (int vetor[], int n) {
    int k, j, aux;
    bool swaped = true;

    for (k = 1; k < n && swaped; k++) {
        
        //printf("\n[%d] ", k);
        swaped = false;
        for (j = 0; j < n - 1; j++) {
            //printf("%d, ", j);
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
                swaped = true;
            }
        }
        // if(swaped == false) {
        //     break;
        // }

    }
}