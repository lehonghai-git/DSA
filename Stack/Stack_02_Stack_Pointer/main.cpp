#include <iostream>
using namespace std;

/*
** Ngăn xếp cài đặt bằng con trỏ (pointer)
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

// Khai báo một node
struct Node
{
	int data;
	Node *next;
};

// Khai báo Stack
typedef struct Stack
{
	// Là các Node
	Node *top;
};

// Khởi tạo Stack (Danh sách rỗng)
void initStack(Stack &S)
{
	S.top = NULL;
}

// Kiểm tra Stack rỗng
int isEmpty(Stack S)
{
	return S.top == NULL;
}

// Tính độ dài Stack (Danh sách)
int lengthStack(Stack S)
{
	Node *node = S.top;
	int i = 0;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return i;
}

// Tạo một node
Node * getNode(int value)
{
	Node *node = (Node*)malloc(1 * sizeof(Node));
	node->data = value;
	node->next = NULL;
	return node;
}

// Chèn phần tử vào đỉnh stack
void push(Stack &S, int value)
{
	/*
	** B1: Cho node trỏ vào top
	** B2: Cho top trỏ lại vào node
	*/
	Node *newNode = getNode(value);
	newNode->next = S.top;
	S.top = newNode;
}

// Lấy dữ liệu từ đỉnh stack (không xóa)
int peak(Stack S)
{
	return S.top->data;
}

// Lấy dữ liệu từ đỉnh stack (có xóa)
int pop(Stack &S)
{
	if (!isEmpty(S))
	{
		int value = S.top->data;
		S.top = S.top->next;
		return value;
	}
}

// input
void input(Stack &S)
{
	int i = 0, value;
	do
	{
		i++;
		printf("Nhap phan tu thu %d (Nhap 0 de thoat): ", i);
		scanf("%d", &value);
		if (value != 0)
		{
			push(S, value);
		}
	} while (value != 0);
}

// output
void output(Stack S)
{
	Node *node = S.top;
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
	printf("\n1: Kiem tra Stack rong");
	printf("\n2: Do dai Stack");
	printf("\n3: Them phan tu vao Stack");
	printf("\n4: Xoa phan tu trong Stack");
	printf("\n5: Thoat");
}

int main()
{
	Stack S;
	initStack(S);
	input(S);

	int luachon;
	do
	{
		system("cls");
		menu();
		printf("\nStack hien tai: \n");
		output(S);
		printf("\Ban chon: ");
		scanf("%d", &luachon);

		switch (luachon)
		{
		case 1:
		{
			if (isEmpty(S))
			{
				printf("Stack rong!\n");
			}
			else
			{
				printf("Stack khong rong!\n");
			}
			system("pause");
			break;
		}
		case 2:
		{
			printf("Do dai Stack: %d\n", lengthStack(S));
			system("pause");
			break;
		}
		case 3:
		{
			int value;
			printf("Nhap phan tu muon chen: ");
			scanf("%d", &value);
			push(S, value);
			printf("Stack sau khi chen: \n");
			output(S);
			system("pause");
			break;
		}
		case 4:
		{
			pop(S);
			system("pause");
			break;
		}
		case 5:
		{
			break;
		}
		}
	} while (luachon != 5);

	system("pause");
	return 0;
}