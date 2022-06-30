// Discuta sobre a utilização de Herança e Composição. (qual é melhor pra gente e porque?)

// Composição é quando um objeto USA outro objeto
// A composição também é uma forma de extensão, só que pela delegação de trabalho para outro objeto.
// Diferente da herança clássica onde tipo, atributos e métodos são estendidos.
// Quando uma classe precisa usar o comportamento de outra, usualmente é melhor usar composição.
// A vantagem é q posso delegar melhor as responsabilidades no meu código
// Alguns objetos podem dificultar o relacionamento e até mesmo o gerenciamento deles como dependências
// e o código pode ficar menos previsível. Como solução, a literatura indicar usar injeção de dependências

// https://www.treinaweb.com.br/blog/devo-usar-heranca-ou-composicao#:~:text=A%20composi%C3%A7%C3%A3o%20tamb%C3%A9m%20%C3%A9%20uma,usualmente%20%C3%A9%20melhor%20usar%20composi%C3%A7%C3%A3o.

#include <iostream>
#include <queue>
#include <list>
#include <stack>

using namespace std;

class No
{
private:
    int chave;
    No *proximo;

public:
    No();
    No(int _chave);
    No *getProximo();
    int getChave();
    void setProximo(No *no)
    {
        proximo = no;
    }
    ~No();
};
No *No::getProximo()
{
    return proximo;
};
int No::getChave()
{
    return chave;
};
No::No(int _chave)
{
    chave = _chave;
    proximo = NULL;
};
No::~No(){
};
class Lista
{
private:
    int tam;
    No *inicio, *fim;

public:
    Lista();
    void imprimir();
    ~Lista();
    void inserirInicio(int _chave);
    void removerInicio();
    void inserirNoFim(int _chave);
    void removerNoFim();
};
void Lista::inserirInicio(int _chave)
{
    No *no = new No(_chave);
    if (inicio == NULL)
    {
        no->setProximo(NULL);
        inicio = no;
        fim = no;
    }
    else
    {
        no->setProximo(inicio);
        inicio = no;
    }
    tam++;
};
void Lista::removerInicio()
{
    if (inicio != NULL)
    {
        No *aux = inicio;
        inicio = aux->getProximo();
        tam--;
        if (inicio == NULL)
        {
            fim = NULL;
        }
    }
};
void Lista::inserirNoFim(int _chave)
{
    No *no = new No(_chave);
    if (fim == NULL)
    {
        inicio = no;
        fim = no;
        tam++;
    }
    else
    {
        No *aux = fim;
        no->setProximo(NULL);
        fim->setProximo(no);
        fim = no;
        tam++;
    }
};
void Lista::removerNoFim()
{

    if (inicio == NULL)
    {
        // printf("\n\n >> vazio << \n\n");
    }
    else
    {
        No *penultimo = inicio;
        
        while (penultimo->getProximo() != NULL && penultimo != fim)
        {
            penultimo = penultimo->getProximo();
            if (penultimo->getProximo() == fim)
            {   
                free(fim);
                fim = penultimo;
                fim->setProximo(NULL);
            }
        }
        tam--;
   }
};
Lista::Lista()
{
    inicio = NULL;
    fim = NULL;
    tam = 0;
};
void Lista::imprimir()
{
     printf("\n Imprimindo...\n");
    for (No *aux = inicio; aux != NULL; aux = aux->getProximo())
    {
        printf("%d\t", aux->getChave());
    }
};
Lista::~Lista(){
    for (No *aux = inicio; aux != NULL; aux = aux->getProximo()){
        inicio = inicio->getProximo();

        if(inicio = fim){
            fim = NULL;
        }
        delete aux;
        tam--;
    }
};

class Pilha
{
private:
    Lista *lista;

public:
    Pilha();
    ~Pilha();
    void push(int _chave);
    void pop();
    void imprimir();
};
Pilha::Pilha()
{
    Lista *lista = new Lista();
    // printf("\n criando: %d\n", lista);
};
void Pilha::push(int _chave)
{
    lista->inserirNoFim(_chave);
};
void Pilha::pop()
{
    lista->removerNoFim();
};
void Pilha::imprimir()
{
    lista->imprimir();
}
Pilha::~Pilha(){
    delete lista;
}

class Fila
{
private:
    Lista *lista;

public:
    Fila();
    ~Fila();
    void enqueue(int _chave);
    void dequeue();
    void imprimir();
};
Fila::Fila()
{
    lista = new Lista();
};
void Fila::enqueue(int _chave)
{
    lista->inserirNoFim(_chave);
};
void Fila::dequeue()
{
    lista->removerInicio();
};
void Fila::imprimir()
{
    lista->imprimir();
}
Fila::~Fila(){
    delete lista;
}

int main()
{
    Lista *lista = new Lista();

    printf("\n Inserindo no fim: \n ");
    lista->inserirNoFim(80);
    lista->imprimir();

    printf("\n Inserindo no inicio: \n");
    lista->inserirInicio(12);
    lista->inserirInicio(13);
    lista->inserirInicio(14);
    lista->imprimir();

    printf("\n Removendo no inicio: \n");
    lista->removerInicio();
    lista->imprimir();

    printf("\n Removendo no fim: \n");
    lista->removerNoFim();
    lista->imprimir();


    // Pilha *pilha = new Pilha();
    // pilha->push(1);
    // pilha->push(2);
    // pilha->push(3);
    // pilha->imprimir();
    // pilha->pop();
    // pilha->imprimir();

    // Fila *fila = new Fila();
    // fila->enqueue(1);
    // fila->enqueue(2);
    // fila->imprimir();
    // fila->dequeue();
    // fila->imprimir();

    return 0;
}