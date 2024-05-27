#include <iostream>
#include <fstream>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

// Функция для вывода двумерного массива на экран
void printArray(double arr[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Функция для записи двумерного массива в бинарный файл
void writeArrayToFile(double arr[][COLS], int rows, int cols, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return;
    }

    for (int i = 0; i < rows; ++i) {
        outFile.write(reinterpret_cast<const char*>(arr[i]), cols * sizeof(double));
    }

    outFile.close();
}

// Функция для чтения данных из бинарного файла и изменения значений элементов
void modifyFile(const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return;
    }

    double arr[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        inFile.read(reinterpret_cast<char*>(arr[i]), COLS * sizeof(double));
    }
    inFile.close();

    // Увеличиваем значения элементов в каждой строке в 1,5 раза
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] *= 1.5;
        }
    }

    // Перезаписываем файл с измененными данными
    writeArrayToFile(arr, ROWS, COLS, filename);
}

int main() {
    setlocale(0, "ru");
    double arr[ROWS][COLS];

    // Ввод значений двумерного массива
    cout << "Введите значения двумерного массива " << ROWS << "x" << COLS << ":" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // Выводим массив до изменений
    cout << "Массив до изменения данных в файле:" << endl;
    printArray(arr, ROWS, COLS);

    // Записываем массив в бинарный файл
    writeArrayToFile(arr, ROWS, COLS, "data.bin");

    // Модифицируем бинарный файл
    modifyFile("data.bin");

    // Выводим массив после изменений
    cout << "Массив после изменения данных в файле:" << endl;
    printArray(arr, ROWS, COLS);

    return 0;
}

