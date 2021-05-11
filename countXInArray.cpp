// Class02_02_19520208_HuynhPhuongNhu_Bai02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

struct Songuyen
{
    int Value;
    int Rep = 0;
};

void NhapThuCong(int& n, int a[])
{
    do
    {
        cout << "Nhap luong phan tu lon hon hoac bang 0: ";
        cin >> n;
    } while (n <= 0);

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu so " << i + 1 << ": ";
        cin >> a[i];
    }
}

void NhapTuDong(int& n, int a[])
{
    srand(time(NULL));
    n = 11 + rand() % 40;
    for (int i = 0; i < n; i++)
    {
        a[i] = 101 + rand() % 20;
    }
}

void XuatDay(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << '\t';
    }
    cout << endl;
}

void swap(int& a, int& b)
{
    int tam;
    tam = a;
    a = b;
    b = tam;
}

void SapXep(int n, int a[])
{
    for (int i = 0; i < n -1 ; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}

void ThongKeSoLuong(int n, int a[], Songuyen b[])
{
    SapXep(n, a);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            b[j].Value = a[i];
            b[j].Rep++;
        }
        else
        {
            if (b[j].Value == a[i])
                b[j].Rep++;
            else
            {
                j++;
                b[j].Value = a[i];
                b[j].Rep++;
            }
        }
    }
    for (int i = 0; i <= j; i++)
    {
        cout << b[i].Value << ": " << b[i].Rep << " lan" << endl;
    }
}

int main()
{
    int arrayA[100], arrayRan[100];
    Songuyen b[100];
    int n = -1, k = -1;

    do {
        int tam;
        cout << "----------------MENU-------------------" << endl << endl;
        cout << "1. Nhap thu cong gia tri cho arrayA tu ban phim " << endl;
        cout << "2. Nhap gia tri tu dong cho arrayA " << endl;
        cout << "3. Xuat day arrayA" << endl;
        cout << "4. Thong ke so luong phan tu trong A" << endl;
        cout << "5. Xoa man hinh" << endl << endl;
        cout << "--------------THE END-------------------" << endl;
        cout << "Chon tinh nang: ";
        cin >> tam;
        cout << endl << endl;
        switch (tam)
        {
        case 1:
        {
            NhapThuCong(n, arrayA);
            break;
        }
        case 2:
        {
            NhapTuDong(k, arrayRan);
            break;
        }
        case 3:
        {
            cout << "Ban muon xuat day nhap thu cong hay nhap tu dong ?" << endl;
            cout << "1.Nhap thu cong" << endl;
            cout << "2.Nhap tu dong" << endl;
            cout << "3.Ca hai" << endl;
            cin >> tam;
            switch (tam)
            {
            case 1:
            {
                if (n == -1)
                {
                    cout << "Ban chua nhap thu cong, hay nhap lai. " << endl;
                    NhapThuCong(n, arrayA);
                    XuatDay(n, arrayA);
                }
                else
                {
                    XuatDay(n, arrayA);
                }
                break;
            }
            case 2:
            {
                if (k == -1)
                {
                    NhapTuDong(k, arrayRan);
                    XuatDay(k, arrayRan);
                }
                else
                    XuatDay(k, arrayRan);
                break;
            }
            case 3:
            {
                if (k == -1)
                {
                    NhapTuDong(k, arrayRan);
                    XuatDay(k, arrayRan);
                    cout << "//Day la day nhap tu dong" << endl;
                }
                else
                {
                    XuatDay(k, arrayRan);
                    cout << "//Day la day nhap tu dong" << endl;
                }

                if (n == -1)
                {
                   
                    cout << "Ban chua nhap thu cong, hay nhap lai. " << endl;
                    NhapThuCong(n, arrayA);
                    XuatDay(n, arrayA);
                    cout << "//Day la day nhap thu cong" << endl;
                }
                else
                {
                    cout << endl;
                    XuatDay(n, arrayA);
                    cout << "//Day la day nhap thu cong" << endl;
                }
               
                
                break;
            }
            }
            break;
        }
        case 4:
        {
            if (k == -1)
            {
                NhapTuDong(k, arrayRan);
                ThongKeSoLuong(k, arrayRan, b);
                cout << "//Day la phan tu trong mang tu dong" << endl;
            }
            else
            {
                ThongKeSoLuong(k, arrayRan, b);
                cout << "//Day la phan tu trong mang tu dong" << endl;
            }


            if (n == -1)
            {
                cout << "Ban chua nhap thu cong, hay nhap lai. " << endl;
                NhapThuCong(n, arrayA);
                ThongKeSoLuong(n, arrayA, b);
                cout << "//Day la phan tu trong mang thu cong" << endl;
            }
            else
            {
                ThongKeSoLuong(n, arrayA, b);
                cout << "//Day la phan tu trong mang thu cong" << endl;
            }
            
            break;
        }
        case 5:
        {
            system("cls");
            break;
        }
        default:
        {
            cout << "Nhap lai tinh nang trong khoang tu 1 den 5 " << endl;
        }
        }
    } while (1);
}
