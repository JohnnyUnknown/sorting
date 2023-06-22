#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int* size_array(int size) {
	int* m = new int[size];
	return m;
}

void create_array(int* array, int size) {
	size_array(size);
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
}

void show_array(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int sort_bubble(int array[], int size) {
	create_array(array, size);
	bool metka = true;
	int counter = 0;
	cout << "Отсортированный массив 'Пузырьком': ";
	for (int i = 0; i < size && metka; i++) {
		counter++;
		metka = false;
		for (int j = size - 1; j >= i; j--) {
			if (array[j] < array[j - 1]) {
				swap(array[j], array[j - 1]);
				metka = true;
			}
		}
		cout << array[i] << " ";		//для наглядности
	}
	cout << endl;
	return counter;
}

int sort_choice(int array[], int size) {
	create_array(array, size);
	int counter = 0;
	cout << "Отсортированный массив 'Выбором': ";
	for (int i = 0; i < size; i++) {
		counter++;
		int min = array[i], min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < min) {
				min = array[j];
				min_index = j;
			}
		}
		if (min_index != i) {
			array[min_index] = array[i];
			array[i] = min;
		}
		cout << array[i] << " ";			//для наглядности
	}
	cout << endl;
	return counter;
}

int average(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	int aver = sum / size;
	return aver;
}

int main() {
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	const int n = 10;
	const int lot_array = 10;
	int count_bubble[lot_array], count_choice[lot_array];
	int* array = nullptr;
	array = size_array(n);
	for (int i = 0; i < 10; i++) {
		count_bubble[i] = sort_bubble(array, n);
	}
	cout << "Количество итераций в 10 циклах для сортировки 'Пузырьком': ";
	show_array(count_bubble, lot_array);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		count_choice[i] = sort_choice(array, n);
	}
	cout << "Количество итераций в 10 циклах для сортировки 'Выбором': ";
	show_array(count_choice, lot_array);
	cout << endl;
	int average_bubble, average_choice;
	average_bubble = average(count_bubble, lot_array);
	cout << "Среднее число итераций в 10 циклах (Пузырек): " << average_bubble << endl;
	average_choice = average(count_choice, lot_array);
	cout << "Среднее число итераций в 10 циклах (Выбор): " << average_choice << endl;
	return 0;
}
