#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp Radix (Distribution Sort - Radix Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void radixSort(int array[], int length)
{
	int b[MAX], m = array[0], exp = 1;
	for (int i = 0; i < length; i++)
	{
		if (array[i] > m)
		{
			m = array[i];
		}
	}

	while (m / exp > 0)
	{
		int bucket[10] = { 0 };
		for (int i = 0; i < length; i++)
			bucket[array[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = length - 1; i >= 0; i--)
			b[--bucket[array[i] / exp % 10]] = array[i];
		for (int i = 0; i < length; i++)
			array[i] = b[i];
		exp *= 10;
	}
}

int main()
{
	int array[MAX], length;
	do
	{
		printf("Nhap so luong phan tu: ");
		scanf("%d", &length);
		if (length <= 0 || length > 100)
			printf("Nhap lai so luong\n");
	} while (length <= 0 || length > MAX);
	NhapMangNgauNhien(array, length);
	printf("\nMang vua nhap:\n");
	XuatMang(array, length);

	// Sorting
	radixSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	getch();
	return 0;
}
/*
** Note:
**
** Tham khảo: https://www.stdio.vn/articles/distribution-sort-radix-sort-476
*/