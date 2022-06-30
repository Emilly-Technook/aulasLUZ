#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista;
    list<int>::iterator it;
    for (int i = 0; i < 5; i++)
    {
        lista.push_back(i);
    }
    for (int i = 5; i < 10; i++)
    {
        lista.push_front(i);
    }
    // Conteudo da lista: 9 8 7 6 5 0 1 2 3 4
    cout << lista.front() << endl;
    // printa 9 na tela
    cout << lista.back() << endl;
    // printa 4 na tela
    cout << lista.size() << endl;
    // printa o tamanho da lista na tela, que é igual a 10

    for (it = lista.begin(); it != lista.end(); it++)
    {
        // printa os numeros pares começando do inicio da lista
        if (*it % 2 == 0)
        {
            cout << *it << endl;
        }
    }
    it--;
    // adiciona dois 11 antes do 4 na lista
    lista.insert(it, 2, 11);
    for (it = lista.begin(); it != lista.end(); it++)
    {
        // printa os numeros pares
        cout << *it << " ";
    }
    cout << endl;
    it--;            // retira o 4 da lista
    lista.erase(it); // printa o 3 que agora é o novo ultimo elemento da listacout << lista.back() << endl;
                     // limpa a lista inteira
    lista.clear();
    // printará 0 pois a lista está vazia
    cout << lista.size() << endl;