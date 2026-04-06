#define _CRT_SECURE_NO_WARNINGS
#include "Stroka.h"
#include <cstring>
#include <iostream>

using namespace std;

// ФУНКЦИИ ИЗ ЛАБОРАТОРНОЙ РАБОТЫ 4
// 1. ОПРЕДЕЛЕНИЕ ДЛИНЫ СТРОКИ (используем способ с указателями)
int dlina1(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

// 2. КОПИРОВАНИЕ СТРОК
char* kopir(char* destination, const char* source) {
    char* original_dest = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';

    return original_dest;
}

// 3. СРАВНЕНИЕ СТРОК
int sravn(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// 4. КОНКАТЕНАЦИЯ СТРОК
char* konkat(char* destination, const char* source) {
    char* original_dest = destination;

    // Находим конец строки назначения
    while (*destination != '\0') {
        destination++;
    }

    // Копируем исходную строку в конец строки назначения
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';

    return original_dest;
}

// Конструктор по умолчанию
Stroka::Stroka()
{
    size = 1;
    str = new char[size];
    str[0] = '\0';
}

// Конструктор из C-строки
Stroka::Stroka(const char* string)
{
    size = dlina1(string) + 1;
    str = new char[size];
    kopir(str, string);
}

// НОВЫЙ: Конструктор с заданным размером
Stroka::Stroka(int razmer)
{
    size = razmer + 1;  // +1 для нуль-терминатора
    str = new char[size];
    str[0] = '\0';      // Инициализируем пустой строкой
}

// Конструктор копирования
Stroka::Stroka(const Stroka& s)
{
    size = s.size;
    str = new char[size];
    kopir(str, s.str);
}

// ДЕСТРУКТОР - освобождает динамическую память
Stroka::~Stroka()
{
    delete[] str;
}

// Оператор присваивания
Stroka& Stroka::operator=(const Stroka& s)
{
    if (this != &s) {
        delete[] str;
        size = s.size;
        str = new char[size];
        kopir(str, s.str);      // используем свой kopir
    }
    return *this;
}

// Оператор сцепления
Stroka& Stroka::operator+(const Stroka& s)
{
    int newSize = size + s.size - 1;  // -1 т.к. нуль-терминатор учтен дважды
    char* newStr = new char[newSize];

    kopir(newStr, str);
    konkat(newStr, s.str);

    // Освобождаем старую память
    delete[] str;

    // Присваиваем новую
    str = newStr;
    size = newSize;

    return *this;
}

// Оператор сравнения
int Stroka::operator==(const Stroka& s) const
{
    if ((sravn(str, s.str)) != 0)
        return 1;
    else
        return 0;
}

// Метод определения длины
int Stroka::dlina()
{
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;
}

// Метод ввода
void Stroka::vvod()
{
    char buffer[1000];
    cin >> buffer;

    // Перевыделяем память под введенную строку
    delete[] str;
    size = dlina1(buffer) + 1;
    str = new char[size];
    kopir(str, buffer);
}

// Метод вывода
void Stroka::vyvod()
{
    cout << str << endl;
}