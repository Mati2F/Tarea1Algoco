#include <bits/stdc++.h>
using namespace std;

unsigned t0,t1;

int partition(vector<int>& arr, int low, int high) {
  
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

/*
Funcion: partition
***
Descripcion: Escoge el pivote, recorre los elementos y va ordenando los 
más pequeños a la izquierda.
*/

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
Funcion: quickSort
***
Descripcion: Realiza el ordenamiento a analizar de forma recursiva, separando el arreglo 
segun el pivote
***
Mejor Caso: O(n log n)
Peor Caso: O(n^2)
*/

void printVector(vector<int>& arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

/*
Funcion: Print Vector
***
Descripcion: Imprime de forma provisoria el vector en el que se encuentran los datos
solo para revisar si se está efectuando.
*/

void rellenarVector(std::vector<int> &vec, ifstream &archivo) {
    int num;
    vec.clear();
    while (archivo >> num) {
        vec.push_back(num);
    }
}

/*
Funcion: Rellenar Vector
***
Descripcion: Rellena el vector en el que se encuentran los datos del archivo de prueba
*/

int main() {
    ifstream archivo("parcialmente_ordenado.txt");
    int n = 1e2, i = 2;

    if (!archivo.is_open()){
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    while(n != 1e7){
        vector<int> arr(n);
        archivo.clear();
        archivo.seekg(0);

        rellenarVector(arr,archivo);

        t0 = clock();
        quickSort(arr, 0,n-1);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "con n = 10^" << i << ", El Tiempo de Ejecucion es: " << time << "\n";

        n *= 10;
        i++;
    }

    

    return 0;
}
