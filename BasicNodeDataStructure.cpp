//STT: 02
//Ho va ten: Huynh Phuong Nhu
//Buoi 03 - Bai 01
//Ghi chu
#include <iostream>
#include <time.h>
#include <stddef.h>
using namespace std;

struct NODE
{
    int info;
    NODE* pNext;
};
struct List
{
    NODE* pHead;
    NODE* pTail;
};
void CreateEmptyList(List& l)
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
void AddTail(List& l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void AddHead(List& l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void MannualInput(List& l)
{
    int n;
    cout << "Insert size: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tam;
        cout << "Insert info: ";
        cin >> tam;
        AddTail(l, CreateNode(tam));
    }
}
void AutoInput(List& l)
{
    srand(time(NULL));
    int n = 39 + rand() % 21;
    for (int i = 0; i < n; i++)
    {
        int tam = -99 + rand() % 199;
        AddTail(l, CreateNode(tam));
    }
}
void Print(List& l)
{
    for (NODE* p = l.pHead; p != NULL; p = p->pNext)
        cout << p->info << "\t";
    cout << endl;
}
void PrintInfoNAdd(List& l)
{
    for (NODE* p = l.pHead; p != NULL; p = p->pNext)
    {
        cout << p->info << "\t" << "<" << &(p->info) << "> pNext <" << &(p->pNext->info) << ">";
        cout << endl;
    }
}
int FindX(List& l, int& x)
{
    cout << "Enter X that need to find: ";
    cin >> x;
    for (NODE* p = l.pHead; p != NULL; p = p->pNext)
    {
        if (x == p->info)
            return 1;
    }
    return 0;
}
int RemoveHead(List& l,int& x)
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
int RemoveAfterQ(List& l, NODE* q,int& x)
{
    NODE* p;
    if (q != NULL)
    {
        p = q->pNext; //Dat ten cho node can xoa
        if (p != NULL) //p=NULL thi q la pTail
        {
            q->pNext = p->pNext; //NODE tiep theo cua p gio thanh NODE tiep theo cua q
            x = p->info; //Tra lai gia tri node da xoa
            if (p == l.pTail)
                l.pTail = q; //Neu NODE tiep theo q la NODE tail thi gio q la NODE tail sau khi xoa
            delete p;
        }
        return 1;
    }
    return 0;
}
int RemoveX(List& l, int& x)
{
    NODE* q = NULL;
    NODE* p = l.pHead;
    if (p != NULL && p->info != x) 
    {                              
        q = p;
        p = p->pNext;
    }
    if (p == NULL) //Neu p bang NULL la List rong
        return 0;
    if (q == NULL)
        RemoveHead(l, x);
    else
        RemoveAfterQ(l, q, x);
    return 1;
}
int Count(List l)
{
    int count = 0;
    for (NODE* i = l.pHead; i != NULL; i = i->pNext)
        count++;
    return count;
}
int UpdateNode(List& l)
{
    if (l.pHead == NULL)
        cout << "Danh sach chua duoc khoi tao!";
    int vt, x, dem = 0;
    cout << "Nhap vi tri cua phan tu can cap nhat: ";
    cin >> vt;
    while (vt > Count(l))
    {
        cout << "Nhap sai vi tri, vui long nhap lai: ";
        cin >> vt;
    }
    cout << "Nhap gia tri can cap nhat: ";
    cin >> x;
    for (NODE* i = l.pHead; i != NULL; i = i->pNext)
    {
        dem++;
        if (dem == vt)
        {
            i->info = x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    List m, a;
    CreateEmptyList(m);
    CreateEmptyList(a);
    NODE* p;
    int x;
    do {
        cout << "\n---------------MENU--------------";
        cout << "\n1. Cau #1.Nhap Danh Sach.\n2. Cau #2.Tao mot node.\n3. Cau #3.Them node vao cuoi danh sach.\n4. Cau #4.In DS ra man hinh.\n5. Cau #5.Tim kiem node\n6. Cau #6.Xoa node.\n7. Cau #7.Cap nhat node\n8. Xoa man hinh.";
        cout << "\n---------------END---------------" << "\nNhap lua chon: ";
        int tam;
        cin >> tam;
        switch (tam)
        {
        case 1:
            cout << "\t1.Nhap Ds thu cong.\n\t2.Nhap Ds tu dong.\n";
            cin >> tam;
            if (tam == 1)
            {
                MannualInput(m);
                cout << "Nhap thanh cong.\n";
            }
            else
            {
                if (tam == 2)
                {
                    AutoInput(a);
                    cout << "Nhap thanh cong.\n";
                }
                else
                    cout << "Khong co chuc nang nay.\n";
            }
            break;
        case 2:
            cout << "Insert Node Info: ";
            cin >> x;
            p = CreateNode(x);
            AddHead(m, p);
            cout << "Node da duoc them vao mang thu cong.\n";
            break;
        case 3:
            cout << "Insert Node Info: ";
            cin >> x;
            p = CreateNode(x);
            AddTail(m, p);
            cout << "Node da duoc them vao mang thu cong.\n";
            break;
        case 4:
            cout << "List duoc nhap bang tay: \t";
            Print(m);
            cout << "List nhap tu dong: \t";
            Print(a);
            break;
        case 5:
            int x;
            if (FindX(m, x) != 1)
                cout << "Khong tim thay x trong mang nhap tay" << endl;
            else
                cout << "Tim thay x trong mang nhap tay" << endl;
            if (FindX(a, x) != 1)
                cout << "Khong tim thay x trong mang tu dong" << endl;
            else
                cout << "Tim thay x trong mang tu dong" << endl;
        case 6:
            cout << "\t1.Xoa trong mang thu cong.\n\t2.Xoa trong mang tu dong.\n";
            cin >> tam;
            
            cout << "Nhap gia tri node muon xoa: ";
            cin >> x;
            if (tam == 1)
            {
                RemoveX(m, x);
                if (RemoveX(m, x) == 1)
                    cout << "Xoa thanh cong.\n";
                else
                    cout << "Xoa khong thanh cong.\n";
            }
            else
            {
                if (tam == 2)
                {
                    RemoveX(a, x);
                    if (RemoveX(a, x) == 1)
                        cout << "Xoa thanh cong.\n";
                    else
                        cout << "Xoa khong thanh cong.\n";
                }
                else
                    cout << "Khong co chuc nang nay.\n";
            }
            break;
        case 7:
            cout << "\t1.Cap nhat trong mang thu cong.\n\t2.Cap nhat trong mang tu dong.\n";
            cin >> tam;
            if (tam == 1)
            {
                UpdateNode(m);
                if (UpdateNode(m) == 1)
                    cout << "Cap nhat thanh cong.\n";
                else
                    cout << "Cap nhat khong thanh cong.\n";
            }
            else
            {
                if (tam == 2)
                {
                    UpdateNode(a);
                    if (UpdateNode(a) == 1)
                        cout << "Cap nhat thanh cong.\n";
                    else
                        cout << "Cap nhat khong thanh cong.\n";
                }
                else
                    cout << "Khong co chuc nang nay.\n";
            }
            break;
        case 8:
            std::system("cls");
            break;
        default:
            cout << "Nhap lai tu 1 den 8" << endl;
            break;
        }
    } while (1);
    return 0;
}
