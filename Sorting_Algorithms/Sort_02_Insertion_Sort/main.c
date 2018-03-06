#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp chèn (Insertion Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void insertionSort(int array[], int length)
{
	int x, tmpValue;
	for (int i = 1; i < length; i++)
	{
		x = i - 1;
		tmpValue = array[i];
		while (x >= 0 && array[x] > tmpValue)
		{
			array[x + 1] = array[x];
			x--;
		}
		array[x + 1] = tmpValue;
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
	insertionSort(array, length);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	getch();
	return 0;
}
/*
** Note:
** Chọn những phần tử nhỏ nhất để đưa lên đầu trong 1 dãy
** Ta có một ví trí là x.
**	+ Dãy từ 0 -> x-1	: là dãy sắp xếp 
**	+ Dãy từ x -> n		: là dãy chưa sắp xếp
** Nhiệm vụ:
** Duyệt dãy chưa sắp xếp (x->n). Thấy phần tử nào thì tìm vị trí phù hợp trong dãy sắp xếp (0->x-1) mà nhét vào
*/