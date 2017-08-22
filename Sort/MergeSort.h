#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <iostream>		/* NULL */
#include <algorithm>	/* min */

using namespace std;

class Merge
{
private:
	//a数组的副本,辅助空间
	char *aux;
public:
	Merge(){ aux = NULL; }

	//单次归并，将a数组的两部分已排好的子数组合并起来
	//mid代表左边子数组的最后一个元素下标
	void merge(char *a, int left, int mid, int right)
	{
		for (int i = left; i <= right; ++i)
			aux[i] = a[i];

		int idxOfLeft = left;
		int idxOfRight = mid + 1;
		//开始归并
		for (int i = left; i <= right; ++i)
		{
			if (idxOfLeft > mid&&idxOfRight <= right)
				a[i] = aux[idxOfRight++];
			else if (idxOfLeft <= mid&&idxOfRight > right)
				a[i] = aux[idxOfLeft++];
			else if (aux[idxOfLeft] < aux[idxOfRight])
				a[i] = aux[idxOfLeft++];
			else
				a[i] = aux[idxOfRight++];
		}
	}

	//自顶向下的递归归并排序
	//这个函数还可以优化，如果left和right之间的插值小到一定的程度，就不用再递归了；直接用插入排序、希尔排序或者选择排序，速度可以提升；其中插入排序可以缩短10%~15%
	void SortCore(char *a, int left, int right)
	{
		if (left >= right)
			return;
		else
		{
			int mid = (left + right) / 2;
			SortCore(a, left, mid);
			SortCore(a, mid + 1, right);
			merge(a, left, mid, right);		//这条语句在执行前还可以做一个判断：如果a[mid]<=a[mid+1]，这条语句可以不执行；
		}
	}

	//启动函数
	void Sort(char *a, int length)
	{
		//保险
		if (aux != NULL)
		{
			delete[] aux;
			aux = NULL;
		}

		aux = new char[length];
		SortCore(a, 0, length - 1);
	}

};

class MergeBu
{
private:
	//a数组的副本,辅助空间
	char *aux;

public:
	MergeBu(){ aux = NULL; }

	//单次归并，将a数组的两部分已排好的子数组合并起来
	//mid代表左边子数组的最后一个元素下标
	void merge(char *a, int left, int mid, int right)
	{
		for (int i = left; i <= right; ++i)
			aux[i] = a[i];

		int idxOfLeft = left;
		int idxOfRight = mid + 1;
		//开始归并
		for (int i = left; i <= right; ++i)
		{
			if (idxOfLeft > mid&&idxOfRight <= right)
				a[i] = aux[idxOfRight++];
			else if (idxOfLeft <= mid&&idxOfRight > right)
				a[i] = aux[idxOfLeft++];
			else if (aux[idxOfLeft] < aux[idxOfRight])
				a[i] = aux[idxOfLeft++];
			else
				a[i] = aux[idxOfRight++];
		}
	}

	//自底向上的归并排序
	//可以给链表进行排序，而不用辅助数组
	void Sort(char *a, int length)
	{
		//保险
		if (aux)
		{
			delete[] aux;
			aux = NULL;
		}

		aux = new char[length];

		for (int subArraySize = 1; subArraySize < length; subArraySize <<= 1)
		{
			for (int left = 0; left < length - subArraySize; left += (subArraySize << 1))		//注意这里的终止条件
				merge(a, left, left + subArraySize - 1, min(left + (subArraySize << 1) - 1, length - 1));
		}
	}
};

#endif