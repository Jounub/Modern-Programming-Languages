#ifdef TASK4

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <windows.h>

// ФУНКЦИИ ДЛЯ РАБОТЫ СО СТРОКАМИ
/**
 * Удаляет символы переноса (дефисы) в конце строки
 * @param str - строка для обработки
 * @return true если были удалены символы переноса
 */
bool removeHyphens(char* str) {
    int len = strlen(str);
    bool removed = false;

    // Удаляем дефисы и пробелы в конце строки
    while (len > 0 && (str[len - 1] == '-' || str[len - 1] == ' ')) {
        str[len - 1] = '\0';
        len--;
        removed = true;
    }

    return removed;
}

/**
 * Извлекает номер страницы из строки формата "- 34 -" или "-34-"
 * @param str - строка с номером страницы
 * @return извлечённый номер страницы или -1 если номер не найден
 */
int extractPageNumber(const char* str) {
    // Ищем шаблон: начинается с '-', затем пробелы, цифры, пробелы, '-'
    const char* start = strchr(str, '-');
    if (start == NULL) return -1;

    // Пропускаем дефис и пробелы после него
    start++;
    while (*start == ' ') start++;

    // Проверяем, что дальше идут цифры
    if (!isdigit(*start)) return -1;

    // Извлекаем число
    int number = 0;
    while (isdigit(*start)) {
        number = number * 10 + (*start - '0');
        start++;
    }

    // Пропускаем пробелы перед закрывающим дефисом
    while (*start == ' ') start++;

    // Проверяем наличие закрывающего дефиса
    if (*start == '-') {
        return number;
    }

    return -1;
}

/**
 * Проверяет, является ли строка строкой с номером страницы
 * @param str - строка для проверки
 * @return true если строка содержит номер страницы в формате "- число -"
 */
bool isPageNumberLine(const char* str) {
    return extractPageNumber(str) != -1;
}

/**
 * Удаляет номер страницы из строки (оставляет только содержимое без номера)
 * @param str - исходная строка
 * @param result - буфер для результата
 */
void removePageNumber(const char* str, char* result) {
    const char* start = strchr(str, '-');
    if (start == NULL) {
        strcpy(result, str);
        return;
    }

    // Находим конец номера страницы
    const char* end = start + 1;
    while (*end != '\0') {
        if (*end == '-') {
            end++;
            break;
        }
        end++;
    }

    // Пропускаем пробелы после номера страницы
    while (*end == ' ') end++;

    // Копируем оставшуюся часть строки
    strcpy(result, end);
}

/**
 * Добавляет номер страницы в конец строки
 * @param str - строка, к которой добавляется номер
 * @param page_num - номер страницы
 * @param result - буфер для результата
 */
void appendPageNumber(const char* str, int page_num, char* result) {
    // Удаляем возможные символы переноса в конце строки
    char temp[1024];
    strcpy(temp, str);
    removeHyphens(temp);

    // Формируем результат: строка + пробел + номер страницы
    sprintf(result, "%s %d", temp, page_num);
}

// ОСНОВНАЯ ФУНКЦИЯ ОБРАБОТКИ
/**
 * Обрабатывает файл: переносит номера страниц из первой строки в последнюю
 * @param input_filename - имя входного файла
 * @param output_filename - имя выходного файла
 * @return true если обработка успешна
 */
bool processFile(const char* input_filename, const char* output_filename) {
    FILE* input_file;
    FILE* output_file;

    // Открываем входной файл для чтения
    errno_t err_in = fopen_s(&input_file, input_filename, "r");
    if (err_in != 0) {
        printf("Error: can't open the file%s\n", input_filename);
        return false;
    }

    // Открываем выходной файл для записи
    errno_t err_out = fopen_s(&output_file, output_filename, "w");
    if (err_out != 0) {
        printf("Error: can't create output file %s\n", output_filename);
        fclose(input_file);
        return false;
    }

    char line[1024];          // буфер для текущей строки
    char next_line[1024];     // буфер для следующей строки
    char page_lines[100][1024]; // буфер для строк текущей страницы
    int line_count = 0;       // количество строк на текущей странице
    int page_number = -1;     // номер текущей страницы
    int total_pages = 0;      // общее количество обработанных страниц
    int ch;

    // Читаем файл посимвольно для обнаружения символов '\f'
    while (fgets(line, sizeof(line), input_file) != NULL) {
        // Проверяем, является ли строка строкой с номером страницы
        if (isPageNumberLine(line)) {
            // Извлекаем номер страницы
            page_number = extractPageNumber(line);

            // Удаляем номер страницы из строки (если нужно сохранить содержимое)
            char content[1024];
            removePageNumber(line, content);

            // Сохраняем содержимое как первую строку страницы
            strcpy(page_lines[line_count], content);
            line_count++;
        }
        // Проверяем, не является ли символ началом новой страницы (встроенный '\f')
        else if (strchr(line, '\f') != NULL) {
            // Разделяем строку по символу '\f'
            char* parts[2];
            char* token = strtok(line, "\f");
            int part_index = 0;

            while (token != NULL && part_index < 2) {
                parts[part_index] = token;
                part_index++;
                token = strtok(NULL, "\f");
            }

            // Если есть содержимое до '\f', добавляем его как строку текущей страницы
            if (part_index > 0 && strlen(parts[0]) > 0) {
                // Удаляем возможные символы переноса
                removeHyphens(parts[0]);
                strcpy(page_lines[line_count], parts[0]);
                line_count++;
            }

            // Если есть содержимое после '\f' - это первая строка следующей страницы
            if (part_index > 1 && strlen(parts[1]) > 0) {
                // Записываем текущую страницу в выходной файл
                if (line_count > 0 && page_number != -1) {
                    for (int i = 0; i < line_count; i++) {
                        // Для последней строки добавляем номер страницы
                        if (i == line_count - 1) {
                            char final_line[1024];
                            appendPageNumber(page_lines[i], page_number, final_line);
                            fprintf(output_file, "%s\n", final_line);
                        }
                        else {
                            fprintf(output_file, "%s\n", page_lines[i]);
                        }
                    }
                    total_pages++;
                }

                // Начинаем новую страницу
                line_count = 0;

                // Проверяем, не содержит ли содержимое после '\f' номер страницы
                if (isPageNumberLine(parts[1])) {
                    page_number = extractPageNumber(parts[1]);
                    char content[1024];
                    removePageNumber(parts[1], content);
                    strcpy(page_lines[line_count], content);
                    line_count++;
                }
                else {
                    // Если нет номера страницы, добавляем как обычную строку
                    strcpy(page_lines[line_count], parts[1]);
                    line_count++;
                }
            }
        }
        // Обычная строка (не номер страницы и не разделитель)
        else {
            // Удаляем символ переноса в конце строки
            removeHyphens(line);
            strcpy(page_lines[line_count], line);
            line_count++;
        }

        // Проверяем следующий символ (для случая отдельного '\f' на строке)
        int next_char = fgetc(input_file);
        if (next_char == '\f') {
            // Записываем текущую страницу
            if (line_count > 0 && page_number != -1) {
                for (int i = 0; i < line_count; i++) {
                    if (i == line_count - 1) {
                        char final_line[1024];
                        appendPageNumber(page_lines[i], page_number, final_line);
                        fprintf(output_file, "%s\n\f", final_line);
                    }
                    else {
                        fprintf(output_file, "%s\n", page_lines[i]);
                    }
                }
                total_pages++;
            }

            // Начинаем новую страницу
            line_count = 0;
            page_number = -1;

            // Читаем следующую строку (первую строку новой страницы)
            if (fgets(line, sizeof(line), input_file) != NULL) {
                if (isPageNumberLine(line)) {
                    page_number = extractPageNumber(line);
                    char content[1024];
                    removePageNumber(line, content);
                    strcpy(page_lines[line_count], content);
                    line_count++;
                }
                else {
                    strcpy(page_lines[line_count], line);
                    line_count++;
                }
            }
        }
        else {
            // Возвращаем символ обратно в поток
            if (next_char != EOF) {
                ungetc(next_char, input_file);
            }
        }
    }

    // Записываем последнюю страницу
    if (line_count > 0 && page_number != -1) {
        for (int i = 0; i < line_count; i++) {
            if (i == line_count - 1) {
                char final_line[1024];
                appendPageNumber(page_lines[i], page_number, final_line);
                fprintf(output_file, "%s\n", final_line);
            }
            else {
                fprintf(output_file, "%s\n", page_lines[i]);
            }
        }
        total_pages++;
    }

    fclose(input_file);
    fclose(output_file);
    return true;
}

// ФУНКЦИЯ ДЛЯ СОЗДАНИЯ ТЕСТОВОГО ФАЙЛА

void createTestFile(const char* filename) {
    FILE* file;
    fopen_s(&file, filename, "w");

    if (file == NULL) {
        printf("Error during creating file\n");
        return;
    }

    fprintf(file, "- 1 -\n");
    fprintf(file, "First string of first page\n");
    fprintf(file, "Second string of first page\n");
    fprintf(file, "Third string of first page\n");
    fprintf(file, "\f");  // разделитель страниц
    fprintf(file, "- 2 -\n");
    fprintf(file, "First string of second page\n");
    fprintf(file, "Second string of second page\n");
    fprintf(file, "Third string of first page\n");
    fprintf(file, "\f");  // разделитель страниц
    fprintf(file, "- 3 -\n");
    fprintf(file, "Third page\n");
    fprintf(file, "Final string\n");

    fclose(file);
    printf("Test file '%s' created\n", filename);
}

int main(void) {
    char inputFilename[] = "testfile1.rtf";
    char outputFilename[] = "testfile2.rtf";
    createTestFile(inputFilename);
    processFile(inputFilename, outputFilename);

    return 0;
}

#endif
