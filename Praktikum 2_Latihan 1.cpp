#include <iostream>
using namespace std;

#define N 4
void rotateMatrix(int matrix[N][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = matrix[i][j];

            matrix[i][j] = matrix[N - 1 - j][i];

            matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];

            matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];

            matrix[j][N - 1 - i] = temp;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[N][N] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Matrix Awal:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << "\nMatrix diputar 90 derajat searah jarum jam:" << endl;
    printMatrix(matrix);

    return 0;
}