// 02_02_19520208_HuynhPhuongNhu_BT3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;

void AutoInput(int arrA[100], int& n)
{
    srand(time(NULL));
    n = 15 + rand() % 16;
    for (int i = 0; i < n; i++)
    {
        arrA[i] = 555 + rand() % 445;
    }
}
void AutoRaiseInput(int arrA[100], int& n)
{
    n = 1;
    srand(time(NULL));
    arrA[0] = 10 + rand() % 90;
    while (arrA[n-1] < 99)
    {
        int t = 99 - arrA[n - 1] + 1;
        arrA[n] = arrA[n - 1] + rand() % t;
        n++;
    }
}
void Print(int arrA[100], int n)
{
    for (int i = 0; i < n; i++)
        cout << arrA[i] << '\t';
    cout << endl;
}
void Swap(int& x, int& y)
{
    int tam = x;
    x = y;
    y = tam;
}
void SapXep(int arrA[100], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrA[i] > arrA[j])
                Swap(arrA[i], arrA[j]);
        }
    }
}
int FindX(int arrA[100], int n, int x)
{
    int l = 0, r = n - 1, m;
    while (l <= r)
    {
        m = l + (r - l) / 2;
        if (x == arrA[m])
            return m;
        if (x < arrA[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
int main()
{
    int n = -1,k = -1;
    int x;
    int arrA[100], arrB[100];
    do
    {
        int t;
        cout << "------------------MENU------------------------" << endl;
        cout << "1.Ham nhap tu dong arrA voi cac gia tri trong khoang [555;999]" << endl;
        cout << "2.Hap nhap tu dong arrB tang dan gia tri trong khoang [10;99]" << endl;
        cout << "3.In mang arrA ra man hinh" << endl;
        cout << "4.In mang arrB ra man hinh" << endl;
        cout << "5.Tim x trong mang arrB" << endl;
        cout << "6.Xoa man hinh" << endl;
        cout << "-------------------THE END------------------------" << endl;
        cout << "Chon chuc nang: ";
        cin >> t;
        switch(t)
        {
        case(1):
        {
            AutoInput(arrA, n);
            break;
        }
        case(2):
        {
            AutoRaiseInput(arrB, k);
            break;
        }
        case(3):
        {
            if(n!=-1)
                Print(arrA, n);
            else
            {
                AutoInput(arrA, n);
                Print(arrA, n);
            }
            break;
        }
        case(4):
        {
            if (k != -1)
                Print(arrB, k);
            else
            {
                AutoRaiseInput(arrB, k);
                Print(arrB, k);
            }
            break;
        }
        case(5):
        {
            if (k == -1)
            {
                AutoRaiseInput(arrB, k);
                cout << "Nhap x:";
                cin >> x;
                if (FindX(arrB, k, x) == -1)
                {
                    cout << "Khong tim thay x trong mang" << endl;
                }
                else
                    cout << "Vi tri cua x la: i = " << FindX(arrB, k, x) << endl;
            }
            else
            {
                cout << "Nhap x:";
                cin >> x;
                if (FindX(arrB, k, x) == -1)
                {
                    cout << "Khong tim thay x trong mang" << endl;
                }
                else
                    cout << "Vi tri cua x la: i = " << FindX(arrB, k, x) << endl;
            }
            break;
        }
        case(6):
        {
            system("cls");
            break;
        }
        default:
        {
            cout << "Nhap lai chuc nang tu 1 den 6." << endl;
            break;
        }
        }
    } while (1);
}
