#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

// Función para generar una matriz aleatoria
vector<vector<int>> generarMatriz(int filas, int columnas) {
    vector<vector<int>> matriz(filas, vector<int>(columnas));
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 100; // Números aleatorios entre 0 y 99
        }
    }
    return matriz;
}

// Función para guardar una matriz en un archivo
void guardarMatriz(ofstream &archivo, const vector<vector<int>> &matriz) {
    for (const auto &fila : matriz) {
        for (const auto &elem : fila) {
            archivo << elem << " ";
        }
        archivo << "\n";
    }
}

int main() {
    int j = 9;
    srand(time(0)); // Inicializar la semilla para generación de números aleatorios

    // Archivo para matrices cuadradas
    ofstream archivoCuadrada("matriz_cuadrada.txt");
    
    // Generar y guardar matrices cuadradas
    for (int tamano = 2; tamano <= pow(2,j); tamano*=2) { // Ejemplo con tamaños de 2x2 a 5x5
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
