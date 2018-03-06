#include <iostream>
using namespace std;
#define MAX 10

/*
** Ngăn xếp cài đặt bằng mảng (array)
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

// Khai báo
struct Stack
{
	int top; // Đỉnh Stack
	int data[MAX];
};

// Khởi tạo danh sách rỗng
void initStack(Stack &S)
{
	S.top = 0;
}

// Kiểm tra danh sách rỗng
int isEmpty(Stack S)
{
	return S.top == 0;
}

// Kiểm tra Stack đầy
int isFull(Stack S)
{
	return S.top == MAX;
}

// Đẩy thêm phần tử vào đỉnh Stack
void push(Stack &S, int value)
{
	if (!isFull(S))
	{
		S.data[S.top] = value;
		S.top++;
	}
}

// Lấy dữ liệu từ đỉnh Stack (không xóa)
int peak(Stack S)
{
	return S.data[S.top - 1];
}

// Lấy dữ liệu từ đỉnh Stack (có xóa)
int pop(Stack &S)
{
	if (!isEmpty(S))
	{
		S.top--;
		return S.data[S.top];
	}
}

// input
void input(Stack &S)
{
	int n, value;
	do
	{
		printf("Nhap so phan tu cua Stack: ");
		scanf("%d", &n);
		if (n < 1 || n > MAX)
		{
			printf("Nhap lai so phan tu!\n");
		}
	} while (n < 1 || n > MAX);

	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &value);
		push(S, value);
	}

}

// output
void output(Stack S)
{
	for (int i = 0; i < S.top; i++)
	{
		printf("%d   ", S.data[i]);
	}
	printf("\n");
}

void menu()
{
	printf("Moi ban chon:");
	printf("\n1: Kiem tra Stack rong");
	printf("\n2: Kiem tra Stack day");
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
		printf("\nBan chon: ");
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
			if (isFull(S))
			{
				printf("Stack day!\n");
			}
			else
			{
				printf("Stack chua day!\n");
			}
			system("pause");
			break;
		}
		case 3:
		{
			int value;
			printf("Nhap phan tu muon them: ");
			scanf("%d", &value);
			push(S, value);
			printf("Stack sau khi them: \n");
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