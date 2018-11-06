#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__

//优先队列的一种实现方式：二叉堆
//二叉堆：用这个数据结构可以很容易进行排序，但是直接用这个数据结构来排序效率并不高，因为我们只用很小一部分代码就够了
class MaxPQ
{
private:
	char *pq;		//节点为k，父节点为(k-1)/2，左孩子为2*k+1，右孩子为2*k+2
	int N;			//记录堆中元素的个数
public:
	MaxPQ(int maxN)
	{
		pq = new char[maxN];
		N = 0;
	}
	~MaxPQ()
	{
		delete[] pq;
	}
	bool isEmpty()
	{
		return N == 0;
	}
	int size()
	{
		return N;
	}
	void insert(char v)
	{
		pq[N] = v;
		swim(N);

		++N;
	}
	char delMax()
	{
		char max = pq[0];

		char temp = pq[0];
		pq[0] = pq[N - 1];
		pq[N - 1] = temp;

		--N;

		sink(0);

		return max;
	}
	//核心
	void swim(int k)
	{
		while (k > 0 && pq[k] > pq[(k - 1) / 2])
		{
			char temp = pq[k];
			pq[k] = pq[(k - 1) / 2];
			pq[(k - 1) / 2] = temp;

			k = (k - 1) / 2;
		}
	}
	//核心
	void sink(int k)
	{
		while (2 * k + 1 < N)
		{
			int maxChild = 2 * k + 1;
			if (maxChild + 1 < N && pq[maxChild + 1] > pq[maxChild])
				++maxChild;

			if (pq[k] >= pq[maxChild])
				break;
			else
			{
				char temp = pq[k];
				pq[k] = pq[maxChild];
				pq[maxChild] = temp;

				k = maxChild;
			}

		}
	}
};


class Heap
{
public:
	//注意：N是待排序数组的长度
	void sink(char *a, int k, int N)
	{
		while (2 * k + 1 < N)
		{
			int maxChild = 2 * k + 1;
			if (maxChild + 1 < N && a[maxChild + 1] > a[maxChild])
				++maxChild;

			if (a[k] >= a[maxChild])
				break;
			else
			{
				char temp = a[k];
				a[k] = a[maxChild];
				a[maxChild] = temp;

				k = maxChild;
			}
		}
	}
	//可以优化：先下沉后上浮，可将比较次数减少一半；这个方法需要额外的空间来辅助，只有当比较需要很高的代价时才采用
	void sort(char *a,int N)
	{
		for (int i = (N - 1) / 2; i >= 0; --i)
			sink(a, i, N);

		for (int i = N - 1; i > 0; --i)
		{
			char temp = a[i];
			a[i] = a[0];
			a[0] = temp;

			sink(a, 0, i);
		}
	}
};

#endif