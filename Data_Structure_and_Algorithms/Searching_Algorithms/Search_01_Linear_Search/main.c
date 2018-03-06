#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Tìm kiếm tuyến tính hay Tìm kiếm tuần tự
** Input	: Mảng một chiều, số phần tử mảng, giá trị muốn tìm
** Output	: Vị trí phần tử tìm thấy trong mảng
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

int linearSearch(int array[], int length, int value)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == value)
		{
			return i;
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

	// Searching
	int value;
	printf("\nNhap gia tri muon tim kiem: ");
	scanf("%d", &value);
	int viTri = linearSearch(array, length, value);
	if (viTri != -1)
	{
		printf("Tim thay %d tai vi tri %d trong mang\n", value, viTri);
	}
	else
	{
		printf("Khong tim thay %d trong mang\n", value);
	}

	getch();
	return 0;
}