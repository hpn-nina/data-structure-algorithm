// Class02_02_19520208_SapXep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <time.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#define MAX1 1e5
#define MAX 10e6
using namespace std;
void InputAuto(long double a[], int n)
{
	srand(time(NULL));
	for (int i = 0; i < MAX1; i++)
	{
		a[i] = rand() / MAX;
	}
}

long double Dem_SelectionSort(long double A[], int n)
{
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	int min = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = 1; j < n; j++)
		{
			if (A[j] < A[min])
				min = j;
		}
		if (min != i)
			swap(A[i], A[min]);
	}
	end = clock();
	cpu_time_used = ((double(end) - double(start)) / CLOCKS_PER_SEC);
	return cpu_time_used;
}
bool InsertionSort(long double a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		double pos = a[i];
		int k;
		for (k = i - 1; k > -1; k--)
		{
			if (a[k] < pos)
				break;
			a[k + 1] = a[k];
		}
		a[k + 1] = pos;
	}
	return 1;
}
long double Dem_InsertionSort(long double a[], int n)
{
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	for (int i = 1; i < n; i++)
	{
		double pos = a[i];
		int k;
		for (k = i - 1; k > -1; k--)
		{
			if (a[k] < pos)
				break;
			a[k + 1] = a[k];
		}
		a[k + 1] = pos;
	}
	end = clock();
	cpu_time_used = ((double(end) - double(start)) / CLOCKS_PER_SEC);
	return cpu_time_used;
}

void CopyArrayA(long double a[], long double b[])
{
	for (int i = 0; i < 100000; i++)
		b[i] = a[i];
}
class Dataset
{
private:
	long double* arr = new long double[10000000];
	int n = 10000000;
public:
	void InputAuto()
	{
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() / MAX;
		}
	}
	long double TimeGenerateSelectionSort()
	{
		return Dem_SelectionSort(arr, n);
	}
	long double TimeGenerateInsertionSort()
	{
		return Dem_InsertionSort(arr, n);
	}
	Dataset CopyArr()
	{
		Dataset b;
		for (int i = 0; i < n; i++)
			b.arr[i] = arr[i];
		return b;
	}
};
class SetofDataset
{
private:
	Dataset A[15];
public:
	void AutoGenerateInput()
	{
		for (int i = 0; i < 15; i++)
			A[i].InputAuto();
	}
	void PrintTimeGenerateTable()
	{
		Dataset b;
		cout << "******************************************************\n";
		for (int i = 0; i < 15; i++)
		{
			b = A[i].CopyArr();
			cout << "*";
			cout << setw(14) << "Dataset " << i + 1;
			cout << setw(13) << "||   " << b.TimeGenerateInsertionSort();
			cout << setw(13) << "||   " << A[i].TimeGenerateSelectionSort();
			cout << "*\n";
		}
		cout << "******************************************************\n";
	}
};
int main()
{
	SetofDataset a;
	Dataset A, B;
	return 0;
}