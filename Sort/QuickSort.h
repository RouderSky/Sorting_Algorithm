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
	//可以优化（代码看quick3way）	
	int Partition(char *a, int left, int right)
	{
		//分割标准，取了首元素来当标准
		char standard = a[left];
#if 0
		//自己写的第一个版本
		int i = left;
		int j = right+1;
		while (i < j)
		{
			while (a[++i] <= standard && i <= right){  }			//i <= right可以改成i < right
			while (standard <= a[--j] && j >= left+1){  }			//j >= left+1不可以更改j > left+1

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
#endif
#if 0
		/*这段代码非常脆弱，所有的大于小于号都要非常准确，可以当作模板记下来*/
		//自己写的第二个版本
		int i = left + 1;
		int j = right;
		while (true)
		{
			while (a[i] <= standard && i <= right) { ++i; }			//i <= right可以改成i < right
			while (standard <= a[j] && j >= left+1) { --j; }		//j >= left+1不可以更改j > left+1

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				break;
		}
#endif
#if 0
		//书本的版本
		int i = left;
		int j = right + 1;
		while (true)
		{
			//特别注意 ++i 和 --j 的位置
			//注意a[i] <= standard和standard <= a[j]的等于号
			while (a[++i] <= standard && i <= right){}			//i <= right可以改成i < right
			while (standard <= a[--j] && j >= left + 1){}			//j >= left+1不可以更改j > left+1

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				break;
		}
#endif
#if 1
		//改：书本的版本
		int i = left+1;
		int j = right;
		while(true)					//使用do...while才是正确的，之前之所以会出错是因为没有意识到i和j的初始位置是需要先用两个while来确定的
		{
			//特别注意 ++i 和 --j 的位置
			//注意a[i] <= standard和standard <= a[j]的等于号
			while (a[i] <= standard && i <= right){ ++i; }			//i <= right可以改成i < right
			while (standard <= a[j] && j >= left + 1){ --j; }		//j >= left+1不可以更改j > left+1

			if (i < j)
			{
				char temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else
				break;

		}
#endif
		a[left] = a[j];
		a[j] = standard;

		return j;
	}
};

//三向切分的快速排序：在一个数组中，不会多次选择主键值同样的元素作为基准；可以改成三向切分，就是比基准值小的元素放在左边，与基准值相等的元素放在中间，比基准值大的元素放在右边；对于包含大量重复元素的数组，可以将时间复杂度有NlgN降到N
class Quick3way
{
public:
	void Sort(char *a, int length)
	{
		//在开始递归排序前最好先打乱一下数组，防止不合理的切分；这样就不容易出现O(N^2)这种情况
		SortCore(a, 0, length - 1);
	}

	void SortCore(char *a, int left, int right)
	{
		if (left >= right)
		{
			return;
		}
		else
		{
			//三向切分
#if 1
			//自己的实现
			//第一次切分
			char standard = a[left];
			int i = left+1;
			int j = right;
			while(true)
			{
				while (a[i] < standard && i <= right){ ++i; }
				while (standard <= a[j] && j >= left+1){ --j; }

				if (i < j)
				{
					char temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
				else
					break;
			}
			a[left] = a[j];
			a[j] = standard;

			int lessRight = j - 1;

			//第二次切分
			j = right;
			while(true)
			{
				while (a[i] == standard && i <= right){ ++i; }
				while (standard < a[j] && j >= lessRight + 2){ --j; }

				if (i < j)
				{
					char temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
				else
					break;
			}

			int equelRight = j;

			SortCore(a, left, lessRight);
			SortCore(a, equelRight + 1, right);
#endif
#if 0		
			//书本的实现
			//如果无法理解这段代码，请使用样例：6、2、3、7、6、6、9、1，来模拟一下
			char standard = a[left];
			int lt = left;				//lt其实永远都指向最左端的基准值
			int i = left + 1;
			int gt = right;
			while (i <= gt)
			{
				if (a[i] < standard)
				{
					char temp = a[i];
					a[i] = a[lt];
					a[lt] = temp;

					++i;
					++lt;
				}
				else if (a[i] == standard)
				{
					++i;
				}
				else if (a[i] > standard)
				{
					char temp = a[i];
					a[i] = a[gt];
					a[gt] = temp;

					--gt;
				}
			}

			SortCore(a, left, lt - 1);
			SortCore(a, gt + 1, right); 
#endif
		}
	}
};

#endif
