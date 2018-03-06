#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp đổi chỗ trực tiếp (Interchange Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void interchangeSort(int array[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (array[i] > array[j])
			{
				// Swap
				int tmpValue = array[i];
				array[i] = array[j];
				array[j] = tmpValue;
			}
		}
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
	interchangeSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	//system("pause"); // C++
	getch();
	return 0;
}