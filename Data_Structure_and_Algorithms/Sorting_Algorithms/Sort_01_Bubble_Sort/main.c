#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp nổi bọt (Bubble Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void bubbleSort(int array[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = length - 1; j > i; j--)
		{
			if (array[j - 1] > array[j])
			{
				// Swap
				int tmpValue = array[j - 1];
				array[j - 1] = array[j];
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
	bubbleSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	getch();
	return 0;
}
/*
** Note: 
** Thuật toán sẽ so sánh từng cặp phần tử với nhau
** Rồi cho nó "trồi" về vị trí đầu tiên, tiếp túc với những phần tử tiếp theo
*/