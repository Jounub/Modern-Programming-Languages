#ifndef STROKA_H
#define STROKA_H

#include <iostream>
using namespace std;

class Stroka
{
    char* str;  // Ууказатель на динамическую память
    int size;   // Храним размер выделенной памяти

public:
    // Конструкторы
    Stroka();                           // Конструктор по умолчанию
    Stroka(const char* string);         // Из C-строки
    Stroka(int razmer);                 // с заданным размером
    Stroka(const Stroka&);              // Конструктор копирования

    // Деструктор
    // При использовании динамической памяти деструктор обязательно понадобится для освобождения выделенной памяти и предотвращения утечек памяти.
    ~Stroka();

    // Перегруженные операции
    Stroka& operator=(const Stroka&);
    Stroka& operator+(const Stroka&);
    int operator==(const Stroka&) const;

    // Методы
    int dlina();
    void vvod();
    void vyvod();
};

#endif

