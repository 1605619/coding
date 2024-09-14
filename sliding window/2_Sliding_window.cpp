#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

/*
	TLE - Sliding Window Lecture 1:

	-------------------------------------------------------------------------------------------

	Q1) Max subarray sum of all subarrays with size k.

	Array of size n, and 'k' value is given, where 'k' defines the size of window. Find sum of all subarrays with window size = k
	
	contraints: n, k <= 10^5

	Soln:

	A) Brute force: For all possible (n-k) subarrays of size k, calculate sum. TC: O(nk)

	B) Do prefix sum, now for each index 'n-k' subarray, I can do prefix[j] - prefix[i-1] ... somthing
	TC: O(n + n)

	C) Also, we can just use sum varable for first k elements, and move forward with +array[j] and -array[i-k]
	TC: O(n)

	Idea: Used a long long sum variable to store sum
	
	-------------------------------------------------------------------------------------------

	Q2) Distinct number of elements in all subarrayts with size k

	Idea: 
	A) map: 

	A) "unordered_map<int, int>": for mapping distinct element with #occurences, as I move forwrd in array, update the unordered_map accordingly
	map.size() returns #distinct elements.

	B) "set": it stores #unique elements, without thier frequency, so won't be that useful for our usecase.
	e.g., for window [1,1,1,3] -> set stores {1,3}

	C) "multiset": it stores all elements i.e., even duplicate elements, so again how would we define #unique elements?
	e.g., for window [1,1,1,3] -> multiset stores {1,1,1,3} -> won't provide us way to find #unique elements
	

	map vs unordered_map: -> look more into it: https://codeforces.com/blog/entry/62393
	map - balanced BST or red-black trees | unordered_map - hashing
	map - O(logN) | unordered_map - log(1) and worst O(N)
	
	map in worst case will take O(logN) TC, but in case of hash map or unorderded_map<> TC can degrade from O(1) to O(n) for each collison, when caused maximum collisions.
	Then for q collisons, it will be O(n*q)
	Read: https://codeforces.com/blog/entry/62393

	Therefore TC: O(nlogk) where n is size of array, and k is size of window or size of BST (map) as height of BST = logk


	Q3) For each window we need first negative element

	Idea: Queue (FIFO) storing negative numbers indeces

	A) Queue

	We could store negative numbers also instead of their indexes.

	TC: O(1) for insertion and deletion for Queue

	B) Sets (BST) - we could use this, by storing indeces (but can't store neg numbers as it will be sorted)
	TC: O(logk)

	C) vector - but popping from front would be O(N) not O(1) so large TC

	Hence, use queues



	Q4) Maximum subarray sum of subarrays with distinct elements of size k i.e., find max subarray sum for array of size k where each element is distinct

	example:

		Input: arr[] = {1, 5, 4, 2, 9, 9, 9}, k = 3
		Output: 15
		Explanation: The possible subarrays of arr with length 3 are:

		{1, 5, 4} which meets the requirements and has a sum of 10.
		{5, 4, 2} which meets the requirements and has a sum of 11.
		{4, 2, 9} which meets the requirements and has a sum of 15.
		{2, 9, 9} which does not meet the requirements because element 9 is repeated.
		{9, 9, 9} which does not meet the requirements because element 9 is repeated.

	A) Set of size k (stores unique) + A variable to store max

		i.e., store subarray elements in set, then as we move we need to add new and remove old element, & also keep the local maxima in variable
		when, size of set == k, then check for max updation

	Note: we can also use unordered_map<int, int> incase, size of k is small, will lead to better TC


	Q5) Max/Min in a sliding window

	A) variable storing max i.e., ans = max(ans, new_ele)

		but let's say array: 5,4,3,2,1 and k = 3
		1st window: "5,4,3",2,1 -> max = 5, ans = 5
		
		Now: ans = max (5, 2) = 5
		2nd window: 5,"4,3,2",1 -> max = 4, ans = 5 (wrong)

	B) priority queue (max heap) for size k:
		
		How will we delete '5' from heap? it will be sorted and we won't be having control over which element we want to delete


	C) multiset/map (BST) - works as stores in sorted fashion -> set would store unique, but we can have duplicates so multiset

		we can erase element we want but takes O(logk) for operaiton

		Therefore, O(nlogk)

		Note: Map (sorted/balanced BST) also works - we can store elements with frequency, using map.begin() we can get the smallest/largest element as it's sorted

		Hence, TC: O(nlogk)

	D) Deque (also called as monotonic deque) - O(n) optimisied and best approch

	
	Knowledge on Deque (double ended queue):

	- https://www.geeksforgeeks.org/how-deque-works-internally-in-cpp/
	- https://www.youtube.com/watch?v=lahmSv8ux4A&t=270s (start with 4:30)

	Applications: 
	1. Applied as both stack and queue, as it supports both operations.
	2. *Storing a web browser’s history.
	3. *Storing a software application’s list of undo operations.
	4. Job scheduling algorithm
	

	vectors are always sequential in memory too, i.e., if you change vector capacity they are reallocated in memory in a sequential order of memory

	Vector: A single large array in contiguous memory.
	[10, 20, 30, 40, 50]
	
	deques work differently, instead of having a huge memory block like in vectors they have several separate blocks of memory
	
	Deque: Multiple smaller blocks (arrays) with a map (pointer) pointing to them.

	Map: [ Block1 | Block2 | Block3 ]
	Block1: [ 1, 2, 3, 4 ]
	Block2: [ 5, 6, 7, 8 ]
	Block3: [ 9, 10, 11, 12 ]


	Note: Deques are not good, if something has to be deleted from middle, as for that block memory allocation can happen again, so depending upon usecase dequeu can be useful
	

	> Block:  Internally, a deque is often implemented using a series of fixed-size blocks (which can be thought of as small arrays). These blocks are not contiguous in memory but are instead scattered, with a map (or a similar structure) pointing to each block.
	> Map of Blocks: The deque uses a “map” (an array of pointers) where each pointer points to a block of elements. This allows the deque to manage memory more flexibly compared to a single contiguous block of memory used by vectors.
	> Dynamic Expansion: Just as vectors dynamically resize by reallocating and copying elements to a larger contiguous memory space, deques manage their size by adding or removing blocks as needed. This provides flexibility in growth and shrinkage.

	
	Note: we can also use a doubly linked list - as it provides a way to delete from end and delete from begining what we need in this approch
	
*/

// TC: O(N)
// VERY IMPORTANT TEMPLATE (DEQUE) - remove from front and back
vi minSubarrayElement(vi &arr, int k) {
	int n = arr.size();
	vi result;

	deque<int> dq; // will always be sorted based on the logic I've written - indices (inserted) and it's values both will be sorted

	for (int i=0;i<n;i++) {
		while (!dq.empty() && arr[dq.back()] >= arr[i]) { // remove from back until 
			dq.pop_back();
		}

		dq.push_back(i);

		if (dq.front() <= i-k) { // remove elements which are outside window from front
			dq.pop_front();
		}

		if (i >= k-1) { // pushing min to result vector for each subarray
			result.push_back(arr[dq.front()]);
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
	
	int n,k,d;
	cin>>n>>k;

	vi arr(n,0);

	for (int i=0;i<n;i++) {
		cin>>d;
		arr[i] = d;
	}

	vi result = minSubarrayElement(arr,k);
	print(result);

	return 0;
}