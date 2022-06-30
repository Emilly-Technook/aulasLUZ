// Estrutura linear para armazenamento de itens q são inseridos e removidos
// de acordo com o LIFO (last-in-first-out)
// Os objetos podem ser inseridos a qualquer momento, mas apenas o objeto
//  q foi inserido por ultimo pode ser removido.
// APLICAÇÃO: implementação de funções recursivas
// INSERÇÃO/EXCLUSÃO: topo // push() pop()

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int valor;
  struct No *prox;
} No; 

typedef struct {
  No *topo;
  int tam;
} Pilha;

Pilha *criarPilha(){
  Pilha *pilha = (Pilha *)malloc(sizeof(No));
  pilha->tam = 0;
  pilha->topo = NULL;
}

No *criarNo(int valor) {
  No *no = (No*)malloc(sizeof(No));
  no->valor = valor;
  no->prox = NULL;
}

void imprimirPilha(Pilha *pilha){
  for (No *no = pilha->topo; no != NULL; no = no->prox ) {
		printf("%d\t", no->valor);
	}
  	if(pilha->tam > 0 ) {
		printf("\nTamanho da lista: %d\n",pilha->tam);
	} else {
		printf("\n Lista vazia. Adicione elementos\n");
	}
}

void push(Pilha *pilha, int valor){
  No *no = criarNo(valor);
  no->prox = pilha->topo;
  pilha->tam++;
  pilha->topo = no;
}

void pop(Pilha *pilha){
  No *no = pilha->topo;
  pilha->topo = no->prox;
  pilha->tam--;
  free(no);
} 

void limpar(Pilha *pilha){
 	for(No *no = pilha->topo; no != NULL ;no = no->prox){
		No *aux = no;
		pilha->tam--;
		free(aux);
	}
	pilha->topo = NULL;
}


int main(void)
{ 
  int op, valor;
  Pilha *pilha = criarPilha();

  while (1) {
		printf( "\n1 - Mostrar pilha\n" );
		printf( "2 - Sair\n" );
		printf( "3 - Inserir elemento\n" );
		printf( "4 - Remover elemento\n" );
		printf( "5 - Limpar pilha\n" );
		printf( "Opcao? " );
		scanf( "%d", &op );

		switch (op){
		case 1:
			imprimirPilha(pilha);
			break;
		case 2: // abandonar programa
			exit(0);
		case 3: // inserir 
      printf("Valor? ");
			scanf("%d", &valor);
      push(pilha, valor);
			break;
		case 4: // remover 
			pop(pilha);
			break;
		case 5: 
      limpar(pilha);
      break;
		}
	}

// https://www.cprogressivo.net/2014/05/Pilhas-Stack-em-C-O-Que-E-Como-Implementar-Tutorial-C-Estrutura-de-Dados.html