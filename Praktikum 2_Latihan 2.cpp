#include <iostream>
using namespace std;

#define N 4

void rotateMatrix(int* matrix) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = *(matrix + i * N + j);

            *(matrix + i * N + j) = *(matrix + (N - 1 - j) * N + i);

            *(matrix + (N - 1 - j) * N + i) = *(matrix + (N - 1 - i) * N + (N - 1 - j));

            *(matrix + (N - 1 - i) * N + (N - 1 - j)) = *(matrix + j * N + (N - 1 - i));

            *(matrix + j * N + (N - 1 - i)) = temp;
        }
    }
}

void printMatrix(int* matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(matrix + i * N + j) << " ";
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

    cout << "Original Matrix:" << endl;
    printMatrix((int*)matrix);

    rotateMatrix((int*)matrix);

    cout << "\nRotated Matrix (90 degrees clockwise):" << endl;
    printMatrix((int*)matrix);

    return 0;
}