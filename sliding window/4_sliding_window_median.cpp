#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vd vector<double>

/* HARD: https://leetcode.com/problems/sliding-window-median/description/ */

/*
	constraints:  n == k == 10e5
	
	My Approaches:

	A) Navie: sort every subarray of size k, and find middle and store as answer -> TLE

	TC: O(n * klogk) => O(10^5 * 10^5(log(10^5))) => will give TLE

	B) Sets: unique | sorted -> can't use as duplicates are possible in subarray
	
	C) Multisets: duplices | sorted | Balanced BST (logN)
		
		As we move window, we will push elements to multiset, and it will come sorted, then to find middle for median,
		we would do iterator on BST (of k size), that will take extra TC of O(k) as we can't do [] indexing on BST

		So it would have taken TC: O(nklogk), but we need TC lesser than O(nk)

		To solve this:

	C.1) Two multisets:

		instead of iterating through multiset of size k, we could have used multiset.begin() and multiset.rbegin() to find median

		TC: O(n * logk) i.e., < O(nk)

	D) Map: balanced BST -> has 'key-value' pair compared to multiset which has just 'key'
	We can also use Map if we would want


	2 1 3 4
	{} {2} -> {2} {}
	{2} {1} -> {1 2} {}
	{1 2} {3}

*/

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
	int n = nums.size();

	multiset<int> low;
	multiset<int> high;

	vd result;

	for (int i=0;i<n;i++) {

		// outside window - remove one occurance of outside element from either low or high depending upon where it is
		if (i-k >= 0) { 
			if (nums[i-k] <= *low.rbegin()) { // either nums[i] will be in low or high or both, let's find as it is sorted
				low.erase(low.find(nums[i-k]));
			}
			else {
				high.erase(high.find(nums[i-k]));
			}
		}	

		// step 1: insert to low
		low.insert(nums[i]);

		// step 2: remove highest from low, and add it to high
		high.insert(*low.rbegin());
		low.erase(low.find(*low.rbegin()));

		// step 3: check conditon 
		// low.size() == high.size() if even OR low.size() == high.size() + 1 if odd, i.e., high size can't be bigger than low size

		if (low.size() < high.size()) {
			low.insert(*high.begin());
			high.erase(high.begin());
		}

		/*
			Note:

			low.rbegin() will always be smaller than high.begin() because:
			after step 2, low.rbegin() <= high.begin()

			e.g., {1,3} {2,6}
			step 2: {1} {2,3,6}

			So we don't need to check if *low.rbegin() > *high.begin() & move high.begin() to low
		*/

		if (i >= k-1) { // pushing median to result vector
			if (k & 1) { // k is odd
				result.push_back(*low.rbegin());
			}
			else { // k is even
				result.push_back(((double)*low.rbegin() + (double)*high.begin())/2.0);
			}
		}
	}

	for (int i=0;i<result.size();i++) {
		cout<<result[i]<<" ";
	}
	

	return result;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif

	vi nums = {1,3,-1,-3,5,3,6,7};
	int k = 3;

	vd result = medianSlidingWindow(nums, k);

	return 0;
}