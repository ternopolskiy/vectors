#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Структура для смартфона
struct Smartphone {
    string brand;       // Фирма-производитель
    int storage;        // Объем встроенной памяти (в ГБ)
    double price;       // Цена
};

// Структура для ноутбука
struct Laptop {
    string brand;       // Фирма-производитель
    string cpuModel;    // Модель процессора
    bool hasGamingGPU;  // Наличие игровой видеокарты
};

// Функция для ввода данных о смартфоне
void inputSmartphone(Smartphone* phone) {
    cout << "Enter brand: ";
    cin >> phone->brand;
    cout << "Enter storage (GB): ";
    cin >> phone->storage;
    cout << "Enter price: ";
    cin >> phone->price;
}

// Функция для вывода данных о смартфоне
void printSmartphone(const Smartphone& phone) {
    cout << "Brand: " << phone.brand << ", Storage: " << phone.storage << "GB, Price: $" << phone.price << endl;
}

// Функция для ввода данных о ноутбуке
void inputLaptop(Laptop* laptop) {
    cout << "Enter brand: ";
    cin >> laptop->brand;
    cout << "Enter CPU model: ";
    cin >> laptop->cpuModel;

    // Ввод для поля hasGamingGPU
    while (true) {
        cout << "Has gaming GPU? (1 for Yes, 0 for No): ";
        if (cin >> laptop->hasGamingGPU) {
            break; // Ввод правильный, выходим из цикла
        }
        else {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Invalid input. Please enter 1 for Yes or 0 for No.\n";
        }
    }
}

// Функция для вывода данных о ноутбуке
void printLaptop(const Laptop& laptop) {
    cout << "Brand: " << laptop.brand << ", CPU Model: " << laptop.cpuModel << ", Gaming GPU: " << (laptop.hasGamingGPU ? "Yes" : "No") << endl;
}

// Функция для создания динамических экземпляров структур и сохранения их в вектор
template<typename T>
void createAndStore(vector<T*>& vec, void (*inputFunc)(T*)) {
    T* item = new T();  // Динамическое создание экземпляра структуры
    inputFunc(item);    // Ввод данных
    vec.push_back(item); // Сохранение в вектор
}

// Функция для очистки вектора и освобождения памяти
template<typename T>
void clearVector(vector<T*>& vec) {
    for (auto& item : vec) {
        delete item; // Освобождение памяти
    }
    vec.clear(); // Очистка вектора
}

int main() {
    vector<Smartphone*> smartphones; // Вектор для хранения смартфонов
    vector<Laptop*> laptops;         // Вектор для хранения ноутбуков
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Smartphone\n";
        cout << "2. Add Laptop\n";
        cout << "3. View Smartphones\n";
        cout << "4. View Laptops\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        // Проверка на корректный ввод числа
        if (!(cin >> choice)) {
            cin.clear(); // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера

        switch (choice) {
        case 1:
            createAndStore(smartphones, inputSmartphone); // Добавление смартфона
            break;
        case 2:
            createAndStore(laptops, inputLaptop); // Добавление ноутбука
            break;
        case 3:
            if (smartphones.empty()) {
                cout << "No smartphones added yet.\n";
            }
            else {
                cout << "Smartphones:\n";
                for (const auto& phone : smartphones) {
                    printSmartphone(*phone); // Вывод всех смартфонов
                }
            }
            break;
        case 4:
            if (laptops.empty()) {
                cout << "No laptops added yet.\n";
            }
            else {
                cout << "Laptops:\n";
                for (const auto& laptop : laptops) {
                    printLaptop(*laptop); // Вывод всех ноутбуков
                }
            }
            break;
        case 5:
            clearVector(smartphones); // Очистка памяти для смартфонов
            clearVector(laptops);     // Очистка памяти для ноутбуков
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}