#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// classes são sempre UpperCamelCase
class Pessoa {
    // criando os atributos privados da classe
    private:
        int id;
        string name;
        int age;

    public:
        // criando um metodo para acessar os metodos da classe
        void setName(string _name);
        string getName();
        void setId(int _id);
        int getId();
        void setAge(int _age);
        int getAge();
        // contrutor tem o mesmo nome da classe só q não tem retorno
        Pessoa(int _id, string _name, int _idade);
        // destrutor
        ~Pessoa();
};

// a implementação dos metodos ficam fora da classe em C++
// mas poderiam ser feito dentro. Só não é boa pratica nessa linguagem.
void Pessoa::setName(string _name){
    name = _name;
}
string Pessoa::getName(){
    return name;
}
void Pessoa::setId(int _id){
    id = _id;
}
int Pessoa::getId(){
    return id;
}
void Pessoa::setAge(int _age){
    age = _age;
}
int Pessoa::getAge(){
    return age;
}

Pessoa::Pessoa(int _id, string _name, int _idade){
    id = _id;
    name = _name;
    age = _idade;
}

Pessoa::~Pessoa(){
    cout << "Classe Destruida";
}

int main(){
    Pessoa amigo = Pessoa(1, "joao", 30);
    //amigo.setName("Maria");
    //amigo.name = "João";

    // cout << "ID" << amigo.id << endl;
    // cout << "NOME" << amigo.name << endl;
    cout << "NOME: " << amigo.getName();
    // cout << "IDADE" << amigo.age << endl;

    amigo.~Pessoa(); // O objeto continua a exitir sem a classe?

    getch();
    return 0;
}


// https://www.youtube.com/watch?v=o1V4kD5o5rw