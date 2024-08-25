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

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){

    t0 = clock();
    int n = 5;
    int arr[n] = {3,5,2,4,1};
    selectionSort(arr, n);
    
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Tiempo de Ejecucion: " << time << endl;
}
