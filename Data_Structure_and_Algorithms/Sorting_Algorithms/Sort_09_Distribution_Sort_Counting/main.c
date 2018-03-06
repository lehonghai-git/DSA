#include <stdio.h>
#define MAX 100
#define INPUT_SIZE 20
#define M 10

/*
** Giải thuật Sắp xếp bằng phép đếm phân phối (Distribution Sort - Counting Sort)
** Input	: Mảng một chiều số nguyên, số phần tử mảng, biết được giá trị của dãy trong đoạn nào đó
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void XuatMang(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d   ", array[i]);
	}
	printf("\n");
}

void countingSort(int array[], int length)
{
	int countArr[M] = { 0 };
	for (int i = 0; i < length; i++)
	{
		countArr[array[i]]++;
	}
	int outputIndex = 0;
	for (int i = 0; i < M; i++)
	{
		while (countArr[i]-- > 0)
		{
			array[outputIndex++] = i;
		}
	}
}

int main()
{
	int array[INPUT_SIZE] = { 8, 4, 6, 4, 7, 1, 1, 9, 5, 3, 9, 2, 2, 6, 9, 3, 7, 3, 4, 5 };

	printf("\nMang chua sap xep:\n");
	XuatMang(array, INPUT_SIZE);

	// Sorting
	countingSort(array, INPUT_SIZE);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, INPUT_SIZE);

	getch();
	return 0;
}
/*
** Note:
** Giả sử sắp xếp mảng số nguyên trong khoảng 0..M
** Số giá trị 0 = C(0)
** Số giá trị 1 = C(1)
** Số giá trị ...
** Cho dãy cần sắp xếp: 1, 4, 2, 7, 8, 2, 1, 3, 8, 6, 2, 4
** Ta có: C(1) = 2, C(2) = 3, C(3) = 1, C(4) = 2, C(6) = 1, C(7) = 1, C(8) = 2
** Giá trị 1 đứng ở vị trí từ 1-> C(1). (tức là từ 1-> 2)
** Giá trị 2 đứng ở vị trí từ C(1) + 1 -> C(1) + C(2). (tức là từ 3-> 5)
** Tương tự giá trị i đứng ở vị trí cừ C(1) + C(2) + C(3) + .. + C(i-1) + 1 -> C(1) + C(2) + C(3) + .. + C(i-1) + C(i).
** Vậy dãy sau khi sắp xếp: 1 1 2 2 2 3 4 4 6 7 8 8
** Tham khảo: https://www.stdio.vn/articles/distribution-sort-counting-sort-474
*/