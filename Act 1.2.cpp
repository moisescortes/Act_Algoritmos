//Moisés Adrián Cortés Ramos A01642492
//Act 1.2 - Algoritmos de Búsqueda y Ordenamiento 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
using namespace std;

//-----------------arrays Random-----------------/
void arrayRandom(int arr[], int n){        
    srand(time(NULL));

    for (int i=0; i<n; i++){
        arr[i] = rand()%(21-1);
    }
    cout<<"Array sin ordenar: "<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//------------------Insercion--------------------//
void ordenaInsercion(int arr[], int n){
    for (int j=1; j<n; j++){
        int key=arr[j];
        int i=j-1;
        while (i>=0 && arr[i]>key){
            arr[i+1]=arr[i];
            i-=1;
        }
        arr[i+1]=key;
    }
    cout<<"Array ordenada (Insercion):"<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//----------------Burbuja---------------------//
void ordenABurbuja(int arr[], int n){
    for (int i=0; i<n; ++i){
        for (int j=0; j<n-i; ++j){
            if (arr[j] > arr[j+1]){
                swap (arr[j], arr[j+1]);
            }
        }
    }
    cout<<"Array ordenada (Burbuja):"<<endl;
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

//---------------------Merge-------------------//
void merge(int arr[], int l, int m, int r){

}

//---------------------Busqueda secuencial-------------------//
int busqSecuencial(int arr[], int busca, int n){
    cout<<"Busqueda Secuencial..."<<endl;
    cout<<"Numero a buscar: "<<busca<<endl;
    for (int i=0; i<n; i++){
        if (busca==arr[i]){
            cout<<"El numero se encuentra en la posicion "<<i+1<<endl;
            return i;
        }
    }
    cout<<"El numero no se encuentra en el array :("<<endl;
    return -1;
}

//------------------busqueda binaria (iterativa)-----------//
int busqBinariaI(int arr[], int buscar, int low, int high){
    cout<<"Busqueda Binaria (iterativa)..."<<endl;
    cout<<"Numero a buscar: "<<buscar<<endl;
    while (low<=high){
        int mid=(low+high)/2;
        if (buscar==arr[mid]){
            cout<<"El numero se encuentra en la posicion "<<mid+1<<endl;
            return mid;
        }
        else if (buscar<arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<"El numero no se encuentra en el array :("<<endl;
    return -1;
}

//-------------------busqueda binaria (recursivo)-----------//
int busqBinariaR(int arr[], int buscar, int low, int high){
    cout<<"Busqueda Binaria (recursiva)..."<<endl;
    cout<<"Numero a buscar: "<<buscar<<endl;
    if (low<=high){
        int mid=(low+high)/2;
        if (buscar==arr[mid]){
            cout<<"El numero se encuentra en la posicion "<<mid+1<<endl;
            return mid;
        }
        else if (buscar<arr[mid]){
            return busqBinariaR(arr, buscar, low, mid-1);
        }
        else{
            return busqBinariaR(arr, buscar, mid+1, high);
        }
    }
    cout<<"El numero no se encuentra en el array :("<<endl;
    return -1;
}

//----------------------main----------------------//
int main() {
    int n= 7;
    int arr[n] ;
    int* ptr_array;
    ptr_array = arr;
    arrayRandom(ptr_array, n);
    ordenaInsercion(arr, n);

    arrayRandom(ptr_array, n);
    ordenABurbuja(arr, n);

    //arrayRandom(ptr_array, n);
    //ordenaMerge(arr, 0, n);

    srand(time(NULL));
    int busca=rand()%(21-1);
    busqSecuencial(arr, busca, n);
    busqBinariaI(arr, busca, 0, n);
    busqBinariaR(arr, busca, 0, n);
}