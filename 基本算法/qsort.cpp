//
// Created by yuanoung on 3/26/18.
//
#include <iostream>

using namespace std;

void swap(int arr[], int i, int j) {
    int _sw = arr[j];
    arr[j] = arr[i];
    arr[i] = _sw;
}

int partition(int arr[], int q, int p) {
    int i = q, j, privot = arr[q];
    for (j = q + 1; j <= p; j++) {
        if (arr[j] <= privot) {
            swap(arr, ++i, j);
        }
    }
    swap(arr, q, i);
    return i;
}

void qsort(int arr[], int q, int p) {
    if (q < p) {
        int privot = partition(arr, q, p);
        qsort(arr, q, privot - 1);
        qsort(arr, privot + 1, p);
    }
}

int main() {
    int arr[21] = {3, 1, 5, 2, 4, 9, 10, 0, 12, 9, 2, 1, 29, 11, 21, 11, 12, 12, 3, 5, 8};
    qsort(arr, 0, 20);
    for (int i = 0; i < 21; i++) {
        cout << arr[i] << endl;
    }
}
