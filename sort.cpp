#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

const int size = 5;
const int line = 10;
const int mmr = 1000;
int sumB = 0; int sumS = 0;

template <class T>
void BubbleSort(T arr[], int length = ::size) {
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				sum++;
			}
		}
		if (sum == 0) {
			cout << "Сортировка закончена.";
			break;
		}
	}
}

template <class T>
void Cooking(T arr[],int diapozone, int length = line) {
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < diapozone-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				sum++;
			}
		}
		if (sum == 0) {
			cout << "Сортировка закончена.";
			break;
		}
	}
}

template <class T>
void MegaBubbleSort(T arr[], int length = mmr, int sort = 0) {
	sort = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				sumB++;
				sort++;
			}
		}
		if (sort == 0) {
			break;
		}
	}
}

template <class T>
void MegaSelSort(T arr[], int length = mmr, int sort = 0) {
	sort = 0;
	int min = 0;
	int temp = 0;
	
	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			min = (arr[j] < arr[min]) ? j : min;
		}
		if (i != min) {
			swap(arr[i], arr[min]);
			sort++;
			sumS++;
		}
		if (sort == 0) {
			break;
		}
	}
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	//system("color B5");

	int chose = 0; int list = 0; int temp = 0;
	int phone[::size] = {};
	int Hphone[::size] = {};
	cout << "Задание 1\n";
	do {
		cout << "Выберите действие:\n[1] - Ввести номер телефона.\n[2] - Вывести данные.\n";
		cout << "[3] - Сортировка по номеру телефона.\n[4] - Сортировка по домашнему номеру телефона.\n";
		cout << "[5] - Выход.\n";
		cin >> chose;
		system("cls");
		switch (chose) {
		case 1:
			cout << "Введите " << list + 1 << " номер телефона:\n";
			cin >> phone[list];
			cout << "Введите " << list + 1 << " домашний номер телефона:\n";
			cin >> Hphone[list];
			list++;
			break;
		case 2:
			for (int i = 0; i < list; i++) {
				cout << i + 1 << " Номер: " << phone[i] << "\t\bДомашний: " << Hphone[i] << "\n";
			}
			Sleep(1000);
			break;
		case 3:
			cout << "Выполняем сортировку по номеру телефона"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";

			for (int i = 1; i < ::size; ++i)
			{
				for (int j = 0; j < ::size - i; j++)
				{
					if (phone[j] < phone[j + 1])
					{
						//Обычный
						temp = phone[j];
						phone[j] = phone[j + 1];
						phone[j + 1] = temp;
						//Домашний
						temp = Hphone[j];
						Hphone[j] = Hphone[j + 1];
						Hphone[j + 1] = temp;
					}
				}
			}

			system("cls");
			cout << "Сортировка выполнена.\n";
			break;
		case 4:
			cout << "Выполняем сортировку по Д.номеру телефона"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".";

			for (int i = 1; i < ::size; ++i)
			{
				for (int j = 0; j < ::size - i; j++)
				{
					if (Hphone[j] < Hphone[j + 1])
					{
						//Обычный
						temp = phone[j];
						phone[j] = phone[j + 1];
						phone[j + 1] = temp;
						//Домашний
						temp = Hphone[j];
						Hphone[j] = Hphone[j + 1];
						Hphone[j + 1] = temp;
					}
				}
			}

			system("cls");
			cout << "Сортировка выполнена.\n";
			Sleep(1000);
			break;
		case 5:
			cout << "Пока-пока!!!";
			Sleep(1000);
			break;
		}
	} while (chose != 5);


	system("cls");
	cout << "Задание 2\n";
	chose = 0;
	int arr[::size] = {};
	do {
		cout << "Выберите действие:\n[1] - Ввести массив вручную.\n[2] - Автозаполнение Массива.\n";
		cout << "[3] - Сортировка.\n[4] - Вывод.\n";
		cout << "[5] - Выход.\n";
		cin >> chose;
		system("cls");
		switch (chose) {
		case 1:
			for (int i = 0; i < ::size; i++) {
				cout << "Введите " << i + 1 << " число:\n";
				cin >> arr[i];
			}
			break;
		case 2:
			cout << "Заполняю массив"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".\n";
			for (int i = 0; i < ::size; i++) {
				arr[i] = 1 + rand() % 20;
			}
			cout << "\nМассив заполнен!\n";
			break;
		case 3:
			cout << "Сортирую"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".\n";
			BubbleSort(arr);
			break;
		case 4:
			cout << "Ваш массив:\n";
			for (int i = 0; i < ::size; i++) {
				cout << arr[i] << " "; Sleep(200);
			}
			cout << endl;
			break;
		case 5:
			cout << "Пока-пока!!!\n";
			Sleep(500);
			break;
		}
	} while (chose != 5);
	

	system("cls");
	cout << "Задание 3\n";
	chose = 0; int sort = 0;
	int pancake[line] = {}; int num = 0; 
	do {
		cout << "Выберите действие:\n[1] - Испечь оладьи самому.\n[2] - Авто-готовка.\n";
		cout << "[3] - Сортировка.\n[4] - Вывод.\n"; cout << "[5] - Выход.\n";
		cin >> chose;
		system("cls");
		switch (chose) {
		case 1:
			for (int i = 0; i < line; i++) {
				cout << "Введите радиус " << i + 1 << " оладушка:\n";
				cin >> pancake[i];
			}
			break;
		case 2:
			cout << "Пеку оладьи"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << ".\n";
			for (int i = 0; i < line; i++) {
				pancake[i] = 1 + rand() % 10;
			}
			cout << "\nВсё готово!!!\n";
			break;
		case 3:
			cout << "От какого оладушка начнём сортировку?\nВведите номер оладушка:\n";
			cin >> num;
			num++;
			Cooking(pancake, num);
			break;
		case 4:
			for (int i = 0; i < line; i++) {
				cout << "(";
				for (int j = 0; j < pancake[i]; j++) {
					cout << "=";
				}
				cout << ")\n";
			}
			break;
		case 5:
			cout << "Пока-пока!!!\n";
			Sleep(500);
			break;
		}
	} while (chose != 5);
	

	system("cls");
	cout << "Задание 4\n";
	int arr1[mmr] = {}; int arr2[mmr] = {}; int arr3[mmr] = {}; int arr4[mmr] = {}; int arr5[mmr] = {};
	int arr6[mmr] = {}; int arr7[mmr] = {}; int arr8[mmr] = {}; int arr9[mmr] = {}; int arr10[mmr] = {};

	for (int i = 0; i < mmr; i++) {
		arr1[i] = 1 + rand() % 10000; arr6[i] = 1 + rand() % 10000;
		arr2[i] = 1 + rand() % 10000; arr7[i] = 1 + rand() % 10000;
		arr3[i] = 1 + rand() % 10000; arr8[i] = 1 + rand() % 10000;
		arr4[i] = 1 + rand() % 10000; arr9[i] = 1 + rand() % 10000;
		arr5[i] = 1 + rand() % 10000; arr10[i] = 1 + rand() % 10000;
	}
	MegaSelSort(arr1); MegaSelSort(arr2); MegaSelSort(arr3); MegaSelSort(arr4); MegaSelSort(arr5);
	MegaSelSort(arr6); MegaSelSort(arr7); MegaSelSort(arr8); MegaSelSort(arr9); MegaSelSort(arr10);
	for (int i = 0; i < mmr; i++) {
		arr1[i] = 1 + rand() % 10000; arr6[i] = 1 + rand() % 10000;
		arr2[i] = 1 + rand() % 10000; arr7[i] = 1 + rand() % 10000;
		arr3[i] = 1 + rand() % 10000; arr8[i] = 1 + rand() % 10000;
		arr4[i] = 1 + rand() % 10000; arr9[i] = 1 + rand() % 10000;
		arr5[i] = 1 + rand() % 10000; arr10[i] = 1 + rand() % 10000;
		
	}
	MegaBubbleSort(arr1); MegaBubbleSort(arr2); MegaBubbleSort(arr3); MegaBubbleSort(arr4); MegaBubbleSort(arr5);
	MegaBubbleSort(arr6); MegaBubbleSort(arr7); MegaBubbleSort(arr8); MegaBubbleSort(arr9); MegaBubbleSort(arr10);

	sumB = sumB / 10; sumS = sumS / 10;
	cout << "Среднее число перестановок\nBubbleSort: " << sumB << "\nSelSort:" << sumS;
	
}
