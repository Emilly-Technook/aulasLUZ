// O que é uma lista  encadeada? circular?
// É uma estrutura de dados, em q os dados são armazeados de forma sequencial em estruturas chamadas de nós.
// Um nó (vagão de trem) possui um elemento da lista e uma apontador para o proximo elemento da lista
// lista são usadas para implementar pilhas e filas.
// Lista estáticasXligada

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
// estrutura de nó
typedef struct Nodo{
	int info;
	struct No *prox; // erro ao retirar o struct
} No;

// estrutura de lista 
typedef struct {
	No *prim;
	int tam;
} Lista;

Lista* criarLista () {
	Lista *lista = (Lista *)malloc(sizeof(Lista)); // alocação dinâmica
	lista->prim = NULL;
	lista->tam = 0;
}

No* criarNo (int valor, No* posicao) {
	No *no = (No *)malloc(sizeof(No));
	no->info = valor;
	no->prox = posicao;
}

void imprimirLista(Lista *lista){
	No *no;
	for (no = lista->prim; no != NULL; no = no->prox ) {
		printf("%d\t", no->info);
	}
	if(lista->tam > 0) {
		printf("\nTamanho da lista: %d\n", lista->tam);
	} else {
		printf("\n Lista vazia. Adicione elementos\n");
	}
}

void inserirNoIni(int valor, Lista *lista){
	No *novo = criarNo(valor, lista->prim);
	lista->prim = novo;
	lista->tam++;
}

void removerNoIni(Lista *lista){
	No *aux = lista->prim;
	lista->prim = aux->prox;
	lista->tam--;
	free(aux);
}

void limpar(Lista *lista){
	for(No *no = lista->prim; no != NULL ;no = no->prox){
		No *aux = no;
		lista->tam--;
		free(aux);
	}
	lista->prim = NULL;
}

void main () {
	int op, valor;
	Lista *lista = criarLista();
	
	while (1) {
		printf( "\n1 - Mostrar lista\n" );
		printf( "2 - Sair\n" );
		printf( "3 - Inserir elemento no inicio\n" );
		printf( "4 - Remover elemento no inicio\n" );
		printf( "5 - Limpar Lista\n" );
		printf( "Opcao? " );
		scanf( "%d", &op );

		switch (op){
		case 1:
			imprimirLista(lista);
			break;
		case 2: // abandonar programa
			exit(0);
		case 3: // inserir elemento no inicio da lista
			printf("Valor? ");
			scanf("%d", &valor);
			inserirNoIni(valor, lista);
			break;
		case 4: // remover no  inicio
			removerNoIni(lista);
			break;
		case 5: // inserir no final
			limpar(lista);
			break;
		}
	}
	
	
}


//https://www.cos.ufrj.br/~rfarias/cos121/aula_11.html#:~:text=A%20principal%20vantagem%20da%20utiliza%C3%A7%C3%A3o,lista%20para%20realizar%20essas%20opera%C3%A7%C3%B5es.
// https://wagnergaspar.com/lista-encadeada-com-a-linguagem-c/

// Níveis de complexidade
// Numa lista com n itens, temos as seguintes complexidades de tempo no pior caso:

// Inserção
// Cabeça: O(1).
// Cauda: O(n) (ou O(1) quando se tem uma referência pro fim da lista).
// Meio: O(n).

// Eliminação
// Cabeça: O(1).
// Cauda: O(n) (ou O(1) quando se tem uma referência pro fim da lista).
// Meio: O(n).

// https://pt.wikipedia.org/wiki/Lista_ligada