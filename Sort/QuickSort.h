#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

class Quick
{
public:
	void Sort(char *a, int length)
	{
		//在开始递归排序前最好先打乱一下数组，防止不合理的切分；这样就不容易出现O(N^2)这种情况
		SortCore(a, 0, length - 1);
	}

	//可以优化：在数组被分割得小于某个数值的时候，改用插入排序
	void SortCore(char *a, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		else
		{
			int j = Partition(a, left, right);
			SortCore(a, left, j - 1);
			SortCore(a, j + 1, right);
		}
	}

	//可以优化：选取部分元素来找出这部分元素的中位数当作基准
	//可以优化（代码看quick3way）：在一个数组中，不会多次选择主键值同样的元素作为基准；可以改成三向切分，就是比基准值小的元素放在左边，与基准值相等的元素放在中间，比基准值大的元素放在右边；对于包含大量重复元素的数组，可以将时间复杂度有NlgN降到N	
	int Partition(char *a, int left, int right)
	{
		//分割标准，取了首元素来当标准
		char standard = a[left];

		int i = left + 1;
		int j = right;
		while (i < j)
		{
			//注意a[i] <= standard和standard <= a[j]的等于号
			//注意i、j的边界别走多了，或者走少了
			while (a[i] <= standard && i < right){ ++i; }
			while (standard <= a[j] && j > left){ --j; }

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}

		a[left] = a[j];
		a[j] = standard;

		return j;
	}
};

class Quick3way
{
public:
	void Sort1_0(char *a, int length)
	{
		//在开始递归排序前最好先打乱一下数组，防止不合理的切分；这样就不容易出现O(N^2)这种情况
		SortCore1_0(a, 0, length - 1);
	}

	void SortCore1_0(char *a, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		else
		{
			char standard = a[left];

			int i = left + 1;
			int j = right;
			while (i < j)
			{
				while (a[i] < standard && i <= right){ ++i; }
				while (standard <= a[j] && j >= left + 1){ --j; }

				if (i < j)
				{
					char temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			a[left] = a[j];
			a[j] = standard;

			int lessRight = j - 1;

			j = right;
			while (i < j)
			{
				while (a[i] == standard && i <= right){ ++i; }
				while (standard < a[j] && j >= lessRight + 2){ --j; }

				if (i < j)
				{
					char temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}

			int equelRight = j;

			SortCore1_0(a, left, lessRight);
			SortCore1_0(a, equelRight + 1, right);
		}
	}

	//如果无法理解这段代码，请使用样例：6、2、3、7、6、6、9、1，来模拟一下
	void Sort2_0(char *a, int length)
	{
		//在开始递归排序前最好先打乱一下数组，防止不合理的切分；这样就不容易出现O(N^2)这种情况
		SortCore2_0(a, 0, length - 1);
	}

	void SortCore2_0(char *a, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		else
		{

		}
	}
};

#endif