// Ordenação por mistura
// ideia é dividir o array em 3 partes: left, middle, right
// Divide, recursivamente, o conjunto de dados até q cada subconjunto tenha um elemento
// combina 2 subconjuntos de forma a obter um conjunto maior e ordenado
// Esse processo se repete até q exista apenas um conjunto

// Performance:
// Melhor caso: O(N log N)
// Pior caso: O(N log N)
// Estável: não altera a pasição de dados iguais
// Desvantagens: recursivo e usa um vetor auxiliar durante a ordenação

#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

int main (void) {
  int i;
  int v[8] = { -1, 7, -3, 11, 4, -2, 4, 8 };
  int v2[MAX-1];

    // Gerar numeros aleatórios
    for (i=0; i<MAX; i++){
        v2[i] = rand() % 10;
        //printf("%d ", rand() % 10);
    }
    // imprimir o array de numeros aleatórios
    printf("\n Elementos desordenados: \n");
    for (i = 0; i < MAX; i++ ) {
      printf("%d ", v2[i] );
    }
    printf("\n Click para ordenar: \n");
    getch();

  mergesort(v2, MAX-1);

  for (i = 0; i < MAX; i++) printf("%d ", v2[i]);

  putchar('\n');

  return 0;
}

/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  //  começo da lista é 0 e o final é n-1
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}