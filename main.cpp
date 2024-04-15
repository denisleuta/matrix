#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono> 

using namespace std;
using namespace chrono;

// Функция для генерации случайной квадратной матрицы размера n x n
vector<vector<int>> generateRandomMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    // Задаем случайные значения элементам матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }

    return matrix;
}

// Функция для вывода матрицы на экран
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

    // Генерируем случайную матрицу
    vector<vector<int>> matrix = generateRandomMatrix(n);

    // Выводим сгенерированную матрицу
    cout << "Сгенерированная матрица:\n";
    printMatrix(matrix);

   // Первый подсчет суммы по строкам и замер времени
    auto start1 = high_resolution_clock::now(); // Запускаем таймер 1

    int totalSum1 = 0;
    for (int i = 0; i < n; ++i) {
        int rowSum = 0;
        for (int j = 0; j < n; ++j) {
            rowSum += matrix[i][j]; // Сумма элементов в текущей строке
        }
        totalSum1 += rowSum;
        cout << "Сумма элементов в строке " << i + 1 << ": " << rowSum << endl;
    }

    auto stop1 = high_resolution_clock::now(); // Останавливаем таймер 1
    auto duration1 = duration_cast<milliseconds>(stop1 - start1); // Получаем продолжительность 1

    cout << "Общая сумма всех строк: " << totalSum1 << endl;
    cout << "Время выполнения первого подсчета: " << duration1.count() << " миллисекунд" << endl;
    
    // Второй подсчет суммы по столбцам и замер времени
    auto start2 = high_resolution_clock::now(); // Запускаем таймер 2

    int totalSum2 = 0;
    for (int j = 0; j < n; ++j) {
        int colSum = 0;
        for (int i = 0; i < n; ++i) {
            colSum += matrix[i][j]; // Сумма элементов в текущем столбце
        }
        totalSum2 += colSum;
        cout << "Сумма элементов в столбце " << j + 1 << ": " << colSum << endl;
    }

    auto stop2 = high_resolution_clock::now(); // Останавливаем таймер 2
    auto duration2 = duration_cast<milliseconds>(stop2 - start2); // Получаем продолжительность 2
    
    cout << "Общая сумма всех столбцов: " << totalSum2 << endl;
    cout << "Время выполнения второго подсчета: " << duration2.count() << " миллисекунд" << endl;
    
    return 0;
}
