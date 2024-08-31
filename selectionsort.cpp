#include <bits/stdc++.h>
using namespace std;

unsigned t0,t1;

void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

/*
Funcion: Selection Sort
***
Descripcion: Realiza el ordenamiento a analizar
***
Mejor Caso: O(n^2)
Peor Caso: O(n^2)
*/

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
Funcion: Print Array
***
Descripcion: Imprime de forma provisoria el arreglo en el que se encuentran los datos
solo para revisar si se está efectuando.
*/


void rellenarArray(int arr[], int &n, ifstream &archivo){
    int num,i=0;
    while(archivo >> num){
        if(i < n){
            arr[i] = num;
            i++;
        }
    }
    n = i;
}

/*
Funcion: Rellenar Array
***
Descripcion: Rellena el arreglo en el que se encuentran los datos del archivo de prueba
*/

int main(){
    ifstream archivo("CasosDePrueba.txt");

    if (!archivo.is_open()){
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    int n = 1e7, arr[n];
    rellenarArray(arr,n,archivo);

    t0 = clock();
    selectionSort(arr, n);
    t1 = clock();

    printArray(arr,n);
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de Ejecucion: " << time << endl;
}
