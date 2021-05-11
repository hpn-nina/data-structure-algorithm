// 02_19520208_BTL2_Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;


long long LinearSearch(double a[], long long n, double x)
{
    for (long long i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return 0;
}
long long BinarySearch(double a[], long long n, double x)
{
    int l = 0, r = n - 1;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (x == a[m])
            return m;
        if (x < a[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return 0;
}
long long InterpolationSearch(double a[], long long n, double x)
{
    int l = 0, r = n - 1;
    int m;
    while (l <= r)
    {
        m = l + ((r - l) * x - a[l] / a[r] - a[l]);
        if (x == a[m])
            return m;
        if (x < a[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return 0;
}

int main()
{
    std::cout << "Hello World!\n";
}
