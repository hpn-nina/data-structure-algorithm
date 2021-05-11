// Nhom01_BracketMatching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct NODE {
    char info;
    NODE* pNext;
};
struct LIST {
    NODE* pHead;
    NODE* pTail;
};
void CreateEmptyList(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
NODE* CreateNode(char x)
{
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    else
    {
        p->info = x;
        p->pNext = NULL;
    }
    return p;
}
bool IsEmpty(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}
void Push(LIST& s,NODE* p)
{
    if (s.pHead == NULL)
        s.pHead = s.pTail = p;
    else
    {
        p->pNext = s.pHead;
        s.pHead = p;
    }
}
void Pop(LIST& s, char& x)
{
    NODE* p;
    if (IsEmpty(s) == 0)
    {
        p = s.pHead;
        s.pHead = s.pHead->pNext;
        x = p->info;
        delete p;
    }
}
bool CheckBracketMatching(LIST& s)
{
    char string[200];
    char x;
    cout << "Insert string want to check bracket matching: ";
    fflush(stdin);
    gets_s(string, 200);
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == '(')
            Push(s, CreateNode('('));
        if (string[i] == ')')
        {
            if (IsEmpty(s) == 1)
                return 0;
            else
                Pop(s, x);
        }
    }
    if (IsEmpty(s) == 1)
        return 1;
    else
        return 0;
}
int main()
{
    LIST stack;
    CreateEmptyList(stack);
    if (CheckBracketMatching(stack) == 1)
        cout << "String valid";
    else
        cout << "String invalid";
    return 0;
}
