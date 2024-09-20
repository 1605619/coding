#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/ */

// O(N)
bool predicate(int n, int bloomDay[], int boq, int flowers, int daysPassed) {
	int boqCount = 0, flowersCount = 0;

	for (int i=0;i<n;i++) {
		if (bloomDay[i] <= daysPassed) { // blossomed
			flowersCount++;
		}
		else {
			flowersCount = 0;
		}

		if (flowersCount == flowers) {
			boqCount++;
			flowersCount = 0;
		}
	}

	return boqCount >= boq;
}

// TC: O(log(SS)*O(N)) & SC: O(1)
int minimumDays(int n, int bloomDay[], int m, int k) {
	int l=1, r=0, mid = 0;

	for (int i=0;i<n;i++) {
		r = max(r, bloomDay[i]);
	}

	int result = -1;

	while (l <= r) {
		mid = (l+r)/2;

		if (predicate(n, bloomDay, m, k, mid)) { // FFFF....TT'T'TTTTT
			result = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return result;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,m,k,d;
	cin>>n>>m>>k;

	int bloomDay[100000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		bloomDay[i] = d;
	}

	cout<<minimumDays(n, bloomDay, m, k);

	return 0;
}