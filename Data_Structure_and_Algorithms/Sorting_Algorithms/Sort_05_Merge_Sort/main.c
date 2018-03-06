#include "NhapXuat.h"
#define MAX 100

/*
** Giải thuật Sắp xếp trộn (Merge Sort)
** Input	: Mảng một chiều, số phần tử mảng
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void merge(int array[], int left, int mid, int right)
{
	// Chia mảng lớn thành hai mảng con A, B
	// Mảng con A: Từ left đến mid
	// Mảng con B: Từ mid + 1 đến right
	int *tmpArray;
	int leftA = left;
	int leftB = mid + 1;

	//tmpArray = new int[right - left + 1]; // C++
	tmpArray = (int *)malloc((right - left + 1) * sizeof(int));

	for (int i = 0; i < right - left; i++)
	{
		if (array[leftA] < array[leftB])
		{
			// Copy phần tử mảng trái (A) vào mảng tạm
			tmpArray[i] = array[leftA];
			leftA++;
		}
		else
		{
			// Copy phần tử của mảng phải (B) vào mảng tạm
			tmpArray[i] = array[leftB];
			leftB++;
		}

		// Kiểm tra xem mảng con A bên trái còn phần tử nào không
		if (leftA == mid + 1)
		{
			while (leftB <= right)
			{
				i++;
				tmpArray[i] = array[leftB];
				leftB++;
			}
			break;
		}

		// Kiểm tra xem mảng con B bên phải còn phần tử nào không
		if (leftB == right + 1)
		{
			while (leftA <= mid)
			{
				i++;
				tmpArray[i] = array[leftA];
				leftA++;
			}
			break;
		}

	}

	// Chép mảng tạm vào mảng chính
	for (int i = 0; i <= right - left; i++)
	{
		array[left + i] = tmpArray[i];
	}

	// Giải phóng
	//delete tmpArray; // C++
	free(tmpArray);
}

void mergeSort(int array[], int left, int right)
{
	if (right > left)
	{
		int mid = (left + right) / 2;
		// Gọi đệ quy mảng con bên phải
		mergeSort(array, left, mid);
		// Gọi đệ quy mảng con bên trái
		mergeSort(array, mid + 1, right);
		merge(array, left, mid, right);

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
	mergeSort(array, 0, length - 1);
	printf("\nMang sau khi sap xep tang:\n");
	XuatMang(array, length);

	//system("pause"); // C++
	getch();
	return 0;
}

/*
** Note:
** Chia mảng lớn thành hai mảng con, đến một điều kiện cụ thể (thường chỉ còn 2 phần tử) rồi so sánh
** Sau đó gom từng mảng con lại thành mảng lớn để ra kết quả
** Giả sử ta có 2 mảng đã sort sẵn, A = { 1, 3, 6, 9 } và B = { 2, 4, 5 }.
** Ta muốn trộn chúng lại thành mảng AB thì ta cần so sánh các cặp vị trí đầu của 2 mảng, phần tử nào bé ta cho vào AB
** A = { 1, 3, 6, 9 }, B = { 2, 4, 5 }, 1 < 2 => AB = { 1 }
** A = { 3, 6, 9 }, B = { 2, 4, 5 }, 3 > 2 => AB = { 1, 2 }
** A = { 3, 6, 9 }, B = { 4, 5 }, 3 < 4 => AB = { 1, 2, 3 }
** A = { 6, 9 }, B = { 4, 5 }, 6 > 4 => AB = { 1, 2, 3, 4 }
** A = { 6, 9 }, B = { 5 }, 6 > 5 => AB = { 1, 2, 3, 4, 5 }
** A = { 6, 9 }, B = { }, B rỗng => nhét toàn bộ mảng A vào AB = { 1, 2, 3, 4, 5, 6, 9 }
*/