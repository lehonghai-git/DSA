#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp nhanh (Quick Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void quickSort(int array[], int left, int right)
{
	int i = left;
	int j = right;
	// Chọn 1 phần tử trong mảng làm mốc, thường chọn luôn ở giữa
	int pivot = array[(left + right) / 2];

	do
	{
		// Tìm vị trí i, j cần swap
		while (array[i] < pivot && i < right)
		{
			i++; 
		}
		while (array[j] > pivot && j > left) 
		{ 
			j--; 
		}
		if (i <= j)
		{
			// Swap
			int tmpValue = array[i];
			array[i] = array[j];
			array[j] = tmpValue;
			i++;
			j--;
		}
	} while (i <= j);
	
	// Gọi đệ quy hai mảng con bên trái mốc và bên phải mốc
	if (left < j) 
	{ 
		quickSort(array, left, j); 
	}
	if (right > i) 
	{ 
		quickSort(array, i, right); 
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
	quickSort(array, 0, length - 1);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	//system("pause"); // C++
	getch();
	return 0;
}

/*
** Note:
** Quick sort chọn 1 phần tử trong mảng (tùy ý, thường ở giữa) làm mốc
** Đưa phần tử nhỏ hơn mốc vào danh sách con 1
** Đưa phần tử lớn hơn mốc vào danh sách con 2
** Cứ như vậy ta dùng đệ quy ở cả 2 danh sách con cho đến khi chỉ còn 1 phần tử
*/