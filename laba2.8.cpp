#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Структура для представления информации о джазовых музыкантах
struct JazzMusician {
    string artist;
    string albumTitle;
    int circulation;
    int yearOfRelease;
    double albumPrice;
};

int main() {
    setlocale(0, "ru");
    // Создаем вектор для хранения данных о джазовых музыкантах
    vector<JazzMusician> musicians = {
        {"Louis Armstrong", "What a Wonderful World", 1500, 1968, 60.0},
        {"Miles Davis", "Kind of Blue", 2000, 1959, 70.0},
        {"John Coltrane", "A Love Supreme", 800, 1965, 55.0},
        // Добавьте других музыкантов...
    };

    // Открываем бинарный файл для записи
    ofstream outFile("jazz_musicians.dat", ios::binary);
    if (!outFile) {
        cerr << "Ошибка открытия файла для записи." << endl;
        return 1;
    }

    // Записываем данные о музыкантах в файл
    for (const auto& musician : musicians) {
        outFile.write(reinterpret_cast<const char*>(&musician), sizeof(JazzMusician));
    }

    outFile.close();

    // Открываем бинарный файл для чтения
    ifstream inFile("jazz_musicians.dat", ios::binary);
    if (!inFile) {
        cerr << "Ошибка открытия файла для чтения." << endl;
        return 1;
    }


    int currentYear = 2024;

    // Читаем данные из файла и выводим информацию о музыкантах, выпустивших альбомы, соответствующие критериям
    JazzMusician musician;
    cout << "Информация о музыканте, выпустившем альбом с тиражом более 1000 экземпляров и ценой не менее 50 грн в текущем году:" << endl;
    while (inFile.read(reinterpret_cast<char*>(&musician), sizeof(JazzMusician))) {
        if (musician.circulation > 1000 && musician.albumPrice >= 50.0 && musician.yearOfRelease == currentYear) {
            cout << "Исполнитель: " << musician.artist << endl;
            cout << "Название альбома: " << musician.albumTitle << endl;
            cout << "Тираж: " << musician.circulation << endl;
            cout << "Год выпуска: " << musician.yearOfRelease << endl;
            cout << "Цена альбома: " << musician.albumPrice << " грн" << endl;
            cout << "--------------------------" << endl;
        }
    }

    inFile.close();

    return 0;
}
