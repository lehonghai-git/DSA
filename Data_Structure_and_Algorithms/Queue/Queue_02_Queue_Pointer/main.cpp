#include <stdio.h>
#include <stdlib.h>

/*
** Hàng đợi cài đặt bằng con trỏ
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

// Xây dựng cấu trúc
struct Node
{
	int data;
	Node *next;
};

struct Queue
{
	Node *front, *rear;
	int count;
};

// Khởi tạo
void initQueue(Queue &Q)
{
	Q.front = Q.rear = NULL;
	Q.count = 0;
}

// Kiểm tra rỗng
int isEmpty(Queue Q)
{
	return Q.count == 0;
}

// Tạo một node mới
Node *getNode(int value)
{
	Node *newNode = (Node*)malloc(1 * sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

// Thêm phần tử vào cuối queue
void push(Queue &Q, int value)
{
	Node *newNode = getNode(value);
	if (isEmpty(Q))
	{
		Q.front = Q.rear = newNode;
	}
	else
	{
		Q.rear->next = newNode;
		Q.rear = newNode;
	}
	Q.count++;
}

// Xóa phần tử dầu queue
int pop(Queue &Q)
{
	if (isEmpty(Q))
	{
		printf("Hang doi rong!\n");
		return 0;
	}
	else
	{
		int value = Q.front->data;
		if (Q.count == 1)
		{
			initQueue(Q);
		}
		else
		{
			Q.front = Q.front->next;
			Q.count--;
		}
		return value;
	}
}

// input và output
void input(Queue &Q)
{
	int i = 0;
	int value;
	do
	{
		i++;
		printf("Nhap phan tu thu %d (Nhap 0 de thoat): ", i);
		scanf("%d", &value);
		if (value != 0)
		{
			push(Q, value);
		}
	} while (value != 0);
}

void output(Queue Q)
{
	Node *node = Q.front;
	while (node != NULL)
	{
		printf("%d   ", node->data);
		node = node->next;
	}
	printf("\n");
}

void menu()
{
	printf("Moi ban chon: ");
	printf("\n1: Kiem tra Queue rong");
	printf("\n2: Them phan tu vao Queue");
	printf("\n3: Xoa phan tu trong Queue");
	printf("\n4: Thoat");
}


int main()
{
	Queue Q;
	initQueue(Q);
	input(Q);

	int luachon;

	do
	{
		system("cls");
		menu();
		printf("\nQueue hien tai: \n");
		output(Q);
		printf("\nBan chon: ");
		scanf("%d", &luachon);

		switch (luachon)
		{
		case 1:
		{
			if (isEmpty(Q))
			{
				printf("Hang doi rong!\n");
			}
			else
			{
				printf("Hang doi khong rong!\n");
			}
			system("pause");
			break;
		}
		case 2:
		{
			int value;
			printf("Nhap phan tu muon chen: ");
			scanf("%d", &value);
			push(Q, value);
			printf("Queue sau khi chen: \n");
			output(Q);
			system("pause");
			break;
		}
		case 3:
		{
			if (!isEmpty(Q))
			{
				pop(Q);
				printf("Queue sau khi xoa: \n");
				output(Q);
			}
			system("pause");
			break;
		}
		case 4:
		{
			break;
		}
		}

	} while (luachon != 4);


	system("pause");
	return 0;
}