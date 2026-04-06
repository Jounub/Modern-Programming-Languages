#ifdef TASK1
#include <iostream>
using namespace std;

void main()
{
    int i, k, num;
    
    // Здесь вводим число, которое будем возводить в степень
    std::cout << "Enter a number: ";
    std::cin >> num;
    
    // Вызов функции
    int power(int, int);
    
    // Цикл для вычисления степеней введенного числа
    for (i = 0; i < 10; i++)
    {
        k = power(num, i);
        cout << "i = " << i << ", k = " << k << endl;
    }
}

// Функция для вычисления числа x, возведенного в степень n
int power(int x, int n)
{
    int i, p = 1;    

    for (i = 1; i <= n; i++)
    {
        p *= x;
    }
    return p;
}
#endif