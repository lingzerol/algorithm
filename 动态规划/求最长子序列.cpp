#include <iostream>
#include <cmath>
/*bool cmp(int a, int b) {
	return a < b;
}*///默认比较函数
unsigned int MAX_LIST(const int *array, const unsigned int length, int *result,bool(*cmp)(int, int)) {
	/*array数组是原始数据的数组，
	length则是该数组含有元素的个数，
	而result则是记录以array为原始数据的最长递增或递减子序列，
	而cmp函数则是记录要输出的是最长递增序列还是最长递减序列或最长相等序列*/

	int *list,*pre;

	int max, n;//max记录最长序列的长度，n记录最长序列的最大（小）元素位置;

	int i, j,temp;

	list = new int[length];//用于记录当前各元素作为最大（小）元素的最长序列长度
	pre = new int[length]; //记录当前以该元素作为最大（小）元素的序列中该元素的前驱节点，用于打印序列用


	for (int i = 0; i < length;++i) {
		list[i] = 1;
		pre[i] = i;
	}
	//初始化list和pre数组


	for (i = 1,max=1,n=0; i < length; ++i) {
		for (j = 0; j < i; ++j) {
			
			if (cmp(array[j],array[i]) && (list[j]+1)>list[i])
			{
				//若当前元素比之前的元素大时，组成新的序列的长度比较之前的最大序列，若大于则替换

				list[i] = list[j] + 1;
				pre[i] = j;


				if (max < list[i])
				{

					//max记录最长序列的长度
					//n记录最长序列最大(小)元素的位置


					max = list[i];
					n = i;
				}
			}
		}
	}
	

	//输出最长序列
	temp = n;
	for (i = max-1; i >=0;--i){	
		result[i] = array[temp];
		temp = pre[temp];
	}
	delete []list, []pre;
	return max;
}