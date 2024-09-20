#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/split-array-largest-sum/description/ */
/* TLE Eliminators: Solution discussed in vdo: Binary Search Problem Solving */


// O(N)
bool predicate(int n, int maxSplits, int nums[], int maxSum) { // predicate i.e., will return true/false
	int subArraySum = 0;
	int count = 0;

	for (int i=0;i<n;i++) {
		if (subArraySum + nums[i] > maxSum) {
			count++; // increase #splits
			subArraySum = 0; // reset
		}
		subArraySum += nums[i];
	}

	return count+1 <= maxSplits; // count+1 is #subarrays here
}

// O(log(search_space) * N) i.e., binary search on search space * time complexity of predicate function
// log(10^18) = 60, similarly: 10^15 = 50, 10^14 = 46
// even if I would have taken search space as 0....10^18
// log(10^18)*O(N) would be O(60*N) i.e., not much of TC differenece, so focus on f(x) or predicate function 
int splitArray(int n, int nums[], int k) {
	int sum = 0, largestLoad = 0;

	for (int i=0;i<n;i++) {
		sum += nums[i];
		largestLoad = max(largestLoad, nums[i]);
	}

	int l = largestLoad, r = sum, mid = 0;

	int result = 0;

	while (l <= r) {
		mid = (l+r)>>1; // to avoid overflow

		if (predicate(n,k,nums, mid)) { // returns true, i.e, all on right of array would be T, so can check on left part to minimize sum
			result = mid;
			r = mid - 1;
		}
		else { // returns false, i.e, all on left of array would be F, so can check on right part to find a T
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
	
	int n,k,d;
	cin>>n>>k;

	int nums[1000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		nums[i] = d;
	}

	cout<<splitArray(n,nums,k);

	return 0;
}