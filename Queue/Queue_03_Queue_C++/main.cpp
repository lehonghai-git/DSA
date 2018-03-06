#include <iostream>
#include<queue>
using namespace std;

/*
** Hàng đợi cài đặt sẵn trong C++
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

typedef queue<int> Queue;

void menu()
{
	printf("Moi ban chon: ");
	printf("\n1: Kiem tra Queue rong");
	printf("\n2: Them phan tu vao Queue");
	printf("\n3: Xoa phan tu khoi Queue");
	printf("\n4: Thoat");
}

void input(Queue &Q)
{
	int value, i = 0;
	do
	{
		i++;
		cout << "Nhap phan tu thu " << i << " (Nhap 0 de thoat): ";
		cin >> value;
		if (value != 0)
		{
			Q.push(value);
		}
	} while (value != 0);
}

void output(Queue Q)
{
	while (!Q.empty())
	{
		int value = Q.front();
		cout << value << "   ";
		Q.pop();
	}
	cout << endl;
}


int main()
{
	Queue Q;
	input(Q);

	int luachon;

	do
	{
		system("cls");
		menu();
		cout << endl << "Queue hien tai: " << endl;
		output(Q);
		cout << endl << "Ban chon : ";
		cin >> luachon;

		switch (luachon)
		{
		case 1:
		{
			if (Q.empty())
			{
				cout << "Queue rong!" << endl;
			}
			else
			{
				cout << "Queue khong rong!" << endl;
			}
			system("pause");
			break;
		}
		case 2:
		{
			int value;
			cout << "Nhap phan tu muon them: ";
			cin >> value;
			Q.push(value);
			cout << "Queue sau khi them: " << endl;
			output(Q);
			system("pause");
			break;
		}
		case 3:
		{
			if (!Q.empty())
			{
				Q.pop();
				cout << "Queue sau khi xoa: " << endl;
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

}