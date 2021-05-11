// Class02_02_195202008_Sort_Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <minmax.h>
using namespace std;
#include <time.h>
#define MAX 100
void AutoInputArrX(int a[], int& n)
{
    srand(time(NULL));
    n = rand() % 21 + 30;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 898 + 100;
    }
}
void AutoInputArrY(int a[], int& n)
{
    srand(time(NULL));
    n = rand() % 21 + 30;
    a[0] = 100 + rand() % 31;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + rand() % 16;
        if (a[i] >= 985)
            break;
    }
}
void PrintArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;
}
int LinearSearch(int a[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
            return i;
    }
    return -1;
}
int BinarySearch(int a[], int n, int value)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == value)
            return m;
        if (a[m] < value)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int InterpolationSearch(int a[], int n, int value)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + ((r - l) / (a[r] - a[l])) * (value - a[l]);
        if (a[m] == value)
            return m;
        if (a[m] < value)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int Dem_LinearSearch(int a[], int n, int value)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        dem++;
        if (a[i] == value)
            return dem;
    }
    return dem;
}
int Dem_InterpolationSearch(int a[], int n, int value)
{
    int l = 0, r = n - 1;
    int dem = 0;
    while (l <= r)
    {
        dem++;
        int m = l + ((r - l) / (a[r] - a[l])) * (value - a[l]);
        if (a[m] == value)
            return dem;
        if (a[m] < value)
            l = m + 1;
        else
            r = m - 1;
    }
    return dem;
}
int Dem_BinarySearch(int a[], int n, int value)
{
    int l = 0, r = n - 1;
    int dem = 0;
    while (l <= r)
    {
        dem++;
        int m = l + (r - l) / 2;
        if (a[m] == value)
            return dem;
        if (a[m] < value)
            l = m + 1;
        else
            r = m - 1;
    }
    return dem;
}
int Min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}
void Sosanh(int arrayY[], int k, int x)
{
    int t = max((Dem_BinarySearch(arrayY, k, x), Dem_InterpolationSearch(arrayY, k, x)), Dem_LinearSearch(arrayY, k, x));
    int t2 = Min((Dem_LinearSearch(arrayY, k, x), Dem_InterpolationSearch(arrayY, k, x)), Dem_BinarySearch(arrayY, k, x));
    if (t == Dem_BinarySearch(arrayY, k, x))
        cout << "Tim kiem nhi phan co so lan tim kiem lon nhat: " << t << endl;
    else
    {
        if (t == Dem_InterpolationSearch(arrayY, k, x))
            cout << "Tim kiem noi suy co so lan tim kiem lon nhat: " << t << endl;
        else
            cout << "Tim kiem tuyen tinh co so lan tim kiem lon nhat: " << t << endl;
    }
    if (t2 == Dem_InterpolationSearch(arrayY, k, x))
        cout << "Tim kiem noi suy co so lan tim kiem be nhat: " << t2 << endl;
    else
    {
        if (t2 == Dem_LinearSearch(arrayY, k, x))
            cout << "Tim kiem tuyen tinh co so lan tim kiem be nhat: " << t2 << endl;
        else
            cout << "Tim kiem nhi phan co so lan tim kiem be nhat: " << t2 << endl;
    }
}
bool AvailableFindInStd(int a[], int n, int x)
{
    int* p;
    p = std::find(a, a + n, x);
    if (*p == x)
        return 1;
    else
        return 0;
}
int main()
{
    int arrayX[MAX], arrayY[MAX];
    int n, k;
    int x;
    char t;
    do
    {
        cout << "--------------------- MENU ---------------------\n";
        cout << "1. Tao mang\n\tA. Tao mang arrayX\n\tB. Tao mang arrayY\n";
        cout << "2. Xuat mang\n\tA.Xuat mang arrayX\n\tB. Xuat mang arrayY\n";
        cout << "3. Tim kiem tuyen tinh\n\tA. Ap dung mang arrayX\n\tB. Ap dung mang arrayY\n";
        cout << "4. Tim kiem nhi phan, ap dung mang arrayY\n";
        cout << "5. Tim kiem noi suy, ap dung mang arrayY\n";
        cout << "6. So sanh so lan tim kiem, ap dung mang arrayY\n";
        cout << "7. Ham tim kiem co san trong thu vien C++.\n";
        cout << "--------------------- END ----------------------\n";
        cout << "\tXin moi lua chon: ";
        int t1;
        cin >> t1;
        switch (t1)
        {
        case 1:
            cout << "\tA. Tao mang arrayX\n\tB. Tao mang arrayY\n";
            cout << "\tXin moi lua chon: ";
            cin >> t;
            if (t == 'A')
                AutoInputArrX(arrayX, n);
            if (t == 'B')
                AutoInputArrY(arrayY, k);
            break;
        case 2:
            cout << "\tA.Xuat mang arrayX\n\tB. Xuat mang arrayY\n";
            cout << "\tXin moi lua chon: ";
            cin >> t;
            if (t == 'A')
                PrintArr(arrayX, n);
            if (t == 'B')
                PrintArr(arrayY, k);
            break;
        case 3:
            cout << "\tA. Ap dung mang arrayX\n\tB. Ap dung mang arrayY\n";
            cout << "\tXin moi lua chon: ";
            cin >> t;
            cout << "Hay nhap x can tim: ";
            cin >> x;
            if (t == 'A')
            {
                if (LinearSearch(arrayX, n, x) != -1)
                    cout << "Tim thay x o vi tri " << LinearSearch(arrayX, n, x) << endl;
                else
                    cout << "Khong tim thay x\n";
            }
            if (t == 'B')
            {
                if (LinearSearch(arrayY, k, x) != -1)
                    cout << "Tim thay x o vi tri " << LinearSearch(arrayY, k, x) << endl;
                else
                    cout << "Khong tim thay x\n";
            }
            break;
        case 4:
            cout << "Hay nhap x can tim: ";
            cin >> x;
            if (BinarySearch(arrayY, k, x) != -1)
                cout << "Tim thay x o vi tri " << BinarySearch(arrayY, k, x) << endl;
            else
                cout << "Khong tim thay x\n";
            break;
        case 5:
            cout << "Hay nhap x can tim: ";
            cin >> x;
            if (InterpolationSearch(arrayY, k, x) != -1)
                cout << "Tim thay x o vi tri " << InterpolationSearch(arrayY, k, x) << endl;
            else
                cout << "Khong tim thay x\n";
            break;
        case 6:
            Sosanh(arrayY, k, x);
            break;
        case 7:
            cout << "Hay nhap x can tim: ";
            cin >> x;
            if (AvailableFindInStd(arrayX, n, x) == 1)
                cout << "Tim thay x trong mang.\n";
            else
                cout << "Khong tim thay x trong mang.\n";
            break;
        default:
            cout << "Nhap lai trong khoang tu 1 den 7.\n";
            break;
        }
    } while (1);
    return 0;
}
