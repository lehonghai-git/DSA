#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp theo độ dài giảm dần (Shell Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void shellSort(int array[], int length)
{
	int gap, i, j;

	for (gap = length / 2; gap > 0; gap = gap / 2)
	{
		for (i = 0; i < length; i = i + gap)
		{
			int tmp = array[i];
			for (j = i; j > 0 && array[j - gap] > tmp; j = j - gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
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
	shellSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	getch();
	return 0;
}
/*
** Note:
** Là giải thuật cải tiến từ Insertion sort
** Phân chia dãy ban đầu thành những dãy con mà mỗi phần tử của dãy cách nhau một 1 ví trí h
** Insertion sort áp dụng sau đó trên mỗi dãy con sẽ làm cho các phần tử đc đưa về vị trí đúng tương đối (trong dãy con)
** Sau đó giảm khoảng cách h để tạo các dãy con mới
** Giải thuật dừng khi h = 1. Đảm bảo các phần tử trong dãy ban đầu sẽ được so sánh với nhau để xác định trật tự cuối cùng
*/