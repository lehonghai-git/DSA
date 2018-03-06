#include "NhapXuat.h"

void NhapMang(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Nhap arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}
void XuatMang(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d   ", arr[i]);
	printf("\n");
}
void NhapMangNgauNhien(int arr[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		arr[i] = 10 + rand() % (99 - 10 + 1);
}