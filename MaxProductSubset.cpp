// Class02_02_19520208_HuynhPhuongNhu_BT4.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        arrA[i] = -99 + rand() % 199;
    }
}
void Swap(int& a, int& b)
{
    int tam = a;
    a = b;
    b = tam;
}
void Arrange(int arrA[100], int n)
{
    for(int i=0;i<n-1;i++)
        for (int j = i + 1; j < n; j++)
        {
            if (arrA[i] > arrA[j])
                Swap(arrA[i], arrA[j]);
        }
}
void Print(int arrA[100], int n)
{
    for (int i = 0; i < n; i++)
        cout << arrA[i] << "\t";
    cout << endl;
}
int CountNegativeNum(int arrA[100], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arrA[i] < 0)
            count++;
    }
    return count;
}
void MaxSubset(int arrA[100], int n, int Subset[100],int& k,long double& Multiply)
{
    //Neu tap toan so duong, thi tat ca nhan nhau
    //Neu tap chi co mot so am, thi loai bo so am tat ca nhan nhau
    //Neu co so 0 thi loai bo
    //Neu co tu 2 so am tro len, dem so so am, chan thi nhan lai het, le thi lay n-1 so am dau tien
    Arrange(arrA, n);
    Multiply = 1;
    k = 0;
    int m = CountNegativeNum(arrA, n);
    if (m != 0)
    {
        if (m % 2 == 1)
        {
            for (int i = 0; i < m - 1; i++)
            {
                Subset[k] = arrA[i];
                k++;
                Multiply *= arrA[i];
            }
            for (int i = m; i < n; i++)
            {
                if (arrA[i] != 0)
                {
                    Subset[k] = arrA[i];
                    k++;
                    Multiply *= arrA[i];
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (arrA[i] != 0)
                {
                    Subset[k] = arrA[i];
                    k++;
                    Multiply *= arrA[i];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (arrA[i] != 0)
                Multiply *= arrA[i];
        }
    }
}
int main()
{
    int arrA[100], Subset[100];
    int n = -1 , k;
    long double Multiply;
    do
    {
        cout << "-----------------------MENU-----------------------" << endl;
        cout << "1.Ham nhap gia tri tu dong" << endl;
        cout << "2.Ham xuat mang" << endl;
        cout << "3.Ham tim tap con co gia tri tich lon nhat" << endl;
        cout << "4.Xoa man hinh" << endl;
        cout << "----------------------THE END-------------------" << endl;
        int tam;
        cout << "Chon chuc nang: ";
        cin >> tam;
        switch (tam)
        {
        case 1:
        {
            AutoInput(arrA, n);
            break;
        }
        case 2:
        {
            if (n == -1)
            {
                AutoInput(arrA, n);
                Print(arrA, n);
            }
            else
            {
                Print(arrA, n);
            }
            break;
        }
        case 3:
        {
            if (n != -1)
            {
                MaxSubset(arrA, n, Subset, k, Multiply);
                cout << "Tap con co tich lon nhat la: " << endl;
                Print(Subset, k);
                cout << "Tich la: " << Multiply << endl;
            }
            else
            {
                AutoInput(arrA, n);
                MaxSubset(arrA, n, Subset, k, Multiply);
                cout << "Tap con co tich lon nhat la: " << endl;
                Print(Subset, k);
                cout << "Tich la: " << Multiply << endl;
            }
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
    return 0;
}
