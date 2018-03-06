#include <iostream>
#include <stdlib.h>
using namespace std;

/*
** Danh sách liên kết đơn cài đặt bằng con trỏ
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

// Xây dựng một Nút trong danh sách
typedef struct Node
{
	int data;
	Node *next;
};

// Định nghĩa một danh sách có kiểu Node
typedef Node *List;

// Khởi tạo danh sách rỗng: C++ cho phép truyền kiểu tham chiếu thay cho truyền kiểu con trỏ của C
void initList(List &list)
{
	list = NULL;
}

// Kiểm tra danh sách có rỗng hay không
int isEmpty(List list)
{
	return list == NULL;
}

// Tính độ dài danh sách
int lengthList(List list)
{
	// Dùng một biến kiểu Node để duyệt toàn bộ danh sách, mỗi lần duyệt tăng biến đếm
	Node *pNode = list;
	int dem = 0;
	while (pNode != NULL)
	{
		dem++;
		pNode = pNode->next; // Trỏ đến Node kế
	}
	return dem;
}

// Tạo một Node trong danh sách, trả về node có value được truyền vào
Node * getNode(Node *node, int value)
{
	// Cấp phát động một Node mới
	node = (Node *)malloc(1 * sizeof(node));
	// Node mới chưa trỏ vào đâu cả
	node->next = NULL;
	// Gán dữ liệu cho node
	node->data = value;
	// Trả về con trỏ trỏ đến Node đã cấp phát
	return node;
}

// Chèn một node vào đầu danh sách
void insertHead(List &L, int value)
{
	// Tạo Node muốn chèn
	Node *node = NULL;
	node = getNode(node, value);
	/*
	`** Ban đầu Node mới tạo trỏ NULL
	** B1: Cho Node mới trỏ vào L
	** B2: Cho L trỏ lại Node mới
	*/
	node->next = L;
	L = node;
}

// Chèn một node vào vị trí bất kỳ trong danh sách
void insertNode(List &L, int vt, int value)
{
	if (vt < 1 || vt > lengthList(L) + 1)
	{
		printf("Vi tri chen khong hop le!\n");
	}
	else
	{
		Node *newNode = NULL;
		newNode = getNode(newNode, value);
		if (vt == 1)
		{
			// Chèn vào đầu danh sách
			insertHead(L, value);
		}
		else
		{
			Node *Q = L;
			int i = 1;
			while (Q != NULL && i != vt - 1) // Duyệt đến vị trí = vt - 1
			{
				i++;
				Q = Q->next;
			}
			newNode->next = Q->next;
			Q->next = newNode;
		}
	}

}

// Tìm node có value nào đó trong danh sách
int searchNode(List L, int value)
{
	Node *tmpNode = L;
	int i = 1;
	while (tmpNode != NULL && tmpNode->data != value)
	{
		tmpNode = tmpNode->next;
		i++;
	}
	if (tmpNode != NULL)
	{
		return i;
	}
	else
	{
		return 0;
	}
}

// Xóa node đầu danh sách
void removeHead(List &L)
{
	L = L->next; // Trỏ đến node thứ 2
}

// Xóa node ở vị trí bất kỳ
void removeNode(List &L, int vt)
{
	if (vt < 1 || vt > lengthList(L))
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
			Node *node = L;
			int i = 1;
			while (node != NULL && i != vt - 1)
			{
				node = node->next;
				i++;
			}
			//cho P tro sang Node ke tiep vi tri vt
			node->next = node->next->next;
		}
	}
}

// Xóa node theo giá trị nào đó
void removeValue(List &L, int value)
{
	while (searchNode(L, value))
	{
		removeNode(L, searchNode(L, value));
	}
}

// Nhập danh sách
void input(List &L)
{
	int i = 0;
	int value;
	do
	{
		i++;
		printf("Nhap phan tu thu %d (Nhap 0 de thoi nhap): ", i);
		scanf("%d", &value);
		// Chèn vào cuối
		if (value != 0)
		{
			insertNode(L, lengthList(L) + 1, value);
		}
	} while (value != 0); // Nhap 0 de ket thuc
}

// Xuất danh sách
void output(List L)
{
	Node *node = L;
	while (node != NULL)
	{
		printf("%d   ", node->data);
		node = node->next;
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
	menu();
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
			printf("Do dai danh sach: %d\n", lengthList(L));
			system("pause");
			break;
		}

		case 3:
		{
			int value;
			int vt;
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
** Tham khảo: https://cachhoc.net/2014/12/21/lap-trinh-c-bai-13-danh-sach-lien-ket-don-cai-bang-con-tro/
*/