//Moises Adrian Cortes Ramos
//A01642492

//Act 1.1-Funciones Iterativas, Recursivas y su análisis de Complejidad

#include <iostream>

int sumaIterativa(int n){
    int sum=0;
    if (n==0)
        return 1;
    for (int i=1; i<=n; i++){
        sum+=i;
    }
    return sum;
}

int sumaRecursiva(int n){
    if (n<=1)
        return 1;
    else 
        return n + sumaRecursiva(n-1);
}

int sumaDirecta(int n){
    return (n*(n+1))/2;
}
    
void pruebaFunciones(int n){
    std::cout<<"Sumas del 1 al "<<n<<std::endl;
    if (n>=0){
        std::cout<<"Suma Iterativa: "<<sumaIterativa(n)<<std::endl;
        std::cout<<"Suma Recursiva: "<<sumaRecursiva(n)<<std::endl;
        std::cout<<"Suma Directa: "<<sumaDirecta(n)<<std::endl;
    }
    else
        std::cout<<"No es un numero positivo"<<std::endl;
    return;
}

int main(){
    pruebaFunciones(-5);
    pruebaFunciones(14);
    pruebaFunciones(0);
    pruebaFunciones(1234);
}