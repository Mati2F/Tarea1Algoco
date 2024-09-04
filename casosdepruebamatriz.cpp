#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generarMatriz(int filas, int columnas) {
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 100;
        }
    }
    return matriz;
}

/*
Funcion: Generar matriz
***
Descripcion: genera una matriz aleatoria del tamaño de filas x colummas ingresadas
como parametro, con valores entre el 0 y el 100.
*/

void guardarMatriz(ofstream &archivo, const vector<vector<int>> &matriz) {
    for (const auto &fila : matriz) {
        for (const auto &elem : fila) {
            archivo << elem << " ";
        }
        archivo << "\n";
    }
}

/*
Funcion: Guardar matriz
***
Descripcion: Escribe una matriz en un archivo, ambos pasados como parametros.
*/


int main() {
    int j = 9;
    srand(time(0));

    ofstream archivoCuadrada("matriz_cuadrada.txt");
    
    for (int tamano = 2; tamano <= pow(2,j); tamano*=2) {
        int R1 = tamano, C1 = tamano;
        int R2 = tamano, C2 = tamano;
        
        archivoCuadrada << R1 << " " << C1 << " " << R2 << " " << C2 << "\n";
        
        auto matriz1 = generarMatriz(R1, C1);
        auto matriz2 = generarMatriz(R2, C2);
        
        guardarMatriz(archivoCuadrada, matriz1);
        guardarMatriz(archivoCuadrada, matriz2);
    }
    archivoCuadrada.close();

    cout << "Archivos generados exitosamente.\n";
    return 0;
}
