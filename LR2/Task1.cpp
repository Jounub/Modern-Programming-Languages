#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#define N 5
using namespace std;


// Функция для нахождения минимума всей матрицы
float minMatrix(float m[N][N]) {
    float min = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для нахождения максимума всей матрицы
float maxMatrix(float m[N][N]) {
    float max = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для нахождения максимума нижнетреугольной части матрицы
// Нижнетреугольная часть: i >= j (включая главную диагональ)
float maxLowerTriangle(float m[N][N]) {
    float max = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для нахождения максимума верхнетреугольной части матрицы
// Верхнетреугольная часть: i <= j (включая главную диагональ)
float maxUpperTriangle(float m[N][N]) {
    float max = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
    }
    return max;
}

// Функция для нахождения минимума нижнетреугольной части матрицы
float minLowerTriangle(float m[N][N]) {
    float min = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для нахождения минимума верхнетреугольной части матрицы
float minUpperTriangle(float m[N][N]) {
    float min = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
    }
    return min;
}

// Функция для нахождения минимума главной диагонали
float minMainDiagonal(float m[N][N]) {
    float min = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] < min) {
            min = m[i][i];
        }
    }
    return min;
}

// Функция для нахождения максимума главной диагонали
float maxMainDiagonal(float m[N][N]) {
    float max = m[0][0];
    for (int i = 0; i < N; i++) {
        if (m[i][i] > max) {
            max = m[i][i];
        }
    }
    return max;
}

// Функция для нахождения минимума второстепенной диагонали
// Второстепенная диагональ: i + j = N - 1
float minSecondaryDiagonal(float m[N][N]) {
    float min = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] < min) {
            min = m[i][N - 1 - i];
        }
    }
    return min;
}

// Функция для нахождения максимума второстепенной диагонали
float maxSecondaryDiagonal(float m[N][N]) {
    float max = m[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (m[i][N - 1 - i] > max) {
            max = m[i][N - 1 - i];
        }
    }
    return max;
}


// Функция для нахождения суммы элементов нижнетреугольной части
float sumLowerTriangle(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum;
}

// Функция для нахождения суммы элементов верхнетреугольной части
float sumUpperTriangle(float m[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += m[i][j];
            count++;
        }
    }
    return sum;
}

// Функция для нахождения среднего арифметического всей матрицы
float averageMatrix(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += m[i][j];
        }
    }
    return sum / (N * N);
}

// Функция для нахождения среднего арифметического нижнетреугольной части
float averageLowerTriangle(float m[N][N]) {
    float sum = sumLowerTriangle(m);
    int count = (N * (N + 1)) / 2; // Количество элементов в нижней треугольной части с диагональю
    return sum / count;
}

// Функция для нахождения среднего арифметического верхнетреугольной части
float averageUpperTriangle(float m[N][N]) {
    float sum = sumUpperTriangle(m);
    int count = (N * (N + 1)) / 2; // Количество элементов в верхней треугольной части с диагональю
    return sum / count;
}

// Функция для нахождения суммы строки матрицы
float rowSum(float m[N][N], int row) 
{
    float sum = 0;
    for (int j = 0; j < N; j++) {
        sum += m[row][j];
    }
    return sum;
}

// Функция для нахождения суммы столбца матрицы
float columnSum(float m[N][N], int column)
{
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += m[i][column];
    }
    return sum;
}

// Функция для вывода минимальных значений в строках
void printRowMins(float m[N][N]) {
    cout << "\nMinimum values in the rows:" << endl;
    for (int i = 0; i < N; i++) {
        float min = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
        cout << "Row " << i + 1 << ": " << min << endl;
    }
}

// Функция для вывода минимальных значений в столбцах
void printColumnMins(float m[N][N]) {
    cout << "\nMinimum values in the columns:" << endl;
    for (int j = 0; j < N; j++) {
        float min = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] < min) {
                min = m[i][j];
            }
        }
        cout << "Column " << j + 1 << ": " << min << endl;
    }
}

void printRowMaxs(float m[N][N]) {
    cout << "\nMaximum values in the rows:" << endl;
    for (int i = 0; i < N; i++) {
        float max = m[i][0];
        for (int j = 1; j < N; j++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
        cout << "Row " << i + 1 << ": " << max << endl;
    }
}

// Функция для вывода максимальных значений в столбцах
void printColumnMaxs(float m[N][N]) {
    cout << "\nMaximum values in the columns:" << endl;
    for (int j = 0; j < N; j++) {
        float max = m[0][j];
        for (int i = 1; i < N; i++) {
            if (m[i][j] > max) {
                max = m[i][j];
            }
        }
        cout << "Column " << j + 1 << ": " << max << endl;
    }
}

// Функция для вывода средних арифметических значений строк
void printRowAverages(float m[N][N]) {
    cout << "\nAverage of the rows:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Row " << i + 1 << ": " << rowSum(m, i) / N << endl;
    }
}

// Функция для вывода средних арифметических значений столбцов
void printColumnAverages(float m[N][N]) {
    cout << "\nAverage of the columns" << endl;
    for (int j = 0; j < N; j++) {
        cout << "Column " << j + 1 << ": " << columnSum(m, j) / N << endl;
    }
}

void findClosestToAverage(float m[N][N]) {
    float avg = averageMatrix(m);

    // Ищем элемент, наиболее близкий к среднему значению
    float closestValue = m[0][0];
    float minDiff = abs(m[0][0] - avg);
    int closestI = 0, closestJ = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = abs(m[i][j] - avg);
            if (diff < minDiff) {
                minDiff = diff;
                closestValue = m[i][j];
                closestI = i;
                closestJ = j;
            }
        }
    }
    cout << "\nElement closest to the average:" << endl;
    cout << "Value: " << closestValue << endl;
    cout << "Position: row " << closestI + 1 << ", column " << closestJ + 1 << endl;
    cout << "Decline from average: " << minDiff << endl;
}

int main() 
{
	float m[N][N];
	int i, j;
	for (i=0; i<N; i++)
		for(j=0; j<N; j++) m[i][j] = rand()/10.;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout<<setw(8)<<setprecision(5)<<m[i][j];
		cout<<endl;
	}
    // Вывод результатов всех вычислений
    cout << "\n========== Calculation results ==========" << endl;
    cout << "Minimum of the entire matrix: " << minMatrix(m) << endl;
    cout << "Maximum of the entire matrix: " << maxMatrix(m) << endl;
    cout << "Maximum of the lower triangular part : " << maxLowerTriangle(m) << endl;
    cout << "Maximum of the upper triangular part " << maxUpperTriangle(m) << endl;
    cout << "Minimum of the lower triangular part : " << minLowerTriangle(m) << endl;
    cout << "Minimum of the upper triangular part " << minUpperTriangle(m) << endl;
    cout << "Minimum of the main diagonal: " << minMainDiagonal(m) << endl;
    cout << "Maximum of the main diagonal: " << maxMainDiagonal(m) << endl;
    cout << "Minimum of the secondary diagonal: " << minSecondaryDiagonal(m) << endl;
    cout << "Maximum of the secondary diagonal: " << maxSecondaryDiagonal(m) << endl;
    cout << "Average of the entire matrix: " << averageMatrix(m) << endl;
    cout << "Average of the lower triangular part: " << averageLowerTriangle(m) << endl;
    cout << "Average of the upper triangular part: " << averageUpperTriangle(m) << endl;
    cout << "Sum of the upper triangular part: " << sumUpperTriangle(m) << endl;
    cout << "Sum of the lower triangular part: " << sumLowerTriangle(m) << endl;

    cout << "\nSums of the rows: " << endl;
    for (int i = 0; i < N; i++) {        
        cout << "Row " << i + 1 << " sum: " << rowSum(m, i) << endl;
    }

    cout << "\nSums of the columns: " << endl;
    for (int j = 0; j < N; j++) {
        cout << "Column " << j + 1 << " sum: " << columnSum(m, j) << endl;
    }



    printRowMins(m);
    printColumnMins(m);
    printRowMaxs(m);
    printColumnMaxs(m);
    printRowAverages(m);
    printColumnAverages(m);
    findClosestToAverage(m);

	_getch();
    return 0;
}
