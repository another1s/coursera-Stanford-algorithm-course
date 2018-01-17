#include"mergesort.h"


int main()
{
	long i, j, k, m, n,length=0;
	while (scanf("%ld", &n) != EOF)
	{
		data[length] = n;
		length++;
	}
	cout << length << endl;
	merge_sort(0, length - 1);
	cout << iversion << endl;
	system("pause");
	return 0;
}