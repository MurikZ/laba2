#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

// Структура для представления данных об автомобиле
struct Car {
    string brand;
    string color;
    string serialNumber;
    string registrationNumber;
    int yearOfProduction;
    int yearOfInspection;
    double price;
};

int main() {
    setlocale(0, "ru");
    ifstream inputFile("cars.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }


    int currentYear = 2024;

    // Создание вектора автомобилей
    vector<Car> cars;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        Car car;
        getline(ss, car.brand, ';');
        getline(ss, car.color, ';');
        getline(ss, car.serialNumber, ';');
        getline(ss, car.registrationNumber, ';');
        ss >> car.yearOfProduction;
        ss.ignore(); // Пропускаем разделитель ';'
        ss >> car.yearOfInspection;
        ss.ignore(); // Пропускаем разделитель ';'
        ss >> car.price;
        cars.push_back(car);
    }

    // Фильтрация автомобилей, которым больше 2 лет
    vector<Car> carsOlderThan2Years;
    for (const auto& car : cars) {
        if (currentYear - car.yearOfProduction > 2) {
            carsOlderThan2Years.push_back(car);
        }
    }

    // Закрытие файла
    inputFile.close();


    ofstream outputFile("cars_old.txt");
    if (!outputFile) {
        cerr << "Ошибка открытия файла для записи результатов." << endl;
        return 1;
    }

    for (const auto& car : carsOlderThan2Years) {
        outputFile << car.brand << "; " << car.color << "; " << car.serialNumber << "; " << car.registrationNumber
            << "; " << car.yearOfProduction << "; " << car.yearOfInspection << "; " << car.price << endl;
    }

    // Закрытие файла
    outputFile.close();



    return 0;
}
