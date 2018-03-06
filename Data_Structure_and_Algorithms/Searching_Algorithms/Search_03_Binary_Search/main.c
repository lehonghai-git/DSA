#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Tìm kiếm nhị phân
** Input	: Mảng một chiều đã sắp xếp, số phần tử mảng, giá trị muốn tìm
** Output	: Vị trí phần tử tìm thấy trong mảng
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void sortArray(int array[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (array[i] > array[j])
			{
				// Swap value
				int tmpValue = array[i];
				array[i] = array[j];
				array[j] = tmpValue;
			}
		}
	}
}

int binarySearch(int array[], int length, int value)
{
	int leftIndex = 0;
	int rightIndex = length - 1;

	while (leftIndex <= rightIndex)
	{
		int midIndex = (leftIndex + rightIndex) / 2;
		if (value > array[midIndex])
		{
			leftIndex = midIndex + 1;
		}
		else if (value < array[midIndex])
		{
			rightIndex = midIndex - 1;
		}
		else
		{
			return midIndex;
		}
	}
	return -1;
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

	sortArray(array, length);
	printf("\nMang vua sap xep tang:\n");
	XuatMang(array, length);

	// Searching
	int value;
	printf("\nNhap gia tri muon tim kiem: ");
	scanf("%d", &value);
	
	int viTri = binarySearch(array, length, value);
	if (viTri != -1)
	{
		printf("Tim thay %d tai vi tri %d\n", value, viTri);
	}
	else
	{
		printf("Khong tim thay %d trong mang\n", value);
	}

	getch();
	return 0;
}