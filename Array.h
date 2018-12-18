#pragma once
#include <iostream>
#define cin std::cin
#define cout std::cout
#define swap std::swap

int correct(int *elements, int size);
bool is_equal(int*a1, int size, int*a2);
bool is_equal_char(char*a1, int size, char*a2);

class Array
{
	int *elements;
	size_t size;
	void heapify(int *elements, int root, int bottom_row); //вспомогательная функция для пирамидальной сортировки
	void quickSort_inside(int *elements, int left, int right); //вспомогательная функция для быстрой сортировки 

public:
	Array();
	~Array();
	int get_size();
	void creature(int *&elements, const int size);  // выделение памяти под массив
	void show(int *elements); // вывод элементов на экран 
	void fill_rand(int *elements); // рандомное заполнение 
	void bubble_sort(int* elements); 	
	int BinarySearch(int *elemenys, int size, int desired_elem);
	void quickSort(int *elements);
	void Bogo_sort(int *elenemts);
	void heapSort(int *elements);
	void CharCreature(char *&elements, const int size); // выделение памяти под массив символов
	void CharFill(char *elements);// запомнение массива с клавиатуры
	void CharShow(char *elements); // вывод массива на экран 
	void CountingSort(char* elements); 



};

