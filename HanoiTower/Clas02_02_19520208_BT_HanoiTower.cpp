// Clas02_02_19520208_BT_HanoiTower.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <stdlib.h>
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
void CreateAllStack(Stack& a, Stack& b, Stack& c)
{
    a.pHead = a.pTail = NULL;
    b.pHead = b.pTail = NULL;
    c.pHead = c.pTail = NULL;
}
void OutputStack(Stack& s)
{
    cout << "STACK: <\t";
    for (NODE* p = s.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << "\t";
        if (p == s.pTail)
            break;
    }
    cout << ">\n========================================\n";
}
bool CreatingTower(Stack& s)
{
    cout << "\t\tInsert number of floor: ";
    int t;
    cin >> t;
    for (int i = t; i >= 1; i--)
        Push(s, i);
    return 1;
}
bool CheckTop(Stack& s, Stack& l)
{
    if (l.pHead == NULL && s.pHead==NULL)
        return 0;
    else
    {
        if (l.pHead == NULL)
            return 1;
        if (s.pHead == NULL)
            return 0;
        if (l.pHead->info > s.pHead->info)
            return 1;
        return 0;
    }
}
int main()
{
	Stack a, b, c;
    int x;
    CreateAllStack(a, b, c);
    do {
        system("cls");
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
        switch (t)
        {
        case 0:
            CreatingTower(a);
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
        default:
            cout << "\tEnter number from 0 to 6.\n";
            break;
        }
    } while (1);
	return 0;
}