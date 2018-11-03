#include <iostream>		/* cout */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

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

#define NEED_2_BE_SORT_DATA_LEN 10

int main()
{
#if 1
	srand(time(NULL));
	char a[NEED_2_BE_SORT_DATA_LEN]; //{'j','i','h','o','p'};

	for (int i = 0; i < NEED_2_BE_SORT_DATA_LEN; ++i)
		a[i] = 'A' + rand() % 26;

//	Selection selection;
//	selection.Sort(a, NEED_2_BE_SORT_DATA_LEN);
//	Insertion insertion;
//	insertion.Sort2_0(a, NEED_2_BE_SORT_DATA_LEN);
//	Shell shell;
//	shell.Sort2_0(a, NEED_2_BE_SORT_DATA_LEN);
//	Merge merge;
//	merge.Sort(a, NEED_2_BE_SORT_DATA_LEN);
//	Quick quick;
//	quick.Sort(a, NEED_2_BE_SORT_DATA_LEN);
	Quick3way quick3way;
	quick3way.Sort(a, NEED_2_BE_SORT_DATA_LEN);
//	Heap heap;
//	heap.sort(a, NEED_2_BE_SORT_DATA_LEN);

	for (int i = 0; i < 10; ++i)
		cout << (int)a[i] << " ";
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