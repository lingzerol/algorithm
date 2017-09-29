int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
 
int cmp(int *r , int a, int b, int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da (int *r , int *sa , int n, int m)
{
    int i, j, p, *x = wa, *y = wb , *t;
    for(i = 0; i < m; i++) 
        ws[i] = 0;
    for(i = 0; i < n; i++) 
        ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) 
        ws[i] += ws[i-1];
    for(i = n-1; i >= 0; i--) 
        sa[--ws[x[i]]] = i;//基数排序，记录每个元素对应的排名
    for(j = 1,p = 1; p < n ; j <<= 1,m = p)
    {
        for(p = 0, i = n - j; i < n; i++) 
            y[p++]=i;
        for(i = 0; i < n; i++)
            if(sa[i] >= j)
                y[p++] = sa[i] - j;
            //与前第j个的字符串进行匹配，前第j个字符串作为当前子串的前缀，因为sa记录的当前子串的排名，因此y数组对应的第i个元素即为右半边字符串的排名，省去了一次基数排序操作


        for(i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for(i = 0; i < m; i++)
            ws[i] = 0;
        for(i = 0; i < n; i++)
            ws[wv[i]]++;
        for(i = 1; i < m; i++)
            ws[i] += ws[i-1];
        //右半边字符串进行基数排序
        //x数组表示长度为j的字符串的排名


        for(i = n-1; i >= 0; i--)
            sa[--ws[wv[i]]] = y[i];
        for(t = x,x = y,y = t,p = 1,x[sa[0]] = 0,i = 1; i < n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p    }//进行验证以sa[i-1]和sa[i]的字符串是否相同，若是，则p保持不变，与sa[i-1]的p相同
}