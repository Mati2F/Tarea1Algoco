#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 1e6;
    srand(time(0));

    // Archivo 1: Datos Aleatorios
    ofstream archivo_aleatorio("numeros_aleatorios.txt");
    if (!archivo_aleatorio.is_open()) {
        cerr << "Error al abrir el archivo numeros_aleatorios.txt" << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int numero_aleatorio = rand();
        archivo_aleatorio << numero_aleatorio << endl;
    }
    archivo_aleatorio.close();

    // Archivo 2: Datos Parcialmente Ordenados
    ofstream archivo_parcial("parcialmente_ordenado.txt");
    if (!archivo_parcial.is_open()) {
        cerr << "Error al abrir el archivo parcialmente_ordenado.txt" << endl;
        return 1;
    }

    vector<int> parcialmente_ordenado(n);
    for (int i = 0; i < n; ++i) {
        parcialmente_ordenado[i] = rand();
    }

    sort(parcialmente_ordenado.begin(), parcialmente_ordenado.begin() + n / 2);

    for (int i = 0; i < n; ++i) {
        archivo_parcial << parcialmente_ordenado[i] << endl;
    }
    archivo_parcial.close();

    // Archivo 3: Datos Inversamente Ordenados
    ofstream archivo_inverso("inversamente_ordenado.txt");
    if (!archivo_inverso.is_open()) {
        cerr << "Error al abrir el archivo inversamente_ordenado.txt" << endl;
        return 1;
    }

    vector<int> inversamente_ordenado(n);
    for (int i = 0; i < n; ++i) {
        inversamente_ordenado[i] = rand();
    }

    sort(inversamente_ordenado.begin(), inversamente_ordenado.end(), greater<int>());

    for (int i = 0; i < n; ++i) {
        archivo_inverso << inversamente_ordenado[i] << endl;
    }
    archivo_inverso.close();

    cout << "Archivos generados exitosamente.\n";
    return 0;
}

