// 02_19520208_HuynhPhuongNhu_Buoi03_Bai02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <string.h>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;
struct Data
{
    string NAME;
    float GPA;
};
struct NODE
{
    Data info;
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
NODE* CreateNode(Data x)
{
    NODE* p = new NODE;
    if (p == NULL)
        std::exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}
void Enter1Student(Data& SV)
{
    cout << "Insert Student's Name: ";
    cin.ignore();
    getline(cin, SV.NAME);
    cout << "Insert Student's GPA: ";
    cin >> SV.GPA;
}

void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    l.pTail->pNext = p;
    p = l.pTail;
}
void AddHead(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    p->pNext = l.pHead;
    l.pHead = p;
}
void EnterStudentList(LIST& l)
{
    int t;
    cout << "\t1.Nhap tu dong. \n\t2.Nhap thu cong.";
    cout << "\n\t\tChon chuc nang:";
    cin >> t;
    switch (t)
    {
    case 1:
    {
        srand(time(NULL));
        int t0 = rand() % 51;
        string ho[10] = { "Huynh ","Hoang ","Nguyen ","Bui ","Luong ","Tran ","Vuong ","Le ","To ","Ly " };
        string tenlot[10] = { "Thi ","Van ","Phuong ","Nhu ","Thanh ","Anh ","Hoang ","Quang ","Tuan ","Ngoc " };
        string ten[10] = { "Nhu","Tin","Dung","An","Phuc","Thanh","Minh","Tuyen","Tuan","Dang" };
        for (int i = 0; i < t0; i++)
        {
            int t1 = rand() % 10;
            int t2 = rand() % 10;
            int t3 = rand() % 10;
            Data t;
            t.NAME = ho[t1] + tenlot[t2] + ten[t3];
            t.GPA = float(rand() % 100) / 10;
            AddHead(l, CreateNode(t));
        }
        break;
    }
    case 2:
    {
        int t;
        cout << "Enter number of students: ";
        cin >> t;
        for (int i = 0; i < t; i++)
        {
            Data SV;
            Enter1Student(SV);
            AddHead(l, CreateNode(SV));
        }
        break;
    }
    default:
    {
        cout << "|NOTICE| WE DON'T HAVE THIS FUNCTION.";
        break;
    }
    }
}

void PrintStudentList(LIST l)
{
    cout << "Student List: " << endl;
    cout << "**************************************************" << endl;
    cout << "*" << setw(40) << left << "                     NAME" << "||" << setw(6) << " GPA" << "*" << endl;
    for (NODE* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << "*" << setw(5) << "     " << setw(35) << left << p->info.NAME << "|| " << setw(5) << p->info.GPA << "*" << endl;
        if (p == l.pTail)
            break;
    }
    cout << "**************************************************" << endl;
}
void SwapInfoNode(NODE* p, NODE* q)
{
    Data tam;
    tam = p->info;
    p->info = q->info;
    q->info = tam;
}
void SortByGPA(LIST& l)
{
    for (NODE* p = l.pHead; p != l.pTail && p != NULL; p = p->pNext)
        for (NODE* q = p->pNext; q != NULL; q = q->pNext)
        {
            if (p->info.GPA > q->info.GPA)
            {
                SwapInfoNode(p, q);
            }
            if (q == l.pTail)
                break;
        }
}
void FindStudent(LIST& l)
{
    int tam;
    cout << "\t1.Tim SV theo ten.\n\t2.Tim SV theo GPA.\n";
    cout << "\t\tChon chuc nang:";
    cin >> tam;
    switch (tam)
    {
    case 1:
    {
        char NAME[50];
        cout << "Insert student's name want to find: ";
        cin.ignore();
        cin.getline(NAME, 256);
        for (NODE* p = l.pHead; p != NULL; p = p->pNext)
        {
            if (p->info.NAME == NAME)
            {
                cout << "Student has been found" << endl;
                cout << "NAME: " << p->info.NAME << "\t" << "GPA: " << p->info.GPA << endl;
            }
            if (p == l.pTail)
                break;
        }
        cout << "Can't found any student related to your given info";
        break;
    }
    case 2:
    {
        float Grade;
        cout << "Insert student's grade want to find: ";
        cin >> Grade;
        for (NODE* p = l.pHead; p != NULL; p = p->pNext)
        {
            if (p->info.GPA == Grade)
            {
                cout << "Student has been found" << endl;
                cout <<"NAME: " << p->info.NAME << "\t" <<"GPA: " << p->info.GPA << endl;
            }
            if (p == l.pTail)
                break;
        }
        cout << "Can't found any more student related to your given info";
        break;
    }
    default:
    {
        cout << "|NOTICE| WE DON'T HAVE THIS FUNCTION.";
        break;
    }

    }
}

bool RemoveAfterQ(LIST& l, NODE* q)
{
    NODE* p;
    if (q != NULL)
    {
        p = q->pNext;
        if (p != NULL)
        {
            q->pNext = p->pNext;
            if (p == l.pTail)
                l.pTail = q;
            delete p;
        }
        return 1;
    }
    return 0;

}

bool RemoveHead(LIST& l)
{
    NODE* t;
    if (l.pHead != NULL)
    {
        t = l.pHead;
        l.pHead = l.pHead->pNext;
        delete t;
        if (l.pHead == NULL)
            l.pTail = NULL;
        return 1;
    }
    return 0;
}
void RemoveStudent(LIST& l)
{
    string t;
    cout << "Enter Student's Name to remove from list:  ";
    cin.ignore();
    getline(cin, t);
    NODE* q = NULL;
    for (NODE* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->info.NAME == t)
        {
            if (p != l.pHead)
            {
                RemoveAfterQ(l, q);
                cout << "Remove Successful.\n";
                break;
            }
            else
            {
                RemoveHead(l);
                cout << "Remove Successful.\n";
                break;
            }
        }
        else
        {
            q = p;
        }
        if (p == l.pTail)
            break;
    }
}
void UpdateStudentInfo(LIST& l)
{
    int tam;
    cout << "Insert Student's Name that you want to update info:";
    string s;
    cin.ignore();
    getline(cin, s);
    for (NODE* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (p->info.NAME == s)
        {
            cout << "\t Enter Student's new GPA want to update: ";
            cin >> tam;
            p->info.GPA = tam;
            cout << "\t Do you want to change student name too? (1/0): ";
            cin >> tam;
            if (tam == 1)
            {
                string tam;
                cout << "Enter Student's new name: ";
                cin.ignore();
                getline(cin, tam);
                p->info.NAME = tam;
            }
            else
            {
                if (tam == 0)
                {
                    break;
                }
                else
                {
                    cout << "WE DON'T HAVE THIS FUNCTION.\n";
                }
            }
            cout << "Update successful.\n";
        }
        if (p == l.pTail)
            break;
    }
}
int main()
{
    LIST SV;
    CreateEmptyList(SV);

    int k = 0;
    do
    {
        cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n------------###---MENU---###-----------";
        cout << "\n|1|. Cau 1: Nhap danh sach sinh vien.\n|2|. Cau 2: Sap xep danh sach sinh vien theo GPA.\n|3|. Cau 3: Tim kiem sinh vien theo ten & diem GPA.\n|4|. Cau 4: Xoa sinh vien trong danh sach.\n|5|. Cau 5: Cap nhat thong tin sinh vien.\n|6|. Cau 6: In danh sach sinh vien.\n|7|. Thoat chuong trinh.\n|8|. Xoa man hinh.";
        cout << "\n------------###---END---###-------------";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\tNhap lua chon: ";
        int a;
        cin >> a;
        int t;
        switch (a)
        {
        case 1:
            EnterStudentList(SV);
            k++;
            break;
        case 2:
            if (k > 0)
                SortByGPA(SV);
            else
            {
                cout << "\t YOU DON'T HAVE A STUDENT LIST, ENTER ONE.\n";
                EnterStudentList(SV);
                k++;
                SortByGPA(SV);
            }
            break;
        case 3:
            if (k > 0)
                FindStudent(SV);
            else
            {
                cout << "\t YOU DON'T HAVE A STUDENT LIST, ENTER ONE.\n";
                EnterStudentList(SV);
                k++;
                FindStudent(SV);
            }
            break;
        case 4:
            if (k > 0)
                RemoveStudent(SV);
            else
            {
                cout << "\t YOU DON'T HAVE A STUDENT LIST, ENTER ONE.\n";
                EnterStudentList(SV);
                k++;
                RemoveStudent(SV);
            }
            break;
        case 5:
            if (k > 0)
                UpdateStudentInfo(SV);
            else
            {
                cout << "\t YOU DON'T HAVE A STUDENT LIST, ENTER ONE.\n";
                EnterStudentList(SV);
                k++;
                UpdateStudentInfo(SV);
            }
            break;
        case 6:
            if (k > 0)
                PrintStudentList(SV);
            else
            {
                cout << "\t YOU DON'T HAVE A STUDENT LIST, ENTER ONE.\n";
                EnterStudentList(SV);
                k++;
                PrintStudentList(SV);
            }
            break;
        case 7:
            cout << "|NOTICE| EXIT.";
            std::exit(0);
            break;
        case 8:
            cout << "Cleansing Screen.";
            std::system("cls");
            break;
        default:
            cout << "|NOTICE| WE DON'T HAVE THIS FUNCTION. PLS CHOOSE FROM 1 TO 8. THANK YOU.";
            break;
        }
    } while (1);
    return 0;
}