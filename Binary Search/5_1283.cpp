#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/ */
/* BS on Answer */

/*Note: when solving BS on Answr question don't think much about space range, but spend time optimiing predicate function*/ 


bool predicate(int nums[], int n, int div, int threshold) {
	int sum = 0;
	float value = 0;

	for (int i=0; i<n; i++) {
		value = (float)nums[i]/(float)div;
		sum += nums[i]/div;

		if (value > nums[i]/div) sum++;
	}

	if (sum <= threshold) return true;
	return false;
}

int smallestDivisor(int n, int nums[], int t) {
	// monotonic search space: 1,2,3,4,5,6....max(nums[i])

	/*
		Statement: Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

		Means: result (i.e., sum of forAll'I'(nums[i]/divisor)) should be <= threshold

		Therefore search space of possible divisors:
		if divisor = 1, result will be maximum i.e., nums[0]/1 + nums[1]/1 + nums[2]/1 + ... + nums[n-1]/1 i.e., sum of all elements
		if divisor = 2, result will => nums[0]/2 + nums[1]/2 + nums[2]/2 + ... + nums[n-1]/2
		.
		.
		.
		if divisor = max(nums[i]), result will => nums[0]/max + nums[1]/max + nums[2]/max + ... + nums[n-1]/max, i.e., result will be minimum

		Therefore this is of 'strictly decreasing type' i.e, if x increases, y decreases

			F F F F F 'T' T T ... T -> find minimum true
		So, 1,2,3,4,5,6....max(nums[i])
	*/

	int l = 1, r = t, mid = 0;

	int divisor = 0;

	for (int i=0; i<n; i++) {
		r = max(r, nums[i]);
	}

	while (l <= r) {
		mid = (l+r)>>1; // it's best to use to avoid overflow, after that l + (r-l)/2, and worst (l+r)/2

		if (predicate(nums, n, mid, t)) { // If it's true, all on right of it, will be true
			divisor = mid;
			r = mid - 1;
		}
		else { // If it's false, all on left of it, will be false
			l = mid + 1;
		}
	}

	return divisor;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,t,d;
	cin>>n>>t;

	int nums[50000] = {0};

	for (int i=0;i<n;i++) {
		cin>>d;
		nums[i] = d;
	}

	cout<<smallestDivisor(n, nums, t);

	return 0;
}