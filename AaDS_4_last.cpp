// AaDS_4_last.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Array.h"
#include <conio.h>
#include <ctime>
#include <time.h>


// 1 Двоичный поиск(BinarySearch)*
// 2 Быстрая сортировка(QuickSort)*
// 4 Сортировка пузырьком(BubbleSort)*
// 6 Пирамидальная сортировка(HeapSort)*
// 7 Глупая сортировка(BogoSort)*
// 8 Сортировка подсчётом(CountingSort) для типа char



int main()
{
	int choice;
	int *PtrArray = NULL;
	char * ptrChar = nullptr;
	Array Array;
	int size = 10;
	Array.creature(PtrArray, size);


	cout << "1. HeapSort \n";
	cout << "2. BinarySearch \n";
	cout << "3. QuickSort \n";
	cout << "4. BubbleSort \n";
	cout << "5. BogoSort \n";
	cout << "6. CountingSort \n";
	cout << "0. Exit \n";

	

	//Array.show(PtrArray);
	
	do
	{
		
		cout << '\n' << "Select an item in the menu: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			Array.fill_rand(PtrArray);
			cout << "Source array:			 ";
			Array.show(PtrArray);
			Array.heapSort(PtrArray);
			cout << '\n' << "Array after sorting (heapSort): ";
			Array.show(PtrArray);
			cout << "\n";

			break;
		}
		case 2:
		{
			Array.fill_rand(PtrArray);
			cout << "Source array:		";
			Array.show(PtrArray);
			Array.bubble_sort(PtrArray);
			cout << '\n' << "Array after BubbleSort: ";
			Array.show(PtrArray);
			cout << '\n' << "BinarySearch\n";
			cout << " Enter the desired elem: ";
			int desired_elem;
			cin >> desired_elem;
			int help = (Array.BinarySearch(PtrArray, size, desired_elem));
			if (help!=-1)
				cout << "The element index is "<< help;
			else 
				cout <<" Elem noy found \n ";
			break;
		}

		case 3:
		{
			Array.fill_rand(PtrArray);
			cout << "Source array:			 ";
			Array.show(PtrArray);
			cout << '\n' << "Array after sorting (QuickSort): ";
			clock_t t = clock();
			Array.quickSort(PtrArray);
			t = clock() - t;
			Array.show(PtrArray);
			printf("\n It took me %d clicks (%f seconds).\n", t, ((float)t / CLOCKS_PER_SEC));
			cout << '\n';
			break;
		}

		case 4:
		{
			Array.fill_rand(PtrArray);
			cout << "Source array:			";
			Array.show(PtrArray);
			cout << '\n' << "Array after sorting (BubbleSort): ";
			clock_t t = clock();
			t = clock();
			Array.bubble_sort(PtrArray);
			t = clock() - t;
			Array.show(PtrArray);
			printf("\nIt took me %d clicks (%f seconds).\n", t, ((float)t / CLOCKS_PER_SEC));
			break;
		}
		case 5:
		{
			Array.fill_rand(PtrArray);
			cout << "Source array:			";
			Array.show(PtrArray);
			cout << '\n'<< "Array after sorting (BogoSort): ";
			Array.Bogo_sort(PtrArray);
			Array.show(PtrArray);
			cout << '\n';
			break;
		}

		case 6:
		{
			Array.CharCreature(ptrChar, size);      //выделяю память для size элементов
			Array.CharFill(ptrChar);
			cout << "Our char array:\n";
			Array.CharShow(ptrChar);
			cout << "\n";
			cout << " CountingSort array:\n";
			Array.CountingSort(ptrChar);
			Array.CharShow(ptrChar);
			cout << '\n';
			break;
		}
		}
		_getch();
	} while (choice != 0);


	
	_getch();
	return 0;

}