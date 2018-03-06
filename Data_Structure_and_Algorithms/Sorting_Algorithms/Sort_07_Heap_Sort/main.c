#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp vun đống (Heap Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

// Ta xem i là nút cha
void maxHeapify(int array[], int length, int i)
{
	int left = 2 * (i + 1) - 1;
	int right = 2 * (i + 1);
	int max;

	// Tìm nút cha lớn nhất
	if (left < length && array[left] > array[i])
	{
		max = left;
	}
	else
	{
		max = i;
	}

	if (right < length && array[right] > array[max])
	{
		max = right;
	}

	if (i != max)
	{
		// Swap
		int tmpValue = array[i];
		array[i] = array[max];
		array[max] = tmpValue;
		// Đệ quy với nút cha lần này là max
		maxHeapify(array, length, max);
	}
}

void buildHeap(int array[], int length)
{
	// Xây dựng heap chỉ lặp nửa so với dãy mảng
	// Do ta cần xây dựng cây nhị phân nên cần phải đi từ nhánh về gốc
	// Vì vậy mảng cần phải duyệt từ giữa (nút con) về đầu (nút gốc)
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		maxHeapify(array, length, i);
	}
}

void heapSort(int array[], int length)
{
	buildHeap(array, length);
	// array[0] lúc này max
	for (int i = length - 1; i > 0; i--)
	{
		// Swap
		int tmpValue = array[0];
		array[0] = array[i];
		array[i] = tmpValue;

		maxHeapify(array, i, 0);
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
	heapSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	getch();
	return 0;
}

/*
** Note:
** Sắp xếp vun đống dựa trên cây nhị phân
** Cây nhị phân xác định:
**	+ Nút con trái: 2*(i+1)-1
**	+ Nút con phải: 2*(i+1)
** Xây dựng heap sao cho nút cha đều lớn hơn 2 nút con. Khi đó nút gốc có giá trị lớn nhất
** Sau đó hoán vị nút gốc với nút thứ n-1 và xây dựng lại heap mới từ 0->(n-2) và nút cha lớn hơn 2 nút con
** Lặp lại việc xây dựng và hoán vụ nút gốc với nút cuối trong heap ta được mảng đã sort
**
*/