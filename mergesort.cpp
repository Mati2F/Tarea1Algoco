#include <bits/stdc++.h>
using namespace std;

unsigned t0,t1;

void merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*
Funcion: merge
***
Descripcion: Junta las dos listas ordenadas para formar la lista original ordenada.
*/

void mergeSort(vector<int>& arr, int left, int right){
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

/*
Funcion: mergeSort
***
Descripcion: Realiza el ordenamiento a analizar de forma recursiva, separando el arreglo 
en mitades y ordenandolas.
***
Mejor Caso: O(n log n)
Peor Caso: O(n log n)
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

int main(){
    ifstream archivo("CasosDePrueba.txt");

    if (!archivo.is_open()){
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    int n = 1e7;
    vector<int> arr(n);
    rellenarVector(arr,archivo);

    t0 = clock();
    mergeSort(arr, 0,n-1);
    t1 = clock();

    printVector(arr);
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de Ejecucion: " << time << endl;

    return 0;
}
