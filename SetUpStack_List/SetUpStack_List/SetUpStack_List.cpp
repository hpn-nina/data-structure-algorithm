// SetUpStack_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct NODE
{
    int info;
    NODE* pNext;
};
struct Stack
{
    NODE* pHead;
    NODE* pTail;
};
void CreateEmptyList(Stack& s)
{
    s.pHead = s.pTail = NULL;
}
bool isEmpty(Stack& s)
{
    if (s.pHead == NULL)
        return 1;
    return 0;
}
NODE* CreateNode(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}
bool Pop(Stack& s, int& x)
{
    if (isEmpty(s) == 0)
    {
        NODE* p = NULL;
        x = s.pHead->info;
        p = s.pHead;
        s.pHead = s.pHead->pNext;
        delete p;
        return 1;
    }
    return 0;
}
bool Push(Stack& s, int& x)
{
    NODE* p = CreateNode(x);
    if (isEmpty(s) == 1)
    {
        s.pHead = s.pTail = p;
        return 1;
    }
    else
    {
        p->pNext = s.pHead;
        s.pHead = p;
        return 1;
    }
}
int main()
{
	Stack s;
	int x;
	CreateEmptyList(s);
	do {
		cout << "\n\n************Demo Stack************\n";
		cout << "\t1.Push\n";
		cout << "\t2.Pop\n";
		cout << "\t3.Top\n";
		cout << "\t4.Checking Empty\n";
		cout << "\t5.Checking Full\n";
		cout << "**********************************\n";
		cout << "STACK = < ";
		for (NODE* p=s.pHead;p!=NULL;p=p->pNext)
		{
			cout << p->info << " ";
		}
		cout << ">\n";
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
			cout << s.pHead->info;
			break;
		case 4:
			if (isEmpty(s) == 1)
				cout << "\t\tStack empty: 1\n";
			else
				cout << "\t\tStack not empty: 0\n";
			break;
		case 5:
			/*if (isFull(s) == 1)
				cout << "\t\tStack full: 1\n";
			else
				cout << "\t\tStack not full: 0\n";*/
			break;
		default:
			cout << "\tChoose from 1 to 5.\n";
			break;
		}
	} while (1);
	return 0;
}
