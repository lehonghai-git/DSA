#include <iostream>
#include <stack>
using namespace std;

/*
** Ngăn xếp cài đặt sẵn trong C++
** IDE		: Visual Studio 2017
** Configuration Properties >> C/C++ >> Preporocessor >> Preprocessor Definitions >> Edit >> add "_CRT_SECURE_NO_WARNINGS"
*/

typedef stack<int> Stack;

void menu()
{
	cout << "Moi ban chon: " << endl;
	cout << "1: Kiem tra Stack rong" << endl;
	cout << "2: Do dai Stack" << endl;
	cout << "3: Push" << endl;
	cout << "4: Pop" << endl;
	cout << "5: Thoat" << endl;
}

void input(Stack &S)
{
	int value, i = 0;
	do
	{
		i++;
		cout << "Nhap phan tu thu " << i << " (Nhap 0 de thoat): ";
		cin >> value;
		if (value != 0)
		{
			S.push(value);
		}
	} while (value != 0);
}

void output(Stack S)
{
	while (!S.empty())
	{
		int value = S.top();
		S.pop();
		cout << value << "   ";
	}
	cout << endl;
}

int main()
{
	Stack S;
	input(S);
	int luachon;

	do
	{
		system("cls");
		menu();
		output(S);

		cout << endl << "Ban chon: ";
		cin >> luachon;
		switch (luachon)
		{
		case 1:
		{
			if (S.empty())
			{
				cout << "Stack rong!" << endl;
			}
			else
			{
				cout << "Stack khong rong!" << endl;
			}
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Do dai Stack: " << S.size() << endl;
			system("pause");
			break;
		}
		case 3:
		{
			int value;
			cout << "Nhap phan tu muon them: ";
			cin >> value;
			S.push(value);
			cout << "Stack sau khi them: " << endl;
			output(S);
			system("pause");
			break;
		}
		case 4:
		{
			if (!S.empty())
			{
				S.pop();
			}
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