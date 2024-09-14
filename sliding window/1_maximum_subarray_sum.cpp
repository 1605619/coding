#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/maximum-subarray/description/ */

int maxSubArray(int n, int arr[]) {
    if (n == 1) return arr[0];

    int i=0, j=0, sum=0, result = INT_MIN;

    while (i < n && j < n) {
        sum += arr[j];
        
        result = max(result, sum);

        if (sum < 0) {
            j++;
            i = j;
            sum = 0;
        }
        else j++;
    }

    return result;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,d;
	cin>>n;

	int arr[100000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		arr[i] = d;
	}

	cout<<maxSubArray(n, arr);

	return 0;
}