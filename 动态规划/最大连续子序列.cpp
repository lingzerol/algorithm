int maxSubSumQuadratic(int *array, int length,int &begin, int &end) {
	int thisSum = 0,MaxSum=INT_MIN,temp_beg=0;
	begin = end = 0;
	for (int i = 0; i<length; ++i) {
		thisSum += *(array + i);
		if (thisSum > MaxSum)
		{
			begin = temp_beg;
			end = i;
			MaxSum = thisSum;
		}
		if (thisSum < 0) {
			thisSum = 0;
			temp_beg = i + 1;
		}
	}
	return MaxSum;
}
