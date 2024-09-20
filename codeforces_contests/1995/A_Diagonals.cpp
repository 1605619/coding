// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44

// largest = 1*n + 2*(n-1) + 2*(n-2) + ... + 2*1

#include<bits/stdc++.h>
using namespace std;

#define int long long int

int diagonals(int n, int k) {
	int count = 1;

	if (k == 0) return 0;
	if (k <= n) return 1;

	k = k - n;
	n -= 1;
	int flag = 0; // 0 and 1

	while (k>0) {
		k = k - n;
		count++;
		n = n - flag;
		flag = !flag;
	}

	return count;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int t;
	cin>>t;

	int n, k;

	for (int i=0;i<t;i++) {
		cin>>n>>k;
		cout<<diagonals(n,k)<<endl;
	}	
	
	return 0;
}