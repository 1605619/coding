#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://www.spoj.com/problems/AGGRCOW/ */

// O(N)
bool predicate(int n, int stalls[], int cows, int minimumDistance) {
	int previousCowStall = stalls[0];
	int count = 1; // I've put one cow already at stalls[0]

	for (int i=1;i<n;i++) { // assuming that have put cow at stalls[0]
		if (stalls[i] - previousCowStall >= minimumDistance) {
			count++;
			previousCowStall = stalls[i];
		}
	}

	return count >= cows;
}

// O(logN * predicate()) => O(NlogN)
int aggresiveCows(int n, int cows, int stalls[]) {
	int l = 1, r = stalls[n-1], mid = 0;

	int result = r;

	while(l <= r) {
		mid = (l+r)>>1;

		if (predicate(n, stalls, cows, mid)) { // TTTTT'T'TT....FFFFF
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
	
	int t,n,c,d;
	cin>>t;

	for (int k=0;k<t;k++) {
		cin>>n>>c;

		int stalls[100000] = {0};

		for (int i=0;i<n;i++) {
			cin>>d;
			stalls[i] = d;
		}

		sort(stalls, stalls + n); // NlogN

		cout<<aggresiveCows(n,c,stalls)<<endl;
	}

	return 0;
}