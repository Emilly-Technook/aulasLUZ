// Estrutura linear na qual a inserção e remoção de ites segue o FIFO
//(fist-in-first-out) 
// Os objetos pode ser inseridos a qualquer momento, mas apenas o objeto
// a mais tempo na fila pode ser removido
// APLICAÇÂO: processos assincronos
//INSERÇÃO/EXCLUSÃO: nos lados, inserçao no final e exclusão no início
// enqueue() dequeue()
// dois ponteiros são necessários um para o primeiro e ultimo elemento

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int valor;
	struct No *prox;
} No;

typedef struct {
	No *prim, *ultm;
	int tam;
} Fila;

Fila *criarFila(){
	Fila *fila = (Fila*)malloc(sizeof(Fila));
	fila->prim = NULL;
	fila->ultm = NULL;
	fila->tam = 0;
}

No *criarNo(int valor) {
  No *no = (No*)malloc(sizeof(No));
  no->valor = valor;
  no->prox = NULL;
}

// inserir elementos no fim da fila
void enqueue(Fila *fila,  int valor){
	No *no = criarNo(valor);
	if (fila->prim == NULL) {
		fila->prim = no;
	}else {
		fila->ultm->prox = no;
	}
	fila->ultm = no;
	fila->tam++;
}

// remover elementos no inicio da fila
void dequeue(Fila *fila){
	No *aux = fila->prim; 
	fila->prim = aux->prox;
	free(aux);
	fila->tam--;
	if(fila->prim == NULL){
		fila->ultm == NULL;
	}
}

void limpar(Fila *fila){
	for (No *no = fila->prim; no != NULL; no = no->prox){
		No *aux = no;
		fila->tam--;
		free(aux);
	}
	fila->prim = NULL;
	fila->ultm = NULL;
}

void imprimirFila(Fila *fila){
	for (No *no = fila->prim; no != NULL; no = no->prox ) {
		printf("%d\t", no->valor);
	}
	if(fila->tam > 0) {
		printf("\nTamanho da lista: %d\n", fila->tam);
	} else {
		printf("\n Lista vazia. Adicione elementos\n");
	}
}

void main () {
	int op, valor;
	Fila *fila = criarFila();
	
	while (1) {
		printf( "\n1 - Mostrar fila\n" );
		printf( "2 - Sair\n" );
		printf( "3 - Inserir elemento \n" );
		printf( "4 - Remover elemento \n" );
		printf( "5 - Limpar fila\n" );
		printf( "Opcao? " );
		scanf( "%d", &op );
		switch (op){
		case 1:
			break;
		case 2: // abandonar programa
			exit(0);
		case 3: 
			printf("Valor? ");
			scanf("%d", &valor);
			enqueue(fila, valor);
			break;
		case 4: 
			dequeue(fila);
			break;
		case 5: 
			limpar(fila);
			break;
		}
	}
}



// cos.ufrj.br/~rfarias/cos121/filas.html