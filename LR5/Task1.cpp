#ifdef TASK1
#include <cstdio>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

bool countEmptyAndNonemptyChars(const char* filename);
int searchSubstringInFile(const char* filename, const char* search_str, const char* result_filename);

int main(void)
{
    int ch;
    char name[50];
    FILE *in;
    printf("Enter file name: ");
    scanf_s("%49s", name, (unsigned)sizeof(name));
    if (fopen_s(&in, name, "r") != 0)
    {
        printf("Error opening file %s\n", name);
        return 1;
    }
    else
    {
        while ((ch = fgetc(in)) != EOF) putchar(ch);
    }

    countEmptyAndNonemptyChars(name);

    char str[100];
    printf("Enter string: ");
    scanf_s("%49s", str, (unsigned)sizeof(str));

	searchSubstringInFile(name, str, "search_results.txt");

    return 0;
}

// ФУНКЦИЯ ДЛЯ ПОДСЧЁТА ПУСТЫХ И НЕПУСТЫХ СИМВОЛОВ
bool countEmptyAndNonemptyChars(const char* filename) {
    int empty_count, non_empty_count;
    FILE* file;
        errno_t err = fopen_s(&file, filename, "r");

    if (err != 0) {
        printf("Error opening file %s\n", filename);
        return false;
    }

    empty_count = 0;
    non_empty_count = 0;
    int ch;

    // Читаем файл посимвольно
    while ((ch = fgetc(file)) != EOF) {
        // Проверяем, является ли символ "пустым"
        // Пустые символы:
        // - пробел
        // - табуляция
        // - перевод строки
        // - возврат каретки
        // - все управляющие символы
        // - звуковой сигнал
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' ||
            ch == '\v' || ch == '\f' || ch == '\a' || iscntrl(ch)) {
            (empty_count)++;
        }
        else {
            (non_empty_count)++;
        }
    }
    cout<< "\nEmpty chars: " << empty_count <<endl;
    cout << "Nonempty chars: " << non_empty_count << endl;

    fclose(file);
    return true;
}

// ФУНКЦИЯ ДЛЯ ПОИСКА ПОДСТРОКИ
/*
 * Структура для хранения информации о найденной подстроке
 */
struct SearchResult {
    int line_number;      // номер строки
    int position;         // позиция в строке (начиная с 0)
    int global_position;  // глобальная позиция в файле
};

int searchSubstringInFile(const char* filename, const char* search_str, const char* result_filename) {
    FILE* input_file;
    FILE* output_file;

    // Открываем исходный файл для чтения
    errno_t err_in = fopen_s(&input_file, filename, "r");
    if (err_in != 0) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    // Открываем файл для записи результатов
    errno_t err_out = fopen_s(&output_file, result_filename, "w");
    if (err_out != 0) {
        printf("Error creating file %s\n", result_filename);
        fclose(input_file);
        return -1;
    }

    int search_len = strlen(search_str);
    if (search_len == 0) {
        fprintf(output_file, "Error: empty search line\n");
        fclose(input_file);
        fclose(output_file);
        return 0;
    }

    // Переменные для поиска
    char* line = NULL;      // буфер для строки
    size_t line_capacity = 0; // размер буфера
    size_t line_length;    // длина прочитанной строки
    int line_number = 0;
    int global_pos = 0;
    int total_matches = 0;
    SearchResult matches[1000]; // массив для хранения результатов (максимум 1000 вхождений)

    // Заголовок файла результатов
    fprintf(output_file, "РЕЗУЛЬТАТЫ ПОИСКА ПОДСТРОКИ\n");
    fprintf(output_file, "Исходный файл: %s\n", filename);
    fprintf(output_file, "Искомая подстрока: \"%s\"\n", search_str);

    // Построчное чтение файла
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        line_number++;
        size_t line_length = strlen(buffer);
        // Удаляем символ новой строки из строки для корректного поиска
        if (line_length > 0 && buffer[line_length - 1] == '\n') {
            buffer[line_length - 1] = '\0';
            line_length--;
        }
        // Поиск всех вхождений подстроки в текущей строке
        char* pos = buffer;
        int line_pos = 0;
        int found_in_line = 0;

        while ((pos = strstr(pos, search_str)) != NULL) {
            int position_in_line = pos - buffer;
            matches[total_matches].line_number = line_number;
            matches[total_matches].position = position_in_line;
            matches[total_matches].global_position = global_pos + position_in_line;
            total_matches++;
            found_in_line++;
            pos += search_len; // Продолжаем поиск после найденной подстроки
        }

        // Если найдены вхождения в строке, выводим информацию
        if (found_in_line > 0) {
            fprintf(output_file, "Строка %d:\n", line_number);
            fprintf(output_file, "  Содержимое: %s\n", buffer);
            fprintf(output_file, "\n");
        }
    }

    // Вывод итоговой статистики
    fprintf(output_file, "ИТОГОВАЯ СТАТИСТИКА\n");
    fprintf(output_file, "Всего строк в файле: %d\n", line_number);
    fprintf(output_file, "Всего найдено вхождений: %d\n", total_matches);

    if (total_matches == 0) {
        fprintf(output_file, "\nПодстрока \"%s\" не найдена в файле.\n", search_str);
    }

    // Освобождение ресурсов
    fclose(input_file);
    fclose(output_file);

    return total_matches;
}
#endif