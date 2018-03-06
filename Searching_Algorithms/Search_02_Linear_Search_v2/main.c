#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Tìm kiếm lính canh (Biến thể của LinearSearch bài trước)
** Input	: Mảng một chiều, số phần tử mảng, giá trị muốn tìm
** Output	: Vị trí phần tử tìm thấy trong mảng
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

int linearSearchV2(int array[], int length, int value)
{
	array[length] = value;
	for (int i = 0; ; i++)
	{
		if (array[i] == value)
		{
			return i;
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

	// Searching
	int value;
	printf("\nNhap gia tri muon tim kiem: ");
	scanf("%d", &value);
	int viTri = linearSearchV2(array, length, value);
	if (viTri != length)
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