#ifndef __INSERTIONSOER_H__
#define __INSERTIONSOER_H__

//插入排序(冒泡排序)
class Insertion
{
public:
	//冒泡形式
	void Sort1_0(char *a, int length)
	{
		for (int index = 1; index < length; ++index)	//每一次需要开始下沉的元素
		{
			for (int i = index; i > 0; --i)				//下沉的过程
			{
				if (a[i] < a[i - 1])
				{
					char temp = a[i];
					a[i] = a[i - 1];
					a[i - 1] = temp;
				}
			}
		}
	}

	//插入形式
	//冒泡的优化版本
	void Sort2_0(char *a, int length)
	{
		for (int index = 1; index < length; ++index)				//每一次需要开始下沉的元素
		{
			char needToInsert = a[index];

			int i;
			for (i = index - 1; i >= 0 && needToInsert < a[i]; --i)		//寻找位置的过程
				a[i + 1] = a[i];	//右移

			a[i + 1] = needToInsert;
		}
	}

};



#endif