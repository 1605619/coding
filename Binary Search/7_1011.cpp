#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/ */

bool predicate(int n, int weights[], int days, int maxCapacity) {
	int count = 0;
	int capacity = 0;

	for (int i=0;i<n;i++) {
		if (capacity + weights[i] > maxCapacity) {
			count++;
			capacity = 0; // reset capacity for next day
		}
		capacity += weights[i];
	}

	return count+1 <= days;
}

int minimizedCapacity(int n, int weights[], int days) {
	int l = weights[0], r = 0, mid = 0;

	for (int i=0;i<n;i++) {
		r += weights[i];
		l = max(l, weights[i]);
	}

	int result = 0;

	while (l <= r) {
		mid = (l+r)>>1;

		if (predicate(n, weights, days, mid)) { // ..........'T'TTTTTTTTT
			result = mid;
			r = mid - 1;
		}
		else { // FFFFFFF'F'..........
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
	
	int n,days,d;
	cin>>n>>days;

	int weights[50000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		weights[i] = d;
	}

	cout<<minimizedCapacity(n,weights,days);

	return 0;
}