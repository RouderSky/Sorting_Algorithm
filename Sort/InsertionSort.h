#ifndef __INSERTIONSOER_H__
#define __INSERTIONSOER_H__

//插入排序
class Insertion
{
public:
	void Sort1_0(char *a, int length)
	{
		for (int index = 1; index < length; ++index)
		{
			for (int i = index; i > 0; --i)
			{
				if (a[i] < a[i - 1])
				{
					char temp = a[i];
					a[i] = a[i - 1];
					a[i - 1] = temp;
				}
				//else
				//	break;
			}
		}
	}
	
	//优化版本
	void Sort2_0(char *a, int length)
	{
		for (int index = 1; index < length; ++index)
		{
			char needToInsert = a[index];

			int i;
			for (i = index - 1; i >= 0 && needToInsert < a[i]; --i)
				a[i + 1] = a[i];	//右移

			a[i + 1] = needToInsert;
		}
	}

};

#endif
