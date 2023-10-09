#include <iostream>
using namespace std;   

//Estructura para los nodos 
struct Node
{
    int data;
    int prior;
};

class PriorQueue{
    private:
        Node *PQ;
        int N, NumNodes;
    public:
        PriorQueue(int size){
            N=size;
            PQ = new Node[size];
            NumNodes=-1;
        }
        ~PriorQueue(){
            delete [] PQ;
            cout<<"Destructor~"<<endl;
        }

        void Enqueue(int, int);
        int Peek();
        void Update(int, int);
        void Dequeue(int);
        void Display();
};

//Función Enqueue - Ingresa un nodo en la cola de prioridad
void PriorQueue::Enqueue(int value, int priority){
    if (NumNodes == N-1){
        cout<<"La Cola de prioridad esta LLENA\n-----"<<endl;
        return;   
    }
    NumNodes++;

    PQ[NumNodes].data=value;
    PQ[NumNodes].prior=priority;
    cout<<"Nodo ingresado\n-----"<<endl;
}

//Funcion Peek - Devuelve el nivel de prioridad del nodo con mayor prioridad
int PriorQueue::Peek(){
    if (NumNodes==-1){
        cout<<"La cola de prioridad esta VACIA"<<endl;
        return -1;
    }
    int idx=0;
    for (int i=1; i<=NumNodes; i++){
        if (PQ[i].prior>PQ[idx].prior){
            idx=i;
        }
    }
    return PQ[idx].prior;
}

//Función Update - modifica la data de un nodo con la data elegida
void PriorQueue::Update(int aux, int value){
    if (NumNodes==-1){
        cout<<"La cola de prioridad esta VACIA"<<endl;
        return;
    }
    cout<<"Nodo a actualizar: "<<aux<<endl;
    for (int i=0; i<=NumNodes; i++){
        if (PQ[i].data==aux){
            PQ[i].data=value;
            cout<<"Nodo actualizado\n------"<<endl;
            return;
        }
    }
    cout<<"No se encontro el Nodo a actualizar\n------"<<endl;
}

//Funcion Dequeue - Elimina el nodo con mayor prioridad de la cola
void PriorQueue::Dequeue(int idx){
    if (NumNodes==-1){
        cout<<"La cola de prioridad esta VACIA"<<endl;
        return;
        }
    for (int i=0; i<=NumNodes; i++){
        if (PQ[i].prior==idx){
            PQ[i].data=PQ[NumNodes].data;
            PQ[i].prior=PQ[NumNodes].prior;
            NumNodes--;
            cout<<"Nodo eliminado\n------"<<endl;
            return;
        }
        
    }
    cout<<"No se encontro el Nodo a eliminar\n------"<<endl;
    return;
} 

void PriorQueue::Display(){
    cout<<"Nodos:"<<endl;
    for (int i=0; i<=NumNodes; i++){
        cout<<"-"<<PQ[i].data<<" ["<<PQ[i].prior<<"]"<<endl;
    }
    cout<<"-----\n"<<endl;
}

int main(){
    PriorQueue P(4);

    cout<<endl;
    P.Enqueue(1,4);
    P.Enqueue(2,6);
    P.Enqueue(3,8);
    P.Enqueue(4,10);
    P.Display();

    int idx=P.Peek();
    cout<<"El Nodo con mayor prioridad es: "<<idx<<endl;
    cout<<"-----"<<endl;

    P.Dequeue(idx);
    P.Display();

    P.Enqueue(5,12);
    P.Display();

    P.Update(3,6);
    P.Display();
    return 0;
}