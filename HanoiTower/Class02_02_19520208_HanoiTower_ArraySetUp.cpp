// Class02_02_19520208_HanoiTower_ArraySetUp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int MAX = 100;
struct Stack
{
	int a[MAX];
	int t;
};
void CreateStack(Stack& s)
{
	s.t = -1;
}
bool isEmpty(Stack& s)
{
	if (s.t == -1)
		return 1;
	return 0;
}
bool isFull(Stack& s)
{
	if (s.t >= MAX)
		return 1;
	return 0;
}
bool Pop(Stack& s, int& x)//Luu tru lai gia tri top bi lay
{
	if (isEmpty(s) != 1)
	{
		x = s.a[s.t--];
		return 1;
	}
	return 0;
}
bool Push(Stack& s, int x)
{
	if (isFull(s) != 1)
	{
		s.a[++s.t] = x;
		return 1;
	}
	return 0;
}
void CreateAllStack(Stack& a, Stack& b, Stack& c)
{
	CreateStack(a);
	CreateStack(b);
	CreateStack(c);
}
void OutputStack(Stack& s)
{
	cout << "<\t";
	for (int i = 0; i <= s.t; i++)
	{
		cout << s.a[i] << "\t";
	}
	cout << ">\n=========================================\n";
}
bool CheckTop(Stack s, Stack l)
{
	int t1 = isEmpty(s);
	int t2 = isEmpty(l);
	if (t1 == 1 && t2 == 1)
		return 0;
	else
	{
		if (t2 == 1)
			return 1;
		if (s.a[s.t] < l.a[s.t])
			return 1;
		return 0;
	}
}
int main()
{
	Stack a, b, c;
	CreateAllStack(a, b, c);
	do {
		cout << "\n\n============= Hanoi Tower ===============\n";
		cout << "\t0.\tCreating Tower\n";
		cout << "\t1.\tA\t->\tB\n";
		cout << "\t2.\tB\t->\tA\n";
		cout << "\t3.\tB\t->\tC\n";
		cout << "\t4.\tC\t->\tB\n";
		cout << "\t5.\tC\t->\tA\n";
		cout << "\t6.\tA\t->\tC\n";
		cout << "=========================================\n";
		cout << "TOWER A\n";
		OutputStack(a);
		cout << "TOWER B\n";
		OutputStack(b);
		cout << "TOWER C\n";
		OutputStack(c);
		cout << "\tPlease Input: ";
		int t;
		cin >> t;
		int k = 0;
		int x = 0;
		switch (t)
		{
		case 0:
			cout << "Enter number of floor: ";
			cin >> t;
			for (int i = t; i >= 1; i--)
			{
				a.a[k] = i;
				k++;
			}
			a.t = t - 1;
			break;
		case 1:
			if (CheckTop(a, b) == 1)
			{
				Pop(a, x);
				Push(b, x);
			}
			else
				cout << "Can not move this floor / Do not have available floor to move\n";
			break;
		case 2:
			if (CheckTop(b, a) == 1)
			{
				Pop(b, x);
				Push(a, x);
			}
			else
				cout << "Can not move this floor / Do not have available floor to move\n";
			break;
		case 3:
			if (CheckTop(b, c) == 1)
			{
				Pop(b, x);
				Push(c, x);
			}
			else
				cout << "Can not move this floor / Do not have available floor to move\n";
			break;
		case 4:
			if (CheckTop(c, b) == 1)
			{
				Pop(c, x);
				Push(b, x);
			}
			else
				cout << "Can not move this floor / Do not have available floor to move\n";
			break;
		case 5:
			if (CheckTop(c, a) == 1)
			{
				Pop(c, x);
				Push(a, x);
			}
			else
				cout << "Can not move this floor / Do not have available floor to move\n";
			break;
		case 6:
			if (CheckTop(a, c) == 1)
			{
				Pop(a, x);
				Push(c, x);
			}
			else
				cout << "Can not move this floor / Do not have available floor to move\n";
			break;
		}
	} while (1);
}