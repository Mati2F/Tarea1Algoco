#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int n = 1e7;
    srand(time(0));
    ofstream archivo_salida("CasosDePrueba.txt");

    if (!archivo_salida.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int numero_aleatorio = rand();
        archivo_salida << numero_aleatorio << endl;
    }
    archivo_salida.close();

    return 0;
}
