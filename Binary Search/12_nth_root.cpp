#include<bits/stdc++.h>
using namespace std;

#define int long long int

// Find the Mth root of give number N
// example: find 3rd root of 27 i.e., cube root of 27 -> 3*3*3 => 3

// Binary Search on Answer

bool predicate(int n, int m, int mid) {
	int value = 1;
	for (int i=0;i<m;i++) {
		value *= mid;
	}

	return value <= n;
}

int nthRoot(int n, int m) {
	int l=1, r = n/3, mid = 0;

	int result = 0;

	while (l <= r) {
		mid = (l+r)>>1;

		if (predicate(n,m,mid)) { // TTTTTT'T'TT....FFFFF
			result = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return result;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,m;
	cin>>n>>m;

	cout<<nthRoot(n,m);

	return 0;
}