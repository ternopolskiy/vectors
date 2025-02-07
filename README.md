# Отчет по лабораторной работе: Работа со структурами в C++/Знакомство с абстрактными типами данных

## 1. Постановка цели
Целью данной работы является изучение и практическое применение структур в языке программирования C++. В рамках работы необходимо:
- Создать структуры для представления объектов (смартфон и ноутбук).
- Реализовать функции для ввода и вывода данных о структурах.
- Организовать динамическое создание экземпляров структур и их хранение в векторе.
- Разработать псевдоменю для взаимодействия с пользователем.

## 2. Оглавление
1. Постановка цели
2. Оглавление
3. Отражение задач
4. Вариант задания
5. Инструкции по использованию
6. Результат работы программы
7. Вывод

## 3. Отражение задач
В рамках работы были выполнены следующие задачи:
1. Реализованы две структуры: `Smartphone` и `Laptop`.
2. Созданы функции для ввода данных о структурах:
   - `inputSmartphone(Smartphone* phone)`
   - `inputLaptop(Laptop* laptop)`
3. Созданы функции для вывода данных о структурах:
   - `printSmartphone(const Smartphone& phone)`
   - `printLaptop(const Laptop& laptop)`
4. Реализована функция `createAndStore`, которая динамически создает экземпляры структур и сохраняет их в вектор.
5. Разработано псевдоменю в функции `main`, позволяющее пользователю добавлять и просматривать данные.

## 4. Вариант задания
В работе использованы следующие варианты структур:
1. **Объект: Смартфон**
   - Характеристики:
     - Фирма-производитель (`brand`)
     - Объем встроенной памяти (`storage`, в ГБ)
     - Цена (`price`)

2. **Объект: Ноутбук**
   - Характеристики:
     - Фирма-производитель (`brand`)
     - Модель процессора (`cpuModel`)
     - Наличие игровой видеокарты (`hasGamingGPU`)

## 5. Инструкции по использованию
При вводе данных, содержащих пробелы (например, модели процессора или бренда), используйте символ подчеркивания (`_`) вместо пробелов. Это позволит корректно обрабатывать ввод.

Пример:
- Бренд: `Acer_Nitro_5`
- Модель процессора: `AMD_Ryzen_5_4600H`

## 6. Результат работы программы
Ниже приведены скриншоты работы программы:

### Добавление смартфона
![Добавление смартфона](https://imgur.com/a/ffoGz8c)

### Добавление ноутбука
![Добавление ноутбука](https://imgur.com/a/Bc2st7K)

### Просмотр списка смартфонов
![Просмотр смартфонов](https://imgur.com/a/myO7KLd)

### Просмотр списка ноутбуков
![Просмотр ноутбуков](https://imgur.com/a/ERw4wmQ)

### Выход из программы
![Выход из программы](https://imgur.com/a/lx4avT5)

## 7. Вывод
В ходе выполнения работы были изучены и применены следующие концепции:
- Работа со структурами в C++.
- Динамическое создание объектов с использованием оператора `new`.
- Хранение объектов в векторе (`std::vector`).
- Организация взаимодействия с пользователем через консольное меню.

Были реализованы функции для ввода и вывода данных, а также обеспечена корректная работа программы без ошибок. В процессе работы я научился:
- Создавать и использовать шаблонные функции.
- Управлять динамической памятью.
- Организовывать структурированный код с использованием функций и классов.

Данная работа позволила углубить понимание работы с памятью и структурами данных в C++.(Абстрактными типами данных)
