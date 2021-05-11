#include <iostream>
# define M 10
using namespace std;
struct Node
{
	Node* next;
	int key;
};

struct List
{
	Node* head;
	Node* tail;
};

void CreateEmptyList(List& l)
{
	l.head = l.tail = NULL;
}

Node* CreateNode(int x)
{
	Node* p = new Node;
	if (p == NULL)
		exit(1);
	p->key = x;
	p->next = NULL;
	return p;
}

void AddTail(List& l, Node* p)
{
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void PrintList(List l)
{
	Node* p = l.head;
	while (p != NULL)
	{
		cout << p->key << "\t";
		p = p->next;
	}
	cout << endl;
}

int HashFunction(int x)
{
	return (x % M);
}

void InitBucket(List Bucket[M])
{
	for (int i = 0; i < M; i++)
	{
		CreateEmptyList(Bucket[i]);
	}
}

void Insert(List Bucket[M], int x)
{
	int pos = HashFunction(x); //Position
	Node* p = CreateNode(x);
	AddTail(Bucket[pos], p);
}

void Input(List Bucket[M])
{
	InitBucket(Bucket);
	for (int i = 0; i < M; i++)
	{
		int tam;
		cout << "Nhap gia tri: ";
		cin >> tam;
		Insert(Bucket, tam);
		cout << "Ban co muon tiep tuc nhap hay khong? (1/0) ";
		cin >> tam;
		if (tam == 0)
			break;
	}
}

bool CheckEmptyList(List l)
{
	if (l.head == NULL)
		return 1;
	return 0;
}


void ShowHashTable(List Bucket[M])
{
	for (int i = 0; i < M; i++)
	{
		cout << "[Bucket #" << i << "]: ";
		if (CheckEmptyList(Bucket[i]) == 1)
			cout << "NULL";
		PrintList(Bucket[i]);
		
	}
}

int Search(int& x, List Bucket[M])
{
	cout << "Enter x's value: ";
	cin >> x;
	int tam = HashFunction(x);
	Node* p = Bucket[tam].head;
	while (p != NULL)
	{
		if (p->key == x)
		{
			cout << p << endl;
			return 1;
		}
		p = p->next;
	}
	cout << endl;
	return 0;
}

bool IsBucketEmpty(List Bucket[M])
{
	for (int i = 0; i < M; i++)
	{
		if (CheckEmptyList(Bucket[i])==0)
			return 0;
	}
	return 1;
}

int main()
{
	int x;
	List Bucket[M];
	Input(Bucket);
	ShowHashTable(Bucket);
	Search(x, Bucket);
	cout << "\n---------------------MENU---------------------\n";
	cout << "0.Testing\n";
	cout << "1.Insert automatically (chaining)\n";
	cout << "2.Insert from keyboard\n";
	cout << "3.Show / printing\n";
	cout << "4.Search\n";
	cout << "5.Delete\n";
	cout << "6.Checking empty\n";
	cout << "---------------------END----------------------\n";
	return 0;
}
