#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Node {
private:
    int chave;
    Node *proximo;
    string volume;
public:
    // sobrecarga de metodos //
    Node();
    Node(int _chave);
    Node(int _chave, Node *_proximo);
    Node(int _chave, Node *_proximo, string _volume);
    //  sobrecarga de operadores //
    Node( string _volume){
        volume = _volume;
    };
    Node operator+ (Node &node2){
        return Node( volume + node2.volume);
    };
    // destruindo a classe //
    ~Node();
};

Node::Node(int _chave){
    chave = _chave;
    proximo = NULL;
    volume = ' ';
}
Node::Node(int _chave, Node *_proximo){
    chave = _chave;
    proximo = _proximo;
    volume = ' ';
}
Node::Node(int _chave, Node *_proximo, string _volume){
    chave = _chave;
    proximo = _proximo;
    volume = _volume;
}
Node::~Node(){
    cout << "Classe Destruida";
}

int main(){
    Node n0;
    Node *no = new Node();
    Node n1 {1};
    Node n2 = Node(2, &n1);
    Node n3 = Node(3, &n2, "dados3");
    Node n4 = n1 + n2;
    n3.~Node();
    delete [] &no; 

    return 0;
}

