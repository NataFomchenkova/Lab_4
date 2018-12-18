#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AaDS_4_last/Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test_for_laba4
{		
	TEST_CLASS(Tests_for_array)
	{
	public:

		TEST_METHOD(check_correct)
		{
			int *PtrArray1 = NULL;
			Array test_array;
			int size = 6;
			test_array.creature(PtrArray1, size);
			PtrArray1[0] = 1;
			PtrArray1[1] = 3;
			PtrArray1[2] = 7;
			PtrArray1[3] = 15;
			PtrArray1[4] = 2;
			PtrArray1[5] = 9;
			

			test_array.heapSort(PtrArray1);
			int *PtrArray2 = new int[6]{1,2,3,7,9,15};
			Assert::IsTrue(is_equal(PtrArray1, size, PtrArray2));
		}


		TEST_METHOD(check_heap_sort_size_20)
		{
			int *PtrArray = NULL;
			Array test_array;
			int size = 20;
			test_array.creature(PtrArray, size);
			test_array.fill_rand(PtrArray);
			test_array.heapSort(PtrArray);

			Assert::IsTrue(correct(PtrArray, size));

		}
		
		TEST_METHOD(check_bubble_sort_size_20)
		{
			int *PtrArray = NULL;
			Array test_array;
			int size = 20;
			test_array.creature(PtrArray, size);
			test_array.fill_rand(PtrArray);
			test_array.bubble_sort(PtrArray);

			Assert::IsTrue(correct(PtrArray, size));
		}

		TEST_METHOD(check_QuickSort_size_20)
		{
			int *PtrArray = NULL;
			Array test_array;
			int size = 20;
			test_array.creature(PtrArray, size);
			test_array.fill_rand(PtrArray);
			test_array.quickSort(PtrArray);
			Assert::IsTrue(correct(PtrArray, size));
		}

		TEST_METHOD(check_Bogo_sort_size10)
		{
			int *PtrArray = NULL;
			Array test_array;
			int size = 10;
			test_array.creature(PtrArray, size);
			test_array.fill_rand(PtrArray);
			test_array.Bogo_sort(PtrArray);

			Assert::IsTrue(correct(PtrArray, size));
		}

		TEST_METHOD(check_CountingSort_size_5)
		{
			
			char* PtrChar = new char[5]{ 'a', 'b', 'c','d','e' };
			char *PtrArray = NULL;
			Array test_array;
			int size = 5;
			test_array.CharCreature(PtrArray, size);
			PtrArray[0] = 'c';
			PtrArray[1] = 'a';
			PtrArray[2] = 'd';
			PtrArray[3] = 'e';
			PtrArray[4] = 'b';
			test_array.CountingSort(PtrArray);
			
			Assert::IsTrue(is_equal_char(PtrChar, 5, PtrArray));

		} 

		TEST_METHOD(check_BinarySearch_size_5_found)
		{
			int *PtrArray = NULL;
			Array test_array;
			int size = 5;
			test_array.creature(PtrArray, size);
			PtrArray[0] = 7;
			PtrArray[1] = 3;
			PtrArray[2] = 14;
			PtrArray[3] = 1;
			PtrArray[4] = 7;

			test_array.bubble_sort(PtrArray);
			 
			Assert::IsTrue(test_array.BinarySearch(PtrArray, size, 1)==0);

		}
		TEST_METHOD(check_BinarySearch_size_5_not_found)
		{
			int *PtrArray = NULL;
			Array test_array;
			int size = 5;
			test_array.creature(PtrArray, size);

			PtrArray[0] = 8;
			PtrArray[1] = 31;
			PtrArray[2] = 7;
			PtrArray[3] = 4;
			PtrArray[4] = 9;

			test_array.heapSort(PtrArray);

			Assert::IsTrue(test_array.BinarySearch(PtrArray, size, 1)==-1);

		}
	};
}