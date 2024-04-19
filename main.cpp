#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono> 

using namespace std;
using namespace chrono;

vector<vector<int>> generateRandomMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    int n;
    cout << "Введите размер квадратной матрицы (n x n): ";
    cin >> n;

    vector<vector<int>> matrix = generateRandomMatrix(n);

    // Измерение времени для суммирования по строкам
    auto start1 = high_resolution_clock::now();

    int totalSum1 = 0;
    for (int i = 0; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j];
        }
        totalSum1 += rowSum;
    }

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);

    // Измерение времени для суммирования по столбцам
    auto start2 = high_resolution_clock::now();

    int totalSum2 = 0;
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += matrix[i][j];
        }
        totalSum2 += colSum;
    }

    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Общая сумма всех строк: " << totalSum1 << endl;
    cout << "Время выполнения первого подсчета: " << duration1.count() << " миллисекунд" << endl;

    cout << "Общая сумма всех столбцов: " << totalSum2 << endl;
    cout << "Время выполнения второго подсчета: " << duration2.count() << " миллисекунд" << endl;

    return 0;
}
