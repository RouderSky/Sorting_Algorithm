#ifndef __SHELLSORT_H__
#define __SHELLSORT_H__

//希尔排序
class Shell
{
public:
	//自己实现
	void Sort1_0(char *a, int length)
	{
		//确定h的最大值
		int h = 1;
		while (h < length / 3)
			h = 3 * h + 1;		//1,4,13,40,121,364,1093，...

		while (h >= 1)	//间隔控制
		{
			for (int i = 0; i < h; ++i)	//每个子数组的头
			{
				//对每个子数组进行插入排序
				for (int j = i + h; j < length; j += h)
				{
					char needToInsert = a[j];
					int k;
					for (k = j - h; j >= i&&needToInsert < a[k]; k -= h)
						a[k + h] = a[k];

					a[k + h] = needToInsert;
				}
			}

			h /= 3;
		}
	}

	//书本实现
	void Sort2_0(char *a, int length)
	{
		//确定h的最大值
		int h = 1;
		while (h < length / 3)
			h = 3 * h + 1;		//1,4,13,40,121,364,1093，...

		while (h >= 1)
		{
			for (int i = h; i < length; ++i)		//从所有子数组的第二元素开始到最后的元素，妙
			{
				//在i元素所属的子数组内对i元素进行插入排序
				char needToInsert = a[i];
				int j;
				for (j = i - h; j >= 0 && needToInsert < a[j]; j -= h)
					a[j + h] = a[j];

				a[j + h] = needToInsert;
			}

			h /= 3;
		}

	}
};

#endif