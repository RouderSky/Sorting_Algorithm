#include <iostream>		/* cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

//对函数pf，随机生成长度为n的char数组，进行t次测试
double TimeRandomInput(void(*pf)(char*, int),int n,int t)
{
	clock_t start = clock();

	char *a = new char[n];
	for (; t >= 0; --t)
	{
		for (int i=0;i<n;++i)
			a[i] = 'A' + rand() % 26;

		pf(a, n);
	}

	clock_t finish = clock();
	double totalTime = (double)(finish - start) / CLOCKS_PER_SEC;

	return totalTime;
}

int main()
{
#if 1
	srand(time(NULL));
	char a[10]; //{'j','i','h','o','p'};

	for (int i = 0; i < 10; ++i)
		a[i] = 'A' + rand() % 26;

//	Selection selection;
//	selection.Sort(a, 5);
//	Insertion insertion;
//	insertion.Sort2_0(a, 5);
//	Shell shell;
//	shell.Sort2_0(a, 5);
//	Merge merge;
//	merge.Sort(a, 5);
	Quick quick;
	quick.Sort(a, 10);
//	Quick3way quick3way;
//	quick3way.Sort2_0(a, 10);

	for (int i = 0; i < 10; ++i)
		cout << a[i] << " ";
	cout << endl;
#endif

#if 0
	//时间测试
	double time1 = TimeRandomInput(SelectionSort, 1000, 1000);
	double time2 = TimeRandomInput(SelectionSort, 1000, 1000);
	cout << time1 << endl;
	cout << time2 << endl;
#endif

	system("pause");
	return 0;
}