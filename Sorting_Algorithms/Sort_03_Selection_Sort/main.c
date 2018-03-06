#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp chọn (Selection Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void selectionSort(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		int x = i;
		// Tìm vị trí có phần tử min và gắn x vào vị trí đó
		for (int j = x; j < length; j++)
		{
			if (array[x] > array[j])
			{
				x = j;
			}
		}
		// Đổi chỗ cho phần tử min về đầu
		int tmpValue = array[i];
		array[i] = array[x];
		array[x] = tmpValue;
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
	selectionSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	getch();
	return 0;
}
/*
** Note:
** Duyệt hết danh sách, thấy phần tử nào nhỏ nhất thì vứt lên đầu danh sách
** Ta có một vị trí x
** Duyệt từ x->n, nếu tìm được phần tử nhỏ nhất thì đổi chỗ nó với x
*/