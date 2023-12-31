//Realiza en forma individual una clase en C++ llamada "priority_queue" 
//que tenga las siguientes operaciones utilizando un heap y simulando 
//una fila priorizada de enteros con prioridad de valor mayor.

#include <iostream>
#include <vector>
using namespace std;

class priority_queue{
    private:
        vector<int> vect;
    public:
        priority_queue();
        ~priority_queue();
        void heapify(vector <int>&, int);
        void Push(int);
        void Pop();
        int Top();
        bool Empty();
        int Size();
        void DeleteAll();

        
};

//Constructor
priority_queue::priority_queue(){
    vect = {};
}

//Destructor
priority_queue::~priority_queue(){
    DeleteAll();
}

//Funcion Heapify
void priority_queue::heapify(vector <int> &hT, int i){
    int size = hT.size();
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2;

    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;
    if (largest != i){
        swap(hT[i], hT[largest]);
        heapify(hT, largest);
    }
}
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//Funcion Push
void priority_queue::Push(int data){
    int size = vect.size();
    if (size == 0){
        vect.push_back(data);
    }
    else{
        vect.push_back(data);
        for (int i = size / 2 - 1; i >= 0; i--){
            heapify(vect, i);
        }
    }
}

//Función Pop
void priority_queue::Pop(){
    int size = vect.size();
    if (size == 0){
        cout << "El vector esta vacio" << endl;
        return;
    }
    vect[0] = vect[size - 1];
    vect.pop_back();
    heapify(vect, 0);
}

//Función Top
int priority_queue::Top(){
    if (vect.size() != 0){
        return vect[0];
    }
    cout << "El vector esta vacio " ;
    return -1;
}

//Función Empty
bool priority_queue::Empty(){
    if (vect.size() == 0)
        return true;
    else
        return false;
}

//Función Size
int priority_queue::Size(){
    return vect.size();
}

//Funcion DelleteAll
void priority_queue::DeleteAll(){
    vect.clear();
}

int main(){
    //Caso de prueba 1 (PQ con 8 datos)
    cout<<"\nCaso de prueba 1"<<endl;
    priority_queue pq1;
    pq1.Push(3);
    pq1.Push(5);
    pq1.Push(1);
    pq1.Push(2);
    pq1.Push(4);
    pq1.Push(6);
    pq1.Push(7);
    pq1.Push(8);
    pq1.Pop();
    cout<<"Dato con la mayor prioridad: "<<pq1.Top()<<endl;
    if (pq1.Empty() == true)
        cout<<"PQ esta vacio"<<endl;
    else
        cout<<"PQ no esta vacio"<<endl;
    cout<<"Tamano de PQ: "<<pq1.Size()<<endl;

    //Caso de prueba 2 (PQ con 5 datos)
    cout<<"\nCaso de prueba 2"<<endl;
    priority_queue pq2;
    pq2.Push(1);
    pq2.Push(2);
    pq2.Push(3);
    pq2.Push(4);
    pq2.Push(5);
    pq2.Pop();
    cout<<"Dato con la mayor prioridad: "<<pq2.Top()<<endl;
    if (pq2.Empty() == true)
        cout<<"PQ esta vacio"<<endl;
    else
        cout<<"PQ no esta vacio"<<endl;
    cout<<"Tamano de PQ: "<<pq2.Size()<<endl;

    //Caso de prueba 3 (PQ con 0 datos)
    cout<<"\nCaso de prueba 3"<<endl;
    priority_queue pq3;
    pq3.Pop();
    cout<<"Dato con la mayor prioridad: "<<pq3.Top()<<endl;
    if (pq3.Empty() == true)
        cout<<"PQ esta vacio"<<endl;
    else
        cout<<"PQ no esta vacio"<<endl;
    cout<<"Tamano de PQ: "<<pq3.Size()<<endl;

    //Caso de prueba 4 (PQ con 1 dato)
    cout<<"\nCaso de prueba 4"<<endl;
    priority_queue pq4;
    pq4.Push(1);
    pq4.Pop();
    cout<<"Dato con la mayor prioridad: "<<pq4.Top()<<endl;
    if (pq4.Empty() == true)
        cout<<"PQ esta vacio"<<endl;
    else
        cout<<"PQ no esta vacio"<<endl;
    cout<<"Tamano de PQ: "<<pq4.Size()<<endl;

    return 0;    
}
