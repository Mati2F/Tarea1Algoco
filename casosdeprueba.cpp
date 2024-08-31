#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
    // Inicializar el tamaño n
    int n = 1e7;

    // Inicializar la semilla para números aleatorios
    std::srand(std::time(0));

    // Crear un archivo de salida
    std::ofstream archivo_salida("CasosDePrueba.txt");

    // Verificar si el archivo se abrió correctamente
    if (!archivo_salida.is_open()) {
        std::cerr << "Error al abrir el archivo" << std::endl;
        return 1;
    }

    // Generar n números aleatorios y escribirlos en el archivo
    for (int i = 0; i < n; ++i) {
        int numero_aleatorio = std::rand();
        archivo_salida << numero_aleatorio << std::endl;
    }

    // Cerrar el archivo
    archivo_salida.close();

    std::cout << "Se han generado " << n << " números aleatorios y se han guardado en 'numeros_aleatorios.txt'." << std::endl;

    return 0;
}
