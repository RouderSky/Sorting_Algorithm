#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__

class Selection
{
public:
	//选择排序
	void Sort(char *a, int length)
	{
		for (int index = 0; index < length - 1; ++index)
		{
			//找出从当前位置index开始到后面所有元素中最小元素的下标
			int indexOfCurMin = index;
			for (int i = index + 1; i < length; ++i)
			{
				if (a[i] < a[indexOfCurMin])
					indexOfCurMin = i;
			}

			//将找到的最小元素和index位置上的元素进行交换
			int temp = a[index];
			a[index] = a[indexOfCurMin];
			a[indexOfCurMin] = temp;
		}
	}
};

#endif