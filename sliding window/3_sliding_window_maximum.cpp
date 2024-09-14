#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

/* HARD: https://leetcode.com/problems/sliding-window-maximum/description/ */

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	int n = nums.size();
	vi result;

	deque<int> dq; // we could have used DLL also

	for (int i=0;i<n;i++) {
		while (!dq.empty() && nums[dq.back()] <= nums[i]) { // remove from back
			dq.pop_back();
		}

		dq.push_back(i); // push

		if (dq.front() <= i-k) { // remove from front
			dq.pop_front();
		}

		if (i >= k-1) {
			result.push_back(nums[dq.front()]);
		}
	}

	return result;
}

void print(vi arr) {
	for (int i=0;i<arr.size();i++) {
		cout<<arr[i]<<" ";
	}
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	vi nums = {1,3};
	int k = 3;

	vi result = maxSlidingWindow(nums, k);
	print(result);

	return 0;
}