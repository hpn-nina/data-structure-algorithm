// Class02_02_19520208_HuynhPhuongNhu_BT5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;
long double FiboAtX(int x)
{
    int FN, F1, F2;
    FN = F1 = F2 = 1;
    for (int i = 3; i <= x; i++)
    {
        FN = F1 + F2;
        F1 = F2;
        F2 = FN;
    }
    return FN;
}
void Finaci(long double fibo[100], int& n)
{
    srand(time(NULL));
    n = 10 + rand() % 41;
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibo[i] = FiboAtX(i + 1);
    }
}
void PrintFinaci(long double fibo[100], int n)
{
    cout << "Day fibonacci: " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << fibo[i] << "\t";
    }
    cout << endl;
}
int main()
{
    long double fibo[100];
    int n = -1;
    int x;
    do {
        int t;
        cout << "------------------MENU------------------------" << endl;
        cout << "1.Ham nhap tu dong day Fibonacci "<< endl;
        cout << "2.Xuat day duoc nhap tu dong" << endl;
        cout << "3.Xuat so Fibo o vi tri x " << endl;
        cout << "4.Xoa man hinh" << endl;
        cout << "-------------------THE END------------------------" << endl;
        cout << "Chon chuc nang: ";
        cin >> t;
        switch (t)
        {
        case 1:
        {
            Finaci(fibo, n);
            break;
        }
        case 2:
        {
            if (n == -1)
            {
                Finaci(fibo, n);
                PrintFinaci(fibo, n);
            }
            else
                PrintFinaci(fibo, n);
            break;
        }
        case 3:
        {
            cout << "Nhap x: ";
            cin >> x;
            cout << FiboAtX(x) << endl;
            break;
        }
        case 4:
        {
            system("cls");
            break;
        }
        default:
        {
            cout << "Nhap lai chuc nang tu 1 den 4." << endl;
            break;
        }
        }
    } while (1);
}

