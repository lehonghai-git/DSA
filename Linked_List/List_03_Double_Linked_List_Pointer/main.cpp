#include <iostream>
#include <stdlib.h>
using namespace std;

/*
** Danh sách liên kết kép cài đặt bằng con trỏ
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

// Khai báo cấu trúc của một node trong danh sách liên kết kép
typedef struct Node
{
	int data;
	Node *Left;
	Node *Right;
};

// Khai báo một danh sách
typedef struct List
{
	Node *Head;
	Node *Tail;
};

// khởi tạo danh sách
void initList(List &L)
{
	L.Head = NULL;
	L.Tail = NULL;
}

// Kiểm tra danh sách có rỗng không
int isEmpty(List L)
{
	return L.Head == NULL;
}

// Tính độ dài danh sách
int lengthList(List L)
{
	Node *nodeDau = L.Head;
	Node *nodeCuoi = L.Tail;
	int dem = 1;

	while (nodeDau != NULL)
	{
		if (nodeDau == nodeCuoi) break;

		nodeDau = nodeDau->Right;
		dem++;

		if (nodeDau == nodeCuoi) break;
		nodeCuoi = nodeCuoi->Left;
		dem++;
	}
	return dem;
}

// Tạo một node mới
Node *getNode(int value)
{
	Node *newNode = (Node *)malloc(1 * sizeof(Node));
	newNode->data = value;
	newNode->Left = NULL;
	newNode->Right = NULL;
	return newNode;
}

// Chèn một node vào đầu danh sách
void insertHead(List &L, int value)
{
	Node *node = NULL;
	node = getNode(value);
	if (isEmpty(L))
	{
		L.Head = node;
		L.Tail = node;
	}
	else
	{
		node->Right = L.Head;
		L.Head->Left = node;
		L.Head = node;
	}
}

// Chèn một node vào cuối danh sách
void insertTail(List &L, int value)
{
	Node *node = NULL;
	node = getNode(value);
	if (isEmpty(L))
	{
		L.Head = node;
		L.Tail = node;
	}
	else
	{
		L.Tail->Right = node; // kết nối với danh sách
		node->Left = L.Tail; // node trở về node trước
		L.Tail = node; // Lưu lại vị trí cuối
	}
}

// Chèn một node vào vị trí bất kỳ
void insertNode(List &L, int vt, int value)
{
	Node *PH = L.Head, *PT, *R;
	int i = 1, l = lengthList(L);
	if (vt < 1 || vt > l + 1)
	{
		printf("Vi tri chen khong hop le!\n");
	}
	else
	{
		R = getNode(value);
		if (vt == 1)
		{
			// Chèn vào đầu
			insertHead(L, value);
		}
		else
		{
			if (vt == l + 1)
			{
				// Chèn vào cuối
				insertTail(L, value);
			}
			else
			{
				while (PH != NULL && i != vt - 1)
				{
					i++;
					PH = PH->Right;
				}
				PT = PH->Right; // Xác định vị trí k
				R->Right = PT;
				R->Left = PH;
				PH->Right = R;
				PT->Left = R;
			}
		}
		
	}

}

// Xóa node đầu danh sách
void removeHead(List &L)
{
	if (!isEmpty(L))
	{
		L.Head = L.Head->Right; // Trỏ để node thứ 2 trong DS
	}
}

// Xóa node cuối danh sách
void removeTail(List &L)
{
	if (!isEmpty(L))
	{
		L.Tail = L.Tail->Left;
		L.Tail->Right = NULL;
	}
}

// Xóa node ở vị trí bất kỳ
void removeNode(List &L, int vt)
{
	Node *PH = L.Head, *PT;
	int i = 1, l = lengthList(L);
	if (vt < 1 || vt > l)
	{
		printf("Vi tri xoa khong hop le!\n");
	}
	else
	{
		if (vt == 1)
		{
			removeHead(L);
		}
		else
		{
			if (vt == l)
			{
				removeTail(L);
			}
			else
			{
				while (PH != NULL && i != vt - 1)
				{
					i++;
					PH = PH->Right;
				}
				PT = PH->Right->Right; // Xác định vị trí k + 1
				PH->Right = PT;
				PT->Left = PH;
			}
		}
	}
}

// Tìm một node theo giá trị nào đó
int searchNode(List L, int value)
{
	Node *P = L.Head;
	int i = 1;
	while (P != NULL && P->data != value)
	{
		P = P->Right;
		i++;
	}
	if (P != NULL)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

// Xóa node theo giá trị nào đó
void removeValue(List &L, int value)
{
	int vt = searchNode(L, value);
	
	while (vt)
	{
		removeNode(L, vt);
		vt = searchNode(L, value);
	}
}

//
void input(List &L)
{
	int i = 0;
	int value;
	do
	{
		i++;
		printf("Nhap phan tu thu %d (Nhap 0 de ket thuc): ", i);
		scanf("%d", &value);
		if (value != 0)
		{
			insertNode(L, lengthList(L) + 1, value);
		}
	} while (value != 0);
}
//
void output(List L)
{
	Node *P = L.Head;
	while (P != L.Tail->Right)
	{
		printf("%d   ", P->data);
		P = P->Right;
	}
	printf("\n");
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
	initList(L);
	input(L);

	int luachon;
	
	do
	{
		system("cls");
		menu();
		printf("\nDanh sach: \n");
		output(L);
		printf("\nBan chon: ");
		scanf("%d", &luachon);
		
		switch (luachon)
		{
		case 1:
		{
			if (isEmpty(L))
			{
				printf("Danh sach rong!\n");
			}
			else
			{
				printf("Danh sach khong rong!\n");
			}
			system("pause");
			break;
		}
		case 2:
		{
			printf("Do dai danh sach la: %d\n", lengthList(L));
			system("pause");
			break;
		}
		case 3:
		{
			int vt, value;
			printf("Nhap phan tu muon chen: ");
			scanf("%d", &value);
			printf("Nhap vi tri muon chen: ");
			scanf("%d", &vt);
			insertNode(L, vt, value);
			printf("Danh sach sau khi chen: \n");
			output(L);
			system("pause");
			break;
		}
		case 4:
		{
			int value;
			printf("Nhap phan tu muon tim: ");
			scanf("%d", &value);
			int vt = searchNode(L, value);
			if (vt)
			{
				printf("Tim thay %d tai vi tri %d\n", value, vt);
			}
			else
			{
				printf("Khong tim thay %d trong danh sach!\n", value);
			}
			system("pause");
			break;
		}
		case 5:
		{
			int vt;
			printf("Nhap vi tri muon xoa: ");
			scanf("%d", &vt);
			removeNode(L, vt);
			printf("Danh sach sau khi xoa: \n");
			output(L);
			system("pause");
			break;
		}
		case 6:
		{
			int value;
			printf("Nhap phan tu muon xoa: ");
			scanf("%d", &value);
			removeValue(L, value);
			printf("Danh sach sau khi xoa: \n");
			output(L);
			system("pause");
			break;
		}
		case 7:
		{
			break;
		}
		}

	} while (luachon != 7);
	system("pause");
	return 0;
}
/*
** Tham khảo: https://cachhoc.net/2014/12/21/lap-trinh-c-bai-14-danh-sach-lien-ket-kep/
*/