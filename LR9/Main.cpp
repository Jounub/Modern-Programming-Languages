#include "Money.h";
#include "TStack.h";
#include <vector>


//Пунк 9.1.1. Шаблон для функции сортировки массива. Сортировка пузырьком.
template <class T>
void Sort(T array[], size_t size)
{
	int i, j;
	T tmp;

	for (i = 0; i < size - 1; i++)
		for(j= size - 1; i<j; j--)
			if(array[j] > array[j+1])
			{
				tmp = array[j];
				array[j] = array[j-1];
				array[j-1] = tmp;
			}
}

//Пунк 9.1.2. Перегруженный шаблон для функции, которая возвращает максимум из двух переданных ей аргументов и максимум из массива.
template <class T>
T getmax(T t1, T t2)
{
	return t1 > t2?t1:t2;
}

template <class T>
T getmax(T t[], size_t size)
{
	T retval = t[0];
	for (int i = 0; i < size; i++)
		if (t[i] > retval)
			retval = t[i];
	return retval;
}

//Пунк 9.1.3. Специализация шаблона для функции, которая возвращает максимум из двух переданных ей аргументов и максимум из массива для типа char*.
const char* getmax(const char* s1, const char* s2)
{
	return strcmp(s1, s2) > 0? s1:s2;
}

void printArray(int n, int  arr[])
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

// Функция для сортировки железнодорожного состава с использованием тупика
void sortTrain(vector<int>& input, vector<int>& output, Tstack<int>& deadEnd) {
    cout << "\n=== Starting train sorting ===" << endl;
    cout << "Input train: ";
    for (int val : input) {
        cout << val << " ";
    }
    cout << endl;

    int expectedWagon = 1;  // Какой вагон ожидаем на выходе
    int inputIndex = 0;      // Индекс текущего вагона на входе
    int n = input.size();

    while (output.size() < n) {
        // 1. Если нужный вагон находится на входе, отправляем его сразу на выход
        if (inputIndex < n && input[inputIndex] == expectedWagon) {
            cout << "Wagon " << expectedWagon << " goes directly from input to output" << endl;
            output.push_back(input[inputIndex]);
            inputIndex++;
            expectedWagon++;
        }
        // 2. Если нужный вагон находится в тупике (стеке), извлекаем его
        else if (!deadEnd.empty() && deadEnd.peek() == expectedWagon) {
            int wagon = deadEnd.pop();
            cout << "Wagon " << wagon << " moves from dead end to output" << endl;
            output.push_back(wagon);
            expectedWagon++;
        }
        // 3. Если нужного вагона нет ни на входе, ни в тупике,
        //    перемещаем следующий вагон со входа в тупик
        else if (inputIndex < n) {
            int wagon = input[inputIndex];
            if (!deadEnd.full()) {
                cout << "Wagon " << wagon << " moves from input to dead end" << endl;
                deadEnd.push(wagon);
                inputIndex++;
            }
            else {
                cout << "ERROR: Dead end is full! Cannot sort further." << endl;
                break;
            }
        }
        // 4. Невозможно продолжить сортировку
        else {
            cout << "ERROR: Cannot sort the train configuration!" << endl;
            break;
        }

        // Отображаем текущее состояние
        cout << "  Current output: ";
        for (int val : output) {
            cout << val << " ";
        }
        cout << endl;
        deadEnd.print();
        cout << "  Expected next wagon: " << expectedWagon << endl;
        cout << "------------------------" << endl;
    }
}

// Функция для проверки, можно ли отсортировать состав
bool canSort(vector<int> wagons, Tstack<int>& deadEnd) {
    vector<int> output;
    int expected = 1;
    int index = 0;
    int n = wagons.size();

    while (output.size() < n) {
        if (index < n && wagons[index] == expected) {
            output.push_back(wagons[index]);
            index++;
            expected++;
        }
        else if (!deadEnd.empty() && deadEnd.peek() == expected) {
            output.push_back(deadEnd.pop());
            expected++;
        }
        else if (index < n) {
            if (!deadEnd.full()) {
                deadEnd.push(wagons[index]);
                index++;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    return true;
}

void main(void)
{
	Money mas[] = {Money(19, 10),
					Money(99, 99), 
					Money(99, 95), 
					Money(19, 95),
					};
	Sort(mas, sizeof(mas)/sizeof(mas[0]));
	for (int i=0; i< sizeof(mas) / sizeof(mas[0]); i++)
		cout << "mas["<<i<<"] = " << mas[i]<< endl;

	int i1=2, i2=5;

	cout << "Max value in mas[] = " << getmax(mas, sizeof(mas)/sizeof(mas[0])) << endl;
	cout << "Max int = " << getmax(i1, i2) << endl;

	const char *s1 = "string1";
	const char* s2 = "string2";
	cout << "Max str = " << getmax(s1, s2) << endl;

	int n = 3;
    int input[] = {1, 5, 3}, output[] = {5, 3, 1};

    Tstack<int> st(n);

    printArray(n, input);

    int j = 0;

    cout << "  Current stack state: ";
    if (st.empty())
        cout << "[empty]";
    else
    {
        for (int k = 0; k < st.numItem; k++)
            cout << st.item[k] << " ";
    }

    vector<int> train1 = { 3, 2, 1, 4 };
    Tstack<int> deadEnd1(3);  // Тупик на 3 вагона
    vector<int> output1;

    cout << "Initial train: ";
    for (int w : train1) cout << w << " ";
    cout << endl;

    sortTrain(train1, output1, deadEnd1);

    cout << "\nFinal sorted output: ";
    for (int w : output1) cout << w << " ";
    cout << endl;
}
