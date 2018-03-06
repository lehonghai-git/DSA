#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100
using namespace std;

/*
** Giải thuật Sắp xếp Bucket (Distribution Sort - Bucket Sort)
** Input	: Mảng một chiều, số phần tử mảng, các phần tử nằm trong một đoạn nào đó
** Output	: Mảng được sắp xếp
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

void bucketSort(float arr[], int n)
{
	// 1) Create n empty buckets
	vector<float> b[MAX]; // Lớn hơn hoặc bằng với số lượng phần tử của mảng

	// 2) Put array elements in different buckets
	for (int i = 0; i<n; i++)
	{
		int bi = n * arr[i]; // Index in bucket
		b[bi].push_back(arr[i]);
	}

	// 3) Sort individual buckets
	for (int i = 0; i<n; i++)
		sort(b[i].begin(), b[i].end());

	// 4) Concatenate all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main()
{
	float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.1234, 0.3589, 0.7945 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Mang chua sap xep: \n";
	for (int i = 0; i<n; i++)
		cout << arr[i] << "   ";
	cout << endl;

	// Sorting
	bucketSort(arr, n);
	cout << "Mang sau khi sap xep: \n";
	for (int i = 0; i<n; i++)
		cout << arr[i] << "   ";
	cout << endl;

	system("pause");
	return 0;
}
/*
** Note:
** Đặt các phần tử của mảng vào các xô thích hợp
** Sắp xếp các phần tử trong xô theo thứ tự
** Liên kết các xô lại trở thành dãy các phần tử được sort theo thứ tự
*/