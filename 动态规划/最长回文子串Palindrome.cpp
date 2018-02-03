
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXN 100
using namespace std;  

int H_T_LCS(char*str, int i, int j,int n) {
	int len = 0;
	while (str[i] == str[j]&&i>=0&&j<n) {
		++len;
		--i;
		++j;
	}
	return len*2;
}
int Palindrome(char *str, int n) {
	int dp[MAXN],mlen;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	mlen = 1;
	for (int i = 1; i < n; ++i) {
		dp[i] = max(H_T_LCS(str, i - 1, i,n), H_T_LCS(str, i - 1, i + 1,n)+1);
		if (dp[i] > mlen)
			mlen = dp[i];
	}
	return mlen;
}

int main() { 
	char str[MAXN];
	while (cin >> str) {
		cout << Palindrome(str, strlen(str)) << endl;
	}
}