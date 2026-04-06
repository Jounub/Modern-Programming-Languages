#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int n);
void printArray(int n, int  arr[]);
void quickSort(int arr[], int low, int high);
void sortEvenAscOddDesc(int arr[], int n);
void sortAscendingInRange(int arr[], int n, int N1, int N2);
void sortDescendingInRange(int arr[], int n, int N1, int N2);


void main(void) 
{

	//Исходный массив
	int mas[] = {2,5,-8,1,-4,6,3,-5,-9,13,0,4,9};
	//вычисление n - количества элементов
	constexpr int n = sizeof(mas) / sizeof(int);

	//Массив для сортировки
	int mas1[n];

	//
	std::copy(std::begin(mas), std::end(mas), mas1);

	//текущие индексы мин. и макс. элементов
	int imin, imax;

	int i;
	//установка начальных индексов для мин и макс
	imin =i=0; imax=i=0;

	system("cls");
	printArray(n, mas1);

	/*
	АЛГОРИТМ "МИНИ-МАКСА" (СОРТИРОВКА ВЫБОРОМ)
	Принцип работы:
	1. На каждой итерации ищется минимальный элемент в неотсортированной части массива
	2. Найденный минимальный элемент меняется местами с первым элементом неотсортированной части
	3. Граница отсортированной части сдвигается вправо
	4. Процесс повторяется, пока весь массив не будет отсортирован
	*/

	for (i = 0; i < n - 1; i++) //нахождение мин и макс
	{
		imin = i; // предполагаем, что текущий элемент - минимальный
		// Поиск минимального элемента в неотсортированной части
		for(int j = i+ 1; j < n; j++)
			if(mas1[j] < mas1[imin]) imin = j; // нашли новый минимальный элемент
		// Обмен местами текущего элемента с найденным минимальным
		int t = mas1[i];
		mas1[i] = mas1[imin];
		mas1[imin] = t;
	}

	cout << "\nMin-max sort: " << endl;
	printArray(n, mas1);

	//Восстанавливаем массив mas1 из исходного массива
	std::copy(std::begin(mas), std::end(mas), mas1);
	cout << "\nInitial array: " << endl;
	printArray(n, mas1);

	bubbleSort(mas1, n);

	cout << "\nBubble sort: " << endl;
	printArray(n, mas1);

	std::copy(std::begin(mas), std::end(mas), mas1);
	cout << "\nInitial array: " << endl;
	printArray(n, mas1);

	quickSort(mas1, 0, n - 1);

	cout << "\nQuick sort: " << endl;
	printArray(n, mas1);

	std::copy(std::begin(mas), std::end(mas), mas1);
	cout << "\nInitial array: " << endl;
	printArray(n, mas1);

	cout << "\nSort even in ascending order, odd in descending order: " << endl;
	sortEvenAscOddDesc(mas1, n);
	printArray(n, mas1);

	std::copy(std::begin(mas), std::end(mas), mas1);
	cout << "\nInitial array: " << endl;
	printArray(n, mas1);

	cout << "\nSort ascending in range, N1 = 1, N2 = 4: " << endl;
	sortAscendingInRange(mas1, n, 1, 4);
	printArray(n, mas1);

	std::copy(std::begin(mas), std::end(mas), mas1);
	cout << "\nInitial array: " << endl;
	printArray(n, mas1);

	cout << "\nSort descending in range, N1 = 2, N2 = 6: " << endl;
	sortDescendingInRange(mas1, n, 2, 6);
	printArray(n, mas1);
}

void printArray(int n, int  arr[])
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

/*
СОРТИРОВКА ПУЗЫРЬКОМ
Принцип работы:
- Последовательно сравниваются соседние элементы
- Если они стоят в неправильном порядке, они меняются местами
- Каждый проход "выталкивает" максимальный элемент в конец массива
- Сложность: O(n²) в худшем и среднем случае
*/
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;  // флаг для оптимизации

		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// Обмен элементов
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}

		// Если не было обменов, массив уже отсортирован
		if (!swapped) break;
	}
}

/*
БЫСТРАЯ СОРТИРОВКА
Принцип работы (алгоритм "разделяй и властвуй"):
1. Выбирается опорный элемент (pivot)
2. Массив разделяется на две части: элементы меньше опорного и больше опорного
3. Рекурсивно сортируются обе части
Сложность: O(n log n) в среднем, O(n²) в худшем случае
*/

// Функция разделения массива
int partition(int arr[], int low, int high) {
	int pivot = arr[high];  // выбираем последний элемент как опорный
	int i = low - 1;  // индекс для элемента, меньшего pivot

	for (int j = low; j < high; j++) {
		// Если текущий элемент меньше или равен pivot
		if (arr[j] <= pivot) {
			i++;
			// Меняем местами arr[i] и arr[j]
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// Помещаем pivot на правильное место
	int temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return i + 1;  // возвращаем индекс pivot
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);  // индекс опорного элемента

		// Рекурсивно сортируем элементы до и после опорного
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/*
Можно ли такие функции использовать для работы с многомерным массивом?
Да, можно, но с определенными подходами:
Способ 1: Представить многомерный массив как одномерный (в памяти он хранится линейно) и передать указатель на первый элемент
Способ 2: Сортировать каждую строку/столбец отдельно
Способ 3: Использовать индексацию для преобразования многомерных координат в одномерные
*/

/*
Задача: четные элементы сортируются по возрастанию,
нечетные элементы - по убыванию
*/
void sortEvenAscOddDesc(int arr[], int n) {
	// Отделяем четные и нечетные элементы
	int evens[100], odds[100];
	int evenCount = 0, oddCount = 0;

	// Разделяем массив на четные и нечетные
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			evens[evenCount++] = arr[i];
		}
		else {
			odds[oddCount++] = arr[i];
		}
	}

	// Сортируем четные по возрастанию
	for (int i = 0; i < evenCount - 1; i++) {
		for (int j = 0; j < evenCount - i - 1; j++) {
			if (evens[j] > evens[j + 1]) {
				swap(evens[j], evens[j + 1]);
			}
		}
	}

	// Сортируем нечетные по убыванию
	for (int i = 0; i < oddCount - 1; i++) {
		for (int j = 0; j < oddCount - i - 1; j++) {
			if (odds[j] < odds[j + 1]) {
				swap(odds[j], odds[j + 1]);
			}
		}
	}

	// Собираем обратно в исходный массив, сохраняя позиции четных и нечетных
	evenCount = 0;
	oddCount = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] = evens[evenCount++];
		}
		else {
			arr[i] = odds[oddCount++];
		}
	}
}

// Сортировка по возрастанию на интервале от N1 до N2
void sortAscendingInRange(int arr[], int n, int N1, int N2) {
	// Проверка корректности границ
	if (N1 < 0) N1 = 0;
	if (N2 >= n) N2 = n - 1;
	if (N1 >= N2) {
		cout << "Некорректные границы интервала!" << endl;
		return;
	}

	// Сортировка пузырьком на указанном интервале
	for (int i = N1; i < N2; i++) {
		for (int j = N1; j < N2 - (i - N1); j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// Сортировка по убыванию на интервале от N1 до N2
void sortDescendingInRange(int arr[], int n, int N1, int N2) {
	// Проверка корректности границ
	if (N1 < 0) N1 = 0;
	if (N2 >= n) N2 = n - 1;
	if (N1 >= N2) {
		cout << "Некорректные границы интервала!" << endl;
		return;
	}

	// Сортировка пузырьком по убыванию на указанном интервале
	for (int i = N1; i < N2; i++) {
		for (int j = N1; j < N2 - (i - N1); j++) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}