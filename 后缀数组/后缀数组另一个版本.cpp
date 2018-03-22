const int MAXN = 300005;


int tt[2*MAXN];

int c[MAXN], wa[MAXN], wb[MAXN], sa[MAXN], Height[MAXN], ran[MAXN];
int n, m;
char str[MAXN];
void sort_sa(int m, int n) {
	int *x = wa, *y = wb, p = 0;
	for (int i = 0; i<m; i++)  c[i] = 0;
	for (int i = 0; i<n; i++)  c[x[i] = str[i]]++;
	for (int i = 1; i<m; i++)  c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for (int k = 1; p<n; k <<= 1, m = p) {
		p = 0;
		for (int i = n - k; i<n; i++) y[p++] = i;//按个位排序  
		for (int i = 0; i<n; i++)  if (sa[i] >= k) y[p++] = sa[i] - k;
		for (int i = 0; i<m; i++) c[i] = 0;
		for (int i = 0; i<n; i++) c[x[y[i]]]++;
		for (int i = 1; i<m; i++) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; i--)  sa[--c[x[y[i]]]] = y[i];
		swap(x, y); x[sa[0]] = 0, p = 1;
		for (int i = 1; i<n; i++)
			if (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) x[sa[i]] = p - 1;
			else x[sa[i]] = p++;
	}
}
void Getheight() {
	int k = 0, len = strlen(str);
	Clear(ran);
	Clear(Height);
	for (int i = 0; i < len; ++i)ran[sa[i]] = i;
	for (int i = 0; i < len; ++i) {
		if (k)--k;
		if (ran[i] != 0) {
			int j = sa[ran[i] - 1];
			while (str[j + k] == str[i + k]) ++k;
			Height[ran[i]] = k;
		}
	}
}
void Init() {
	scanf("%s", str);
	n = strlen(str);
}
