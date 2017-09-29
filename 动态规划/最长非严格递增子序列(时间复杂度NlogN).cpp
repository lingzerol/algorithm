int bSearch(int num, int k)  
{  
    int low=1, high=k;  
    while(low<=high)  
    {  
        int mid=(low+high)/2;  
        if(num>=b[mid])  
            low=mid+1;  
        else   
            high=mid-1;  
    }  
    return low;  
}  
 
int LIS()
{
	int low = 1, high = n;
	int k = 1;
	b[1] = p[1];
	for(int i=2; i<=n; ++i)
	{
		if(p[i]>=b[k])
			b[++k] = p[i];
		else
		{
			int pos = bSearch(p[i], k);
			b[pos] = p[i];
		}
	}
	return k;
}