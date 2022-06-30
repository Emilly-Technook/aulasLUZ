// ARVORE DE BUSCA BINÁRIA
// Em cada nó todos os reistros com chaves menores q a deste nó estão
// na subárvore da esquerda, enquanto q os registros estão na subávore 
// da direita

// BALANCEAMENTO
// A ordem de inserção determina a formma da ávore
// se inserir os elementos em ordem não vira uma árvore, vira uma lista ligada

// 1. Inicializar a ávore
// 2. Inserção de um elemento
// 3. Busca de um elemento
// 4. Contagem do número de elementos
// 5. Leitura da ávore
// 6. Remoção de um elemento

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

// definindo um nó
typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave; // identificador único
    struct No *esq, *dir;
} NO;

typedef NO *POINT;

// inicializando a ávore
POINT inicialliza(){
    return(NULL);
}

POINT criaNovoNo(TIPOCHAVE ch){
    POINT novoNo = (POINT)malloc(sizeof(NO));
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    novoNo->chave = ch;
    return(novoNo);
}

// Inserção
// Não há duplicação de elementos (chave única)
// Se a raiz for null, inserimos lá
POINT adiciona(POINT raiz, POINT no){
    if(raiz == NULL) return(no);
    if(no->chave < raiz->chave){
        raiz->esq = adiciona(raiz->esq, no);
    } else {
        raiz->dir = adiciona(raiz->dir, no);
    }
    return(raiz);
}

// Busca
POINT contem(TIPOCHAVE ch, POINT raiz){
    if (raiz == NULL) return(NULL);
    if (raiz->chave == ch) return(raiz);
    if (raiz->chave > ch){
        return(contem(ch, raiz->esq));
    } else {
        return(contem(ch, raiz->dir));
    }
}
// contando os nos
int numeroNos(POINT raiz){
    if(!raiz) return 0;
    return(numeroNos(raiz->esq) 
        + 1 
        + numeroNos(raiz->dir));
}

void exibirArvore(POINT raiz){
    if(raiz != NULL){
        printf("%i", raiz->chave);
        printf("(");
        exibirArvore(raiz->esq);
        exibirArvore(raiz->dir);
        printf(")");
    }
}
// Busca binária recursiva. Devolve o ponteiro do nó
// buscado. Abastece pai com o ponteiro para o nó pai.

POINT buscaNo(POINT raiz, TIPOCHAVE ch, POINT *pai){
    POINT atual = raiz;
    *pai = NULL;
    while (atual) {
        if(atual->chave == ch) return(atual);
        *pai = atual;
        if(ch < atual->chave) atual = atual->esq;
        else atual = atual->dir;
    }
    return(NULL);
}

POINT removeNo(POINT raiz, TIPOCHAVE ch){
    POINT pai, no, p, q;
    no = buscaNo(raiz, ch, &pai); // essa função tbm retorna o pai?
    if (!no->esq || !no->dir ){
        if (!no->esq) q = no->dir;
        else q = no->esq;
    } else {
        p = no;
        q = no->esq;
        while (q->dir) {
            p=q;
            q=q->dir;
        }
        if( p!= no){
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if (!pai){
        free(no);
        return(q);
    }
    if (ch < pai->chave) pai->esq = q;
    else pai->dir = q;
    free(no);
    return(raiz);
}


int main(){
    POINT r = inicialliza();
    POINT no = criaNovoNo(23);
    POINT no2 = criaNovoNo(12);
    r = adiciona(r, no);
    r = adiciona(r, no2);
    POINT p = contem(12, r);

    exibirArvore(r);
    printf("\n Numero de nos: %d\n ", numeroNos(r));

    removeNo(r, 12);
    exibirArvore(r);
    printf("\n Numero de nos: %d\n ", numeroNos(r));

}

// Em ordem (in-order traversal)
// Essa travessia primeiro percorre a subárvore da esquerda do nó raiz, acessa o nó atual, seguido da subárvore da direita do nó atual. 
//O código abaixo representa o caso de base, também, que diz que uma árvore vazia também é uma árvore binária de busca.
void inOrder(POINT raiz) {
    // Caso de base
    if (raiz == NULL) return;
    // Percorre primeiro a subárvore da esquerda.
    inOrder(raiz->esq);
    // Imprime o valor do nó atual.
    printf("%d ", raiz->chave);
    // Percorre em seguida a subárvore da direita.
    inOrder(raiz->dir);
}

// Pré-ordem (pre-order traversal)
// Essa travessia primeiro acessa o valor do nó atual, faz a travessia pela subárvore da esquerda e, depois, pela subárvore da direita, respectivamente.
void preOrder(POINT raiz){
    if (raiz == NULL) return;
    // Imprime o valor do nó atual
    printf("%d ", raiz->chave);
    // percorre a subarvore da esquerda
    preOrder(raiz->esq);
    // percorre a suarvore da direita
    preOrder(raiz->dir);
}

// Pós-ordem (post-order traversal)
// Essa travessia coloca o valor do nó raiz no fim, percorrendo primeiro a subárvore da esquerda e depois a da direita.
// A ordem relativa das subárvores da esquerda e da direita permanece a mesma.
// Somente a posição do nó raiz muda em relação às travessias anteriores.
void postOrder(POINT raiz) {
    if (raiz == NULL) return;
        // Percorre primeiro a subárvore da esquerda.
        postOrder(raiz->esq);
        // Percorre em seguida a subárvore da direita.
        postOrder(raiz->dir);
        // Imprime o valor do nó atual.
        printf("%d ", raiz->chave);
}

// Estrutura de Dados - Aula 18 - Árvores binárias de pesquisa - Parte 3
// https://www.youtube.com/watch?v=3koM42vL6js

// https://www.freecodecamp.org/portuguese/news/arvores-binarias-de-busca-bst-explicada-com-exemplos/#:~:text=P%C3%B3s%2Dordem%20(post%2Dorder,em%20rela%C3%A7%C3%A3o%20%C3%A0s%20travessias%20anteriores.

// Algoritimo	Caso Médio	Pior Caso
// Espaço		O(n)	    O(n)
// Busca		O(log n)	O(n)
// Inserção		O(log n)	O(n)
// Remoção		O(log n)	O(n)
