#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 4;

int graph[N][N] = {
    {0, 4, 1, 3},
    {4, 0, 2, 5},
    {1, 2, 0, 1},
    {3, 5, 1, 0}
};

int tsp(int start, vector<int>& path) {
    vector<int> vertices;
    for (int i = 0; i < N; i++) {
        if (i != start) vertices.push_back(i);
    }

    int minPath = INT_MAX;

    do {
        int currentCost = 0;
        int k = start;
        for (int i = 0; i < vertices.size(); i++) {
            currentCost += graph[k][vertices[i]];
            k = vertices[i];
        }
        currentCost += graph[k][start];

        if (currentCost < minPath) {
            minPath = currentCost;
            path = {start};
            path.insert(path.end(), vertices.begin(), vertices.end());
            path.push_back(start);
        }

    } while (next_permutation(vertices.begin(), vertices.end()));

    return minPath;
}

int main() {
    int start = 0;

    vector<int> bestPath;
    int minCost = tsp(start, bestPath);

    cout << "Cost List :\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }

    cout << "\nJalur Terpendek : ";
    for (int i = 0; i < bestPath.size(); i++) {
        cout << bestPath[i] + 1; // Tambah 1 agar dari 1..4
        if (i != bestPath.size() - 1) cout << "--->";
    }
    cout << "\nMinimum Cost : " << minCost << endl;

    return 0;
}

