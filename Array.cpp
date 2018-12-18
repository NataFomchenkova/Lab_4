#include "stdafx.h"
#include "Array.h"



Array::Array()
{
	
	elements = nullptr;
	size = 0;

}


Array::~Array()
{
	delete[] elements;
	elements = nullptr;
	size = 0;
}

int Array::get_size()
{
	return size;
}

void Array::creature(int *&elements, const int N)
{
	if (N > 0)
	{
		elements = new int[N];
		size = N;
	}
	else
		cout << "Error in size of array ";
}

void Array::show(int *elements)  
{
	for (int i = 0; i < size; i++)
		cout << elements[i] << "  ";
}

void Array::fill_rand(int *elements)
{
	for (int i = 0; i < size; i++)
		elements[i] = rand() % size + 1;
}


int Array::BinarySearch(int *elemenys, int size, int desired_elem)
{
	if ((desired_elem >= elemenys[0]) && (desired_elem <= elemenys[size - 1]))
	{
		int first = 0;
		int last = size;
		while (first < last)
		{
			const int middle = first + (last - first) / 2;

			if (desired_elem <= elemenys[middle])
				last = middle;
			else
				first = middle + 1;
		}

		if (elemenys[last] == desired_elem)
			return last;
	}
	return -1;
}

void Array::quickSort(int *elements)
{
	int pivot; // ������� � ������� ������������ ������ � ����� ������� 
	int left = 0;
	int right = size - 1;
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = elements[left];
	while (left < right) // ���� ������� �� ���������
	{
		while ((elements[right] >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			elements[left] = elements[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((elements[left] <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			elements[right] = elements[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	elements[left] = pivot; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		quickSort_inside(elements, left, pivot - 1);
	if (right > pivot)
		quickSort_inside(elements, pivot + 1, right);
}

void Array::quickSort_inside(int *elements, int left, int right)
{
	int pivot; 
	int l_hold = left; //����� �������
	int r_hold = right; // ������ �������
	pivot = elements[left];
	while (left < right) // ���� ������� �� ���������
	{
		while ((elements[right] >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			elements[left] = elements[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((elements[left] <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			elements[right] = elements[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	elements[left] = pivot; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		quickSort_inside(elements, left, pivot - 1);
	if (right > pivot)
		quickSort_inside(elements, pivot + 1, right);
}


void Array::bubble_sort(int* elements)
{
	if (size == 0)
		cout << "Array is empty";
	else {
		int temp; // ��������� ���������� ��� ������ ��������� ������� 
		for (size_t i = 0; i < size - 1; i++) {
			for (size_t j = 0; j < size - i - 1; j++) {
				if (elements[j] > elements[j + 1])
				{

					/*temp = elements[j];
					elements[j] = elements[j + 1];
					elements[j + 1] = temp;*/
					swap(elements[j], elements[j + 1]);
				}
			}

		}
	}
}


void Array::Bogo_sort(int *elenemts) // ������ ����������
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (elenemts[i] > elenemts[i + 1]) flag = true;  
		}
		if (flag)
		{
			for (int i = 0; i < size - 1; i++)
			{
				int rand_index = rand() % size;
				int help_elem = elenemts[rand_index];
				elenemts[rand_index] = elenemts[i];
				elenemts[i] = help_elem;
				/*swap(elements[rand() % size], elements[i]);*/
			}
		}
	}
}

void Array::heapify(int *elements, int root, int bottom_row)
{
	int largest = bottom_row;
	int l = 2 * bottom_row + 1;
	int r = 2 * bottom_row + 2;
	if ((l < root) && (elements[l] > elements[largest]))
		largest = l;
	if ((r < root) && (elements[r] > elements[largest]))
		largest = r;
	if (largest != bottom_row)
	{
		swap(elements[bottom_row], elements[largest]);
		heapify(elements, root, largest);
	}
}


void Array::heapSort(int *elements)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(elements, size, i);
	for (int i = size - 1; i >= 0; i--)
	{
		swap(elements[0], elements[i]);
		heapify(elements, i, 0);
	}
}

void Array::CharCreature(char *&elements, const int N) //��� ������ ��������� ����� ��������� ������ ��� ������
{

	elements = new char[N];
	size = N;
}

void Array::CharFill(char *elements)    // ���������� ������� ���������� ���������� �������
{
	char letter;
	cout << "Enter an array of char:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> letter;
		elements[i] = letter;
		
	}
}

void Array::CharShow(char *elements)
{
	for (int i = 0; i < size; i++) 
		cout << elements[i] << "  ";
}


void Array::CountingSort(char* elements)
{
	size_t* SortingArray = new size_t[255];// �������� �������� char �� -127 �� 127
	for (size_t i = 0; i < 255; i++)
		SortingArray[i] = 0;
	for (size_t i = 0; i < size; i++)
	{
		SortingArray[elements[i]]++;
	}
	size_t j = 0;
	
	for (size_t i = 0; i < 255; i++)
	{
		while (SortingArray[i] != 0)
		{
			char c = i;
			elements[j] = c;
			j++;
			SortingArray[i]--;
		}
	}

}

int correct(int *elements, int size)
{
	if (size <= 0)
		return 0;
	else
	{
		while (--size > 0)
			if (elements[size - 1] > elements[size])
				return 0;
		return 1;
	}
}


bool is_equal(int*a1, int size, int*a2)
{
	for (int i = 0; i < size; i++)
	{
		if (a1[i] != a2[i])
			return false;
	}
	return true;
}

bool is_equal_char(char*a1, int size, char*a2)
{
	for (int i = 0; i < size; i++)
	{
		if (a1[i] != a2[i])
			return false;
	}
	return true;
}
//���������� �������� ����� � int, ���� ��� -1
