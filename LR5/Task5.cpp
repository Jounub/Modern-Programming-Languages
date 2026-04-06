#ifdef TASK5

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <windows.h>

// ФУНКЦИЯ ШИФРОВАНИЯ
/**
 * Шифрует/дешифрует файл методом XOR с циклическим ключом
 *
 * @param input_filename  - имя входного файла
 * @param output_filename - имя выходного файла
 * @param key            - ключ шифрования (строка)
 * @return true - успех, false - ошибка
 *
 * Примечание: XOR симметричен, поэтому шифрование и дешифрование
 * выполняются одной и той же функцией
 */
bool xorCryptFile(const char* input_filename, const char* output_filename, const char* key) {
    FILE* input_file;
    FILE* output_file;

    // Открываем входной файл для чтения в бинарном режиме
    // (чтобы корректно обрабатывать все символы, включая '\0')
    errno_t err_in = fopen_s(&input_file, input_filename, "rb");
    if (err_in != 0) {
        printf("Error opening file '%s'\n", input_filename);
        return false;
    }

    // Открываем выходной файл для записи в бинарном режиме
    errno_t err_out = fopen_s(&output_file, output_filename, "wb");
    if (err_out != 0) {
        printf("Error creating file '%s'\n", output_filename);
        fclose(input_file);
        return false;
    }

    int key_len = strlen(key);
    if (key_len == 0) {
        printf("Error: encryption key is empty\n");
        fclose(input_file);
        fclose(output_file);
        return false;
    }

    int ch;
    int key_index = 0;
    long long bytes_processed = 0;

    // Читаем файл по байтам и применяем XOR с ключом
    while ((ch = fgetc(input_file)) != EOF) {
        // Применяем XOR: символ ^ символ ключа
        int encrypted_char = ch ^ key[key_index];
        fputc(encrypted_char, output_file);

        // Переходим к следующему символу ключа (циклически)
        key_index = (key_index + 1) % key_len;
        bytes_processed++;
    }

    fclose(input_file);
    fclose(output_file);
    return true;
}

int main(int argc, char* argv[]) 
{
    char filename[50];
    char encryptionKey[50];

    printf("Enter file name: ");
    scanf_s("%49s", filename, (unsigned)sizeof(filename));

    printf("Enter encryption key: ");
    scanf_s("%49s", encryptionKey, (unsigned)sizeof(encryptionKey));

    xorCryptFile(filename, "encryptionTest.txt", encryptionKey);

    xorCryptFile("encryptionTest.txt", "decryptionTest.txt", encryptionKey);
}
#endif
