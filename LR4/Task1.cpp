#include <iostream>
using namespace std;

int dlina1(const char* str);
int dlina2(const char* str);
int dlina3(const char* str);
char* kopir(char* destination, const char* source);
int sravn(const char* str1, const char* str2);
char* konkat(char* destination, const char* source);
void freeStringArray(char** strings, int count);
void printArray(char** strings, int count);

int main()
{
	char str1[] = "qwerty", str2[] = "1234567890";

	//Библиотечные функции strlen(), strcat(), strcpy(), strcmp()
	cout<<"str1 length = "<<strlen(str1)<<", str2 length = "<<strlen(str2)<<endl;

	char str3[50];
	strcpy_s(str3, str1);
	cout << "Copy: str3 = " << str3 << endl;

	cout << "Comparison str1 & str3 = " << strcmp(str1, str3) << endl;
	cout << "Comparison str2 & str3 = " << strcmp(str2, str3) << endl;

	strcat_s(str3, str2);
	cout << "Concatenation str3 & str2 = " << str3 << endl;

    //Свои функции
    cout << "\nstr1 length = " << dlina1(str1) << ", str2 length = " << dlina1(str2) << endl;
    cout << "str1 length = " << dlina2(str1) << ", str2 length = " << dlina2(str2) << endl;
    cout << "str1 length = " << dlina3(str1) << ", str2 length = " << dlina3(str2) << endl;

    kopir(str3, str1);
    cout << "Copy: str3 = " << str3 << endl;

    cout << "Comparison str1 & str3 = " << sravn(str1, str3) << endl;
    cout << "Comparison str2 & str3 = " << sravn(str2, str3) << endl;

    konkat(str3, str2);
    cout << "Concatenation str3 & str2 = " << str3 << endl;

    char *str1a, *str2a, *str3a;

    //С выделением динамической памяти
    str1a = (char*)malloc(100);
    str2a = (char*)malloc(100);
    str3a = (char*)malloc(100);

    kopir(str1a, str1);
    kopir(str2a, str2);

    cout << "\nstr1a = " << str1a << ", str2a = " << str2a << endl;

    cout << "\nstr1a length = " << dlina1(str1a) << ", str2a length = " << dlina1(str2a) << endl;
    cout << "str1a length = " << dlina2(str1a) << ", str2a length = " << dlina2(str2a) << endl;
    cout << "str1a length = " << dlina3(str1a) << ", str2a length = " << dlina3(str2a) << endl;

    kopir(str3a, str1a);
    cout << "Copy: str3a = " << str3 << endl;

    cout << "Comparison str1a & str3a = " << sravn(str1a, str3a) << endl;
    cout << "Comparison str2a & str3a = " << sravn(str2a, str3a) << endl;

    konkat(str3a, str2a);
    cout << "Concatenation str3a & str2a = " << str3a << endl;

    free(str1a);
    free(str2a);
    free(str3a);

	// С использованием calloc
    // И malloc и calloc выделяют память в куче (heap)
    // malloc выделяет непрерывный блок памяти указанного размера. Выделенная память должна быть освобождена с помощью free() в обоих случаях.
    // calloc выделяет непрерывный блок памяти для массива из count элементов по size байт каждый 
    char* str1b, * str2b, * str3b;
    int size = 100;
    str1b = (char*)calloc(size, sizeof(char));
    str2b = (char*)calloc(size, sizeof(char));
    str3b = (char*)calloc(size, sizeof(char));

    kopir(str1b, str1);
    kopir(str2b, str2);

    cout << "\nstr1b = " << str1b << ", str2b = " << str2b << endl;

    cout << "\nstr1b length = " << dlina1(str1b) << ", str2b length = " << dlina1(str2b) << endl;
    cout << "str1b length = " << dlina2(str1b) << ", str2b length = " << dlina2(str2b) << endl;
    cout << "str1b length = " << dlina3(str1b) << ", str2b length = " << dlina3(str2b) << endl;

    kopir(str3b, str1b);
    cout << "Copy: str3b = " << str3b << endl;

    cout << "Comparison str1b & str3b = " << sravn(str1b, str3b) << endl;
    cout << "Comparison str2b & str3b = " << sravn(str2b, str3b) << endl;

    konkat(str3b, str2b);
    cout << "Concatenation str3b & str2b = " << str3b << endl;

    free(str1b);
    free(str2b);
    free(str3b);

	// МАССИВ СТРОК
    cout << "\nStrings array\n" << endl;

    // Создаём массив указателей на строки
    int num_strings = 3;
    char** strings;

    strings = (char**)calloc(num_strings, sizeof(char*));

    // Выделяем память для каждой строки и заполняем их
    strings[0] = (char*)calloc(50, sizeof(char));
    kopir(strings[0], "qwerty");

    strings[1] = (char*)calloc(50, sizeof(char));
    kopir(strings[1], "asdfgh");

    strings[2] = (char*)calloc(50, sizeof(char));
    kopir(strings[2], "zxcvbnnm");

	printArray(strings, num_strings);

    for (int i = 0; i < num_strings; i++) {
        cout << "Length of " << i + 1 << " element of array: " << dlina1(strings[i]) << endl;
    }

    cout << "\nCopy 1 element to 2 element" << endl;
    kopir(strings[1], strings[0]);

    printArray(strings, num_strings);

    for (int i = 0; i < num_strings - 1; i++) {
        cout << "Comparison of " << i+1 << " and " << i+2 << " elements of array: " << sravn(strings[i], strings[i + 1]) << endl;
	}

    cout << "\nConcatenation of array elements" << endl;
    for (int i = 0; i < num_strings - 1; i++) {
        konkat(strings[i+1], strings[i]);
    }
    printArray(strings, num_strings);

	freeStringArray(strings, num_strings);

	return 0;
}

// 1. ОПРЕДЕЛЕНИЕ ДЛИНЫ СТРОКИ (3 способа)
// Способ 1: Использование счётчика с циклом while
int dlina1(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Способ 2: Использование цикла for с проверкой условия
int dlina2(const char* str) {
    int length;
    for (length = 0; str[length] != '\0'; length++);
    return length;
}

// Способ 3: Использование указателей
int dlina3(const char* str) {
    const char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    return ptr - str;  // разность указателей даёт длину
}

// 2. КОПИРОВАНИЕ СТРОК
char* kopir(char* destination, const char* source) {
    char* original_dest = destination;  // запоминаем начало

    // Копируем символы, пока не встретим '\0'
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';  // добавляем завершающий нуль-символ

    return original_dest;  // возвращаем указатель на начало строки назначения
}

// 3. СРАВНЕНИЕ СТРОК
// Возвращает:
// 0 - если строки равны
// <0 - если первая строка меньше второй
// >0 - если первая строка больше второй
int sravn(const char* str1, const char* str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;  // разница кодов символов
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
    *destination = '\0';  // добавляем завершающий нуль-символ

    return original_dest;
}

// Функция для освобождения памяти массива строк
void freeStringArray(char** strings, int count) {
    for (int i = 0; i < count; i++) {
        if (strings[i] != NULL) {
            free(strings[i]);
        }
    }
    free(strings);
}

void printArray(char** strings, int count) {

    for (int i = 0; i < count; i++) {
        if (strings[i] != NULL) {
            cout << "String " << i + 1 << ": " << strings[i] << endl;
        }
    }
}
