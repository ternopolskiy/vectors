#include <iostream>
#include <vector>
#include <string>
#include <limits>


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
    std::cout << "Enter brand: ";
    std::cin >> phone->brand;
    std::cout << "Enter storage (GB): ";
    std::cin >> phone->storage;
    std::cout << "Enter price: ";
    std::cin >> phone->price;
}

// Функция для вывода данных о смартфоне
void printSmartphone(const Smartphone& phone) {
    std::cout << "Brand: " << phone.brand << ", Storage: " << phone.storage << "GB, Price: $" << phone.price << endl;
}

// Функция для ввода данных о ноутбуке
void inputLaptop(Laptop* laptop) {
    std::cout << "Enter brand: ";
    std::cin >> laptop->brand;
    std::cout << "Enter CPU model: ";
    std::cin >> laptop->cpuModel;

    // Ввод для поля hasGamingGPU
    while (true) {
        std::cout << "Has gaming GPU? (1 for Yes, 0 for No): ";
        if (std::cin >> laptop->hasGamingGPU) {
            break; // Ввод правильный, выходим из цикла
        }
        else {
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            std::cout << "Invalid input. Please enter 1 for Yes or 0 for No.\n";
        }
    }
}

// Функция для вывода данных о ноутбуке
void printLaptop(const Laptop& laptop) {
    std::cout << "Brand: " << laptop.brand << ", CPU Model: " << laptop.cpuModel << ", Gaming GPU: " << (laptop.hasGamingGPU ? "Yes" : "No") << endl;
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
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Smartphone\n";
        std::cout << "2. Add Laptop\n";
        std::cout << "3. View Smartphones\n";
        std::cout << "4. View Laptops\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        // Проверка на корректный ввод числа
        if (!(cin >> choice)) {
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера

        switch (choice) {
        case 1:
            createAndStore(smartphones, inputSmartphone); // Добавление смартфона
            break;
        case 2:
            createAndStore(laptops, inputLaptop); // Добавление ноутбука
            break;
        case 3:
            if (smartphones.empty()) {
                std::cout << "No smartphones added yet.\n";
            }
            else {
                std::cout << "Smartphones:\n";
                for (const auto& phone : smartphones) {
                    printSmartphone(*phone); // Вывод всех смартфонов
                }
            }
            break;
        case 4:
            if (laptops.empty()) {
                std::cout << "No laptops added yet.\n";
            }
            else {
                std::cout << "Laptops:\n";
                for (const auto& laptop : laptops) {
                    printLaptop(*laptop); // Вывод всех ноутбуков
                }
            }
            break;
        case 5:
            clearVector(smartphones); // Очистка памяти для смартфонов
            clearVector(laptops);     // Очистка памяти для ноутбуков
            std::cout << "Exiting the program.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
