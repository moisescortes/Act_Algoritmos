#include <iostream>
using namespace std; 

struct Node{
    int value;
};

class Queue{
    private:
    Node *QueueArray;
    int front, rear, N;
    public:
    Queue (int size){
        N=size;
        QueueArray= new Node[size];
        front = rear = -1;
    }
    ~Queue(){
        delete QueueArray;
    }

    void Enqueue(int);
    void Peek(int);
    void Update(int);
    Node* Dequeue(int);
};

//Función para agregar un nodo a la fila
void Queue::Enqueue(int n){
    if (front==0 && rear==N-1) //Se asegura de que la fila no este llena
        cout<<"La fila esta llena"<<endl;
    else{
        if (front==-1)
            front=0;
        rear++;
        QueueArray[rear].value=n;
    }
}

void Queue::Peek(int n){
    if (front==-1)
        cout<<"La fila esta vacia"<<endl;
    else{
        for (int i=front; i<=rear; i++){
            if (QueueArray[i].value==n){
                cout<<"El valor "<<n<<" esta en la posicion "<<i+1<<endl;
                return;
            }
        }
        cout<<"No esta en la fila"<<endl;
    }
}

void Queue::Update(int n){
    if (front==-1)
        cout<<"La fila esta vacia"<<endl;
    else{
        for (int i=front; i<=rear; i++){
            if (QueueArray[i].value==n){
                cout<<"Ingrese el nuevo valor: ";
                cin>>QueueArray[i].value;
                cout<<"El valor "<<n<<" ha sido actualizado"<<endl;
                return;
            }
        }
        cout<<"El valor "<<n<<" no esta en la fila"<<endl;
    }
}

Node* Queue::Dequeue(int n){
    if (front==-1)
        cout<<"La fila esta vacia"<<endl;
    else{
        for (int i=front; i<=rear; i++){
            if (QueueArray[i].value==n){
                Node *temp = new Node;
                temp->value=QueueArray[i].value;
                for (int j=i; j<rear; j++){
                    QueueArray[j].value=QueueArray[j+1].value;
                }
                rear--;
                cout<<"El valor "<<n<<" ha sido eliminado"<<endl;
                return temp;
            }
        }
        cout<<"El valor "<<n<<" no esta en la fila"<<endl;
    }
}

int main(){
    int size, opcion, valor;
    cout<<"Ingrese el tamaño de la fila: ";
    cin>>size;
    Queue fila(size);
    do{
        cout<<"1. Agregar un nodo a la fila"<<endl;
        cout<<"2. Buscar un nodo en la fila"<<endl;
        cout<<"3. Actualizar un nodo de la fila"<<endl;
        cout<<"4. Eliminar un nodo de la fila"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        switch (opcion){
            case 1:
                cout<<"Ingrese el valor del nodo: ";
                cin>>valor;
                fila.Enqueue(valor);
                break;
            case 2:
                cout<<"Ingrese el valor del nodo: ";
                cin>>valor;
                fila.Peek(valor);
                break;
            case 3:
                cout<<"Ingrese el valor del nodo: ";
                cin>>valor;
                fila.Update(valor);
                break;
            case 4:
                cout<<"Ingrese el valor del nodo: ";
                cin>>valor;
                fila.Dequeue(valor);
                break;
            case 5:
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(opcion!=5);
    return 0;
}