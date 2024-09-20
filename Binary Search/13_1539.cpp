#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/kth-missing-positive-number/description/ */


// LogN
int kthMissing(int n, int arr[], int k) {
    if (arr[0] - 1 >= k) return k;

    int l = 0, r = n-1, mid = 0;
    int upperBound = INT_MAX;

    while (l <= r) {
        mid = (l+r)>>1;

        if (arr[mid] - mid - 1 == k) {
            upperBound = mid;
            r = mid - 1; // IMPORTANT: otherwise it will find wrong #left_elements -> e.g., [2,3,4,7,11], k=1 => it should point to 0th index not 2nd
        }
        else if (arr[mid] - mid - 1 > k) {
            upperBound = min(upperBound, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    if (upperBound == INT_MAX) return n+k;

    return upperBound + k;
}


int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,k,d;
	cin>>n>>k;

	int arr[1000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		arr[i] = d;
	}

	cout<<kthMissing(n,arr,k);

	return 0;
}