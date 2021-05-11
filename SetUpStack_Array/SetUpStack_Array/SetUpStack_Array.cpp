// SetUpStack_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
bool Push(Stack& s, int& x)
{
	if (isFull(s) != 1)
	{
		s.a[++s.t] = x;
		return 1;
	}
	return 0;
}
int main()
{
	Stack s;
	int x;
	CreateStack(s);
	do {
		cout << "\n\n************Demo Stack************\n";
		cout << "\t1.Push\n";
		cout << "\t2.Pop\n";
		cout << "\t3.Top\n";
		cout << "\t4.Checking Empty\n";
		cout << "\t5.Checking Full\n";
		cout << "**********************************\n";
		cout << "STACK = < ";
		for (int i = s.t; i >= 0; i--)
		{
			cout << s.a[i] << " ";
		}
		cout << ">";
		cout << " \nTOP = " << s.t << "\t( " << s.t + 1 << " phan tu)\n";
		cout << "**********************************\n";
		cout << "\tPlease input: ";
		int t;
		cin >> t;
		switch (t)
		{
		case 1:
			cout << "\tInsert x to push into stack: ";
			cin >> x;
			if (Push(s, x) == 0)
				cout << "\t\tStack is full, can not insert more.\n";
			break;
		case 2:
			if (Pop(s, x) == 1)
				cout << "\t\tTop has been removed from stack is " << x << endl;
			else
				cout << "\t\tStack is empty, can not remove top.";
			break;
		case 3:
			cout << "\tTop is " << s.a[s.t] << endl;
			break;
		case 4:
			if (isEmpty(s) == 1)
				cout << "\t\tStack empty: 1\n";
			else
				cout << "\t\tStack not empty: 0\n";
			break;
		case 5:
			if (isFull(s) == 1)
				cout << "\t\tStack full: 1\n";
			else
				cout << "\t\tStack not full: 0\n";
			break;
		default:
			cout << "\tChoose from 1 to 5.\n";
			break;
		}
	} while (1);
	return 0;
}