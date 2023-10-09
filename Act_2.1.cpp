#include <iostream>
using namespace std;

struct  Node{
    Node *next;
    int data;
    Node *prev;
};

class ListaDobleLigada{
    private: 
        Node *Head;
    public: 
        ListaDobleLigada(): Head(NULL){}
        ~ListaDobleLigada(){
            cout<<"Destructor: ";
            EraseAll();
            delete Head;
        }
        void create(int);
        Node* read(int);
        void update(int, int);
        void del(int);
        void EraseAll();
        void print();
};

//Funcion create para crear nodos
void ListaDobleLigada::create(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if(Head == NULL){
        Head = temp;
    }else{
        Node *aux = Head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = temp;
        temp->prev = aux;
    }
}

//Funcion read para leer nodos
Node* ListaDobleLigada::read(int value){
    Node *aux = Head;
    int posicion = 0;
    while(aux != NULL){
        posicion++;
        if(aux->data == value){
            cout<<"Posicion del numero "<<value<<": "<<posicion<<endl;
            return aux;
        }
        aux = aux->next;
    }
    cout<<"No se encontro el valor"<<endl;
    return NULL;
}

//Funcion update para actualizar nodos
void ListaDobleLigada::update(int value, int value2){
    Node *aux = Head;
    while(aux != NULL){
        if(aux->data == value){
            aux->data = value2;
        }
        aux = aux->next;
    }
}

//Funcion del para eliminar nodos
void ListaDobleLigada::del(int value){
    Node *aux = Head;
    while(aux != NULL){
        if(aux->data == value){
            if(aux == Head){
                Head = aux->next;
                Head->prev = NULL;
                delete aux;
                return;
            }else{
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                delete aux;
                return;
            }
        }
        aux = aux->next;
    }
}

//Funcion EraseAll para eliminar todos los nodos
void ListaDobleLigada::EraseAll(){
    Node *aux = Head;
    while(aux != NULL){
        Head = aux->next;
        delete aux;
        aux = Head;
    }
}

//Funcion print para imprimir los nodos
void ListaDobleLigada::print(){
    Node *aux = Head;
    while(aux != NULL){
        cout<<aux->data<<" ";
        aux = aux->next;
    }
    cout<<endl;
}

int main(){
    ListaDobleLigada lista;
    lista.create(1);
    lista.create(2);
    lista.create(3);
    lista.create(4);
    lista.create(5);
    lista.create(6);
    lista.create(7);
    lista.create(8);
    lista.create(9);
    lista.print();
    lista.del(2);
    lista.update(4, 10);
    lista.print();
    lista.read(3);
}