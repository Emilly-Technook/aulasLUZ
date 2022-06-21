// Separa o vetor em dois subvetores, chamando recursivamente a função para ordenar cada subvetor.

// 1. escolher um pivor
// 2. Separa os elementos menores que o pivor para a esquerda e os maiores para a direita
// 3. chamar recursivamente a função para ordenar os subvetores

// executando ...
//1. definir i e j começando pela esquerda e direita respectivamente
//2. fazer a varredura com a variável i para a direita até q encontre um elemento v[i] maior que o pivor
//3. fazer a varredura com a variável j para a esquerda até q encontre um elemento v[j] menor que o pivor
//4. troque v[i] com v[j]

// Performace:
// Melhor caso: O(N log N)
// Pior caso: O(N^2) - quando o pivos esta localizado proximo as psições extremas da lista. Gera particionamento desigual
// Estável: não altera a de dados iguais
// Desvantagens: como escolher o pivor? - isso afeta o desempenho
// Vantagem: mais rapido que o mergeSort(constantes menores)

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void quick_sort(int *a, int left, int right);


int * compara (const void*x, const void*y) {
    return (int *) (*(int *)x - *(int *)y);
}


int main(){
    int vetor[5] = {10,9,8,7,6};
    int i; 
    int num2[MAX-1];

    // Gerar numeros aleatórios
    for (i=0; i<MAX; i++){
        num2[i] = rand() % 10;
        //printf("%d ", rand() % 10);
    }
    // imprimir o array de numeros aleatórios
    printf("\n Elementos desordenados: \n");
    for (i = 0; i < MAX; i++ ) {
      printf("%d ", num2[i] );
    }
    getch();
    // usando uma função nativa do C para ordenar o array: qsort
    // qsort(num2, MAX, sizeof(int), compara);
    quick_sort(num2, 0, MAX-1);
    printf("\n Elementos ordenados: \n");
    for (i=0; i<MAX; i++){
        printf("%d ", num2[i]);
    }
    return 0;
}

// Função de Ordenação por Seleção
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}