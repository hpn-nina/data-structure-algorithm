// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct NODE
{
	int info;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void CreateEmptyList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
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
void AddTail(LIST& l, NODE* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
bool isEmpty(LIST& s)
{
	if (s.pHead == NULL)
		return 1;
	return 0;
}
void Push(LIST& s, NODE* p)
{
	if (s.pHead == NULL)
	{
		s.pHead = p;
		s.pTail = p;
	}
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
	}
}
bool Pop(LIST& s, int& x)
{
	NODE* p;
	if (isEmpty(s) != 1)
	{
		if (s.pHead != NULL)
		{
			p = s.pHead;
			x = p->info;
			s.pHead = s.pHead->pNext;
			if (s.pHead == NULL)
				s.pTail = NULL;
			return 1;
		}
	}
	return 0;
}
void InputList(LIST& l)
{
	int n;
	cout << "Nhap so node: ";
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int x;
		cout << "Nhap x: ";
		cin >> x;

		NODE* p = new NODE;
		p = CreateNode(x);
		AddTail(l, p);
	}

}

void PrintList(LIST l)
{
	cout << "Duyet list: ";
	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
		cout << p->info << " ";

	cout << endl;
}
void SortList(LIST& l)
{
	for (NODE* i = l.pHead; i != l.pTail; i = i->pNext)
		for (NODE* j = i->pNext; j != NULL; j = j->pNext)
			if (i->info > j->info)
				swap(i->info, j->info);
}
bool RemoveHead(LIST& l, int& x)
{
	NODE* p;
	if (l.pHead != NULL)
	{
		x = l.pHead->info;
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;

		delete p;
		return 1;
	}
	return 0;
}
bool RemoveAfterQ(LIST& l, NODE* Q, int& x)
{
	NODE* p;
	if (Q != NULL)
	{
		p = Q->pNext;
		if (p != NULL)
		{
			Q->pNext = p->pNext;
			x = p->info;
			if (p == l.pTail)
				l.pTail = Q;
			delete p;
		}
		return 1;
	}
	return 0;
}

bool RemoveX(LIST& l, int x)
{
	NODE* q, * p;
	q = NULL;
	p = l.pHead;

	while (p != NULL && p->info != x)
	{
		q = p;
		p = p->pNext;
	}

	if (p == NULL)
		return 0;
	if (q != NULL)
		RemoveAfterQ(l, q, x);
	else
		RemoveHead(l, x);
	return 1;
}
void Coso(int& x,LIST& s)
{
	int t;
	while (x > 0)
	{
		t = x % 2;
		NODE* p=CreateNode(t);
		Push(s, p);
		x /= 2;
	}
	for (NODE* p = s.pHead; p != NULL; p = p->pNext)
	{
		int k = 0;
		Pop(s, k);
		cout << k;
	}
	cout << endl;
	
}
int main()
{
	LIST l;
	int x;
	LIST stack;
	CreateEmptyList(stack);
	cout << "Nhap x can chuyen sang he nhi phan:";
	cin >> x;
	Coso(x, stack);
	return 0;
}

