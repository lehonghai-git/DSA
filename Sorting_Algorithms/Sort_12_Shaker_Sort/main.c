#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp Shaker (Shaker Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void shakerSort(int array[], int length)
{
	int Left = 0;
	int Right = length - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (array[i] < array[i - 1])
			{
				swap(&array[i], &array[i - 1]);
				k = i;
			}
		}
		Left = k;
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
	shakerSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	getch();
	return 0;
}
/*
** Note:
** Shaker Sort là một cải tiến của Bubble Sort.
** Sau khi đưa phần tử nhỏ nhất về đầu dãy, thuật toán
** sẽ giúp chúng ta đưa phần tử lớn nhất về cuối dãy.
** Do đưa các phần tử về đúng vị trí ở cả hai đầu nên
** Shaker Sort sẽ giúp cải thiện thời gian sắp xếp dãy số.
** Tham khảo: https://www.stdio.vn/articles/bubble-sort-va-shaker-sort-117
*/