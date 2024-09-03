#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

unsigned t0,t1;

void printMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (int elemento : fila) {
            cout << elemento << "\t";
        }
        cout << endl;
    }
}

/*
Funcion: Print Matriz
***
Descripcion: Imprime de forma provisoria la matriz en la que se encuentran los datos
solo para revisar si se está efectuando.
*/

vector<vector<int>> mulMat(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, int R1, int C2, int R2) {
    vector<vector<int>> rslt(R1, vector<int>(C2, 0));

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < R2; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return rslt;
}

/*
Funcion: Multiplicar matriz
***
Descripcion: Realiza la multiplicacion tradicional de matrices.
***
Mejor Caso: O(n^3)
Peor Caso: O(n^3)
*/

int main() {
	int i = 1;
    ifstream inputFile("matriz_cuadrada.txt");

    if (!inputFile) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    int R1, C1, R2, C2;
    while (inputFile >> R1 >> C1 >> R2 >> C2) {
        vector<vector<int>> mat1(R1, vector<int>(C1));
        vector<vector<int>> mat2(R2, vector<int>(C2));

        for (int i = 0; i < R1; ++i) {
            for (int j = 0; j < C1; ++j) {
                inputFile >> mat1[i][j];
            }
        }

        for (int i = 0; i < R2; ++i) {
            for (int j = 0; j < C2; ++j) {
                inputFile >> mat2[i][j];
            }
        }

        //cout << "\nMatrix 1:\n";
        //printMatriz(mat1);

        //cout << "\nMatrix 2:\n";
        //printMatriz(mat2);

        t0 = clock();
        vector<vector<int>> result = mulMat(mat1, mat2, R1, C2, R2);
		t1 = clock();

		double time = (double(t1-t0)/CLOCKS_PER_SEC);

        //cout << "\nMultiplication of given two matrices is:\n";
        //printMatriz(result);
		cout << "\n" << "con n = "<< i << ", el tiempo de ejecucion es: " << time << "\n";
		i++;
    }

    inputFile.close();
    return 0;
}
