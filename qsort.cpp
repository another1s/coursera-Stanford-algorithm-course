// qsort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int array0[11000];
long compare = 0;

void quick_sort(int a[],int begin,int end)
{

	if (begin == end)
	{
		return;
	}
	int i = begin, j = end;
	int mid = (begin + end) / 2;   // get the medium element as the pivot
	int exchange = 0;
	exchange = a[begin];
	a[begin] = a[mid];
	a[mid] = exchange;
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int pivot = a[begin];
 	while (i<j)              //searching from the left to right
	{
		while (a[j]<pivot&&j>i)     
		{
			int w = 0;
			w = a[i];
			a[i] = a[j];
			a[j] = w;
			j--;
			i++;

		}
		while (a[j] > pivot&&j>i)
		{
			
				j--;
		}
	}
	int swap = 0;
	swap = a[i];
	a[i] = a[begin];
	a[begin] = swap;
	for (int i1 = 0; i1 < 8; i1++)
	{
		cout <<"after sort "<< a[i1] << " ";
	}
	cout << endl;
	compare += end - begin;
	for (int i = 0; i < 8; i++)
	{
		cout <<a[i]<<" ";
	}
	cout << endl;
	quick_sort(a, begin, i - 1);
	quick_sort(a, i + 1, end);
}

int main()
{
	int i, j, k, m=0, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array0[i]);
	}
	quick_sort(array0, 0, n-1);
	cout << compare << endl;
	system("pause");
    return 0;
}

