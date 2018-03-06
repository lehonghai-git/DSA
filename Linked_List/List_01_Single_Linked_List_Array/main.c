#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/*
** Danh sách liên kết đơn cài đặt bằng mảng
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/


// Khai báo danh sách
typedef struct
{
	int arr[MAX];	// Mảng dữ liệu
	int size;		// Số phần tử của danh sách
} List;

// Khởi tạo danh sách rỗng: Không có phần tử nào
void initList(List *list)
{
	// Tham số là con trỏ để khi kết thúc hàm thì danh sách được cập nhập
	(*list).size = 0;
}

// Kiểm tra danh sách rỗng
int isEmpty(List list)
{
	return list.size == 0;
}

// Kiểm tra danh sách đầy
int isFull(List list)
{
	return list.size == MAX;
}

// Chèn phần tử vào vị trí k trong mảng
int initValue()
{
	int value;
	scanf("%d", &value);
	return value;
}

int insertValue(List *list, int vt, int value)
{
	// Kiểm tra danh sách đã full chưa
	if (isFull(*list))
	{
		printf("Danh sach da day!\n");
		return 0;
	}

	// Kiểm tra vị trí chèn có hợp lệ?
	if (vt < 0 || vt >(*list).size)
	{
		printf("Vi tri chen khong hop le!\n");
		return 0;
	}

	printf("Nhap mot so: ");
	value = initValue();

	for (int i = (*list).size; i > vt; i--)
		(*list).arr[i] = (*list).arr[i - 1];
	(*list).arr[vt] = value;
	(*list).size++;
	return 1;
}

// Nhập danh sách
void input(List *list)
{
	int n;
	do
	{
		printf("Nhap so phan tu cua danh sach: ");
		scanf("%d", &n);
	} while (n < 0 || n > MAX);

	(*list).size = n;

	for (int i = 0; i < (*list).size; i++)
	{
		printf("Nhap phan tu thu %d: ", i);
		(*list).arr[i] = initValue();
	}
}

// Xuất danh sách
void output(List list)
{
	printf("\nDanh sach: \n");
	for (int i = 0; i < list.size; i++)
		printf("%d   ", list.arr[i]);
	printf("\n");
}

// Tìm phần tử trong danh sách
int search(List list, int value)
{
	for (int i = 0; i < list.size; i++)
	{
		if (list.arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

// Xóa phần tử trong danh sách
int remove(List *list, int vt, int *value)
{
	if (isEmpty(*list))
	{
		printf("Danh sach rong!\n");
		return 0;
	}

	if (vt < 0 || vt >(*list).size)
	{
		printf("Vi tri xoa khong hop le!\n");
		return 0;
	}
	*value = (*list).arr[vt];

	for (int i = vt; i < (*list).size; i++)
		(*list).arr[i] = (*list).arr[i + 1];
	(*list).size--;
	return 1;
}

// Xóa phần tử có nội dung = value trong danh sách
int removeValue(List *list, int value)
{
	if (isEmpty(*list))
	{
		printf("Danh sach rong!\n");
		return 0;
	}
	int vt = search(*list, value);
	if (vt == -1)
	{
		printf("Khong tim thay %d trong danh sach!\n", value);
		return 0;
	}
	else
	{
		do
		{
			remove(list, vt, &value);
			vt = search(*list, value);
		} while (vt != -1);
		return 1;
	}
}

void menu()
{
	printf("Moi ban chon:");
	printf("\n1: Kiem tra danh sach rong");
	printf("\n2: Do dai danh sach");
	printf("\n3: Chen phan tu x vao vi tri k trong danh sach");
	printf("\n4: Tim mot phan tu trong danh sach");
	printf("\n5: Xoa phan tu tai vi tri k");
	printf("\n6: Xoa phan tu x trong danh sach");
	printf("\n7: Thoat");
}

int main()
{
	List L;
	initList(&L);
	input(&L);
	output(L);

	int luachon;
	do
	{
		system("cls");
		menu();
		output(L);
		printf("Ban chon: ");
		scanf("%d", &luachon);

		switch (luachon)
		{
		case 1:
		{
			if (isEmpty(L))
				printf("Danh sach rong!\n");
			else
				printf("Danh sach khong rong!\n");
			getch();
			break;
		}
		case 2:
		{
			printf("Do dai danh sach: %d", L.size);
			getch();
			break;
		}
		case 3:
		{
			int value = 0, vt;
			printf("Nhap vi tri muon chen: ");
			scanf("%d", &vt);
			if (insertValue(&L, vt, value))
			{
				printf("Danh sach sau khi chen: \n");
				output(L);
			}
			getch();
			break;
		}
		case 4:
		{
			int value;
			printf("Nhap phan tu muon tim: ");
			scanf("%d", &value);

			int vt = search(L, value);
			if (vt != -1)
			{
				printf("Tim thay %d tai vi tri %d", value, vt);
			}
			else
			{
				printf("Khong tim thay %d trong danh sach!\n", value);
			}
			getch();
			break;
		}
		case 5:
		{
			int vt, value;
			printf("Nhap vi tri muon xoa: ");
			scanf("%d", &vt);
			if (remove(&L, vt, &value))
			{
				printf("Danh sach sau khi xoa: \n");
				output(L);
			}
			getch();
			break;
		}
		case 6:
		{
			int value;
			printf("Nhap phan tu muon xoa: ");
			scanf("%d", &value);
			if (removeValue(&L, value))
			{
				printf("Danh sach sau khi xoa: \n");
				output(L);
			}
			getch();
			break;
		}
		case 7: break;
		}

	} while (luachon != 7);

	getch();
	return 0;
}

/*
** Note:
** Tham khảo: https://cachhoc.net/2014/12/20/lap-trinh-c-bai-12-danh-sach-lien-ket-cai-bang-mang/
*/