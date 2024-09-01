#include <bits/stdc++.h>
using namespace std;

unsigned t0,t1;

void selectionSort(vector<int>& arr, int n){
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
        selectionSort(arr, n);
        t1 = clock();

        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "con n = 10^" << i << ", El Tiempo de Ejecucion es: " << time << "\n";

        n *= 10;
        i++;
    }
}
