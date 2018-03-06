#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*
** Hàng đợi cài đặt bằng mảng
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

// Khai báo cấu trúc hàng đợi
struct Queue
{
	int first, last;
	int data[MAX];
	int count;
};

// Khởi tạo hàng đợi rỗng
void initQueue(Queue &Q)
{
	Q.count = 0;
	Q.first = 0;
	Q.last = -1;
}

// Kiểm tra rỗng
int isEmpty(Queue Q)
{
	return Q.count == 0;
}

// Kiểm tra đầy
int isFull(Queue Q)
{
	return Q.count == MAX;
}

// Thêm phần tử vào cuối hàng đợi
void push(Queue &Q, int value)
{
	if (isFull(Q))
	{
		printf("Hang doi da day!\n");
	}
	else
	{
		Q.data[++Q.last] = value;
		Q.count++;
	}
}

// Xóa phần tử đầu hàng đợi
int pop(Queue &Q)
{
	if (isEmpty(Q))
	{
		printf("Hang doi rong!\n");
	}
	else
	{
		int value = Q.data[Q.first];
		// Dịch chuyển các phần tử về đầu
		for (int i = Q.first; i < Q.last; i++)
		{
			Q.data[i] = Q.data[i + 1];
		}
		Q.last--;
		Q.count--;
		return value;
	}
}

// Xem thông tin phần tử đầu hàng đợi
int QFirst(Queue Q)
{
	if (isEmpty(Q))
	{
		printf("Hang doi rong!\n");
	}
	else
	{
		return Q.data[Q.first];
	}
}

// input và output
void input(Queue &Q)
{
	int n, value;
	do
	{
		printf("Nhap so phan tu cua hang doi: ");
		scanf("%d", &n);
		if (n < 1 || n > MAX)
		{
			printf("So phan tu khong hop le!\n");
		}
	} while (n < 1 || n > MAX);

	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf("%d", &value);
		push(Q, value);
		//pushCircular(Q, value);
	}
}

void output(Queue Q)
{
	if (isEmpty(Q))
	{
		printf("Hang doi rong!\n");
	}
	else
	{
		for (int i = Q.first; i <= Q.last; i++)
		{
			printf("%d   ", Q.data[i]);
		}
		printf("\n");
	}
}

void menu()
{
	printf("Moi ban chon:");
	printf("\n1: Kiem tra Queue rong");
	printf("\n2: Kiem tra Queue day");
	printf("\n3: Them phan tu vao Queue");
	printf("\n4: Xoa phan tu trong Queue");
	printf("\n5: Thoat");
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
			if (isFull(Q))
			{
				printf("Hang doi day!\n");
			}
			else
			{
				printf("Hang doi khong day!\n");
			}
			system("pause");
			break;
		}
		case 3:
		{
			int value;
			printf("Nhap phan tu muon them vao Queue: ");
			scanf("%d", &value);
			push(Q, value);
			printf("Hang doi sau khi them vao: \n");
			output(Q);
			system("pause");
			break;
		}
		case 4:
		{
			if (!isEmpty(Q))
			{
				pop(Q);
			}
			printf("Hang doi sau khi lay ra: \n");
			output(Q);
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

/*
** Tham khảo: https://cachhoc.net/2014/12/30/lap-trinh-c-bai-16-xay-dung-hang-doi-queue/
*/