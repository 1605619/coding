#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

/*

	Multiset:





*/

void testMultiset(vi &nums) {
	int n = nums.size();

	multiset<int> m;

	for (int i=0;i<n;i++) {
		m.insert(nums[i]);

		// begin() - O(1) -> pointer to smallest element in multiset
		// rbegin() - O(1) -> pointer to largest element in multiset [Note: end() gives pointer next to last element]
		cout<<*m.begin()<<" : "<<*m.rbegin()<<endl;
	}

	cout<<endl<<endl;


	for (auto itr = m.begin(); itr != m.end(); itr++) {
		cout<<*itr<<" ";
	}

	/*
		Note: Multiset allows deleting multiple occurances of same element

		Now, if I do: 
			m.erase(3); on multiset: {-3 -1 1 3 3 5 6 7 }
		
		then, 
			{-3 -1 1 3 3 5 6 7 } -> {-3 -1 1 3 5 6 7 }
		
		i.e., 2 occurances of 3 are deleted, if you want to delete only one occurance, 
			- first find location to it's first occurance -> m.find(3)
			- delete only that location -> m.erase(address)


		TC:
		value = 3;
		
		1. m.erase(value); -> min: O(logn + 1), avg: O(logn + k), worse: O(logn + n)
			min: O(logn + 1) -> if you have only one occurance of value in multiset
			avg: O(logn + k) -> if you have 'k' occurances of value in multiset
			worse: O(logn + n) -> if you have 'n' occurances of value in multiset, i.e., all elements are same in balanced BST

		because-> it first finds the first & last occurance i.e., container size occurance of 'value' in multiset which takes O(logn), and as it's
		self balancing BST, all occurances of 'value' should be connected with each other in a BST, then it takes constant operation to delete a node i.e., O(1), and for such 'k' nodes, 
		it will be O(k)

		hence, O(logn + k) for m.erase(value);

		2. m.erase(iterator) -> constant

		if provided a memory location, it will directly delete it. (note: rebalancing can be required which can take O(logn))

	*/
	

	// O(logn)
	auto addressPointerToX = m.find(3); // locates the first occurance of x and returns a pointer to that

	if (addressPointerToX != m.end()) { // check x was present and should not be null
		// O(1)
		m.erase(addressPointerToX); // erase that occurance by providing pointer to that location
	}
	

	cout<<endl<<endl;

	for (auto itr = m.begin(); itr != m.end(); itr++) {
		cout<<*itr<<" ";
	}

}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	vi nums = {1,3,-1,-3,5,3,6,7};

	testMultiset(nums);


	return 0;
}