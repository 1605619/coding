#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>

/*

	Multiset: Balanced BST (self balancing BST) -> O(logn) for insertion, deletion, search. 
	Multiset allows duplicates, and stores elements in sorted order.
	Multiset is implemented as red-black tree, which is a self balancing BST.

*/

void testMultiset(vi &nums) {
	int n = nums.size();

	multiset<int> m;

	for (int i=0;i<n;i++) {
		m.insert(nums[i]);

		// begin() - O(1) -> pointer to smallest element in multiset
		// rbegin() - O(1) -> pointer to largest element in multiset [Note: end() gives pointer next to last element]

		/*
			Multiset is implemented as red-black tree, which is a self balancing BST, and if we want to find the smallest element, 
			we can keep going to the most left node from root node, which will be the smallest element.

			Similarly, if we want to find the largest element, we can keep going to the most right node from root node, 
			which will be the largest element.

			Now to find the smallest or largest element, begin() does NOT walk down the tree every time.

			Instead, it maintains a pointer to the smallest/largest element in the tree, and returns it directly.

			Therefore, TC: O(1) for begin() and rbegin()

			Note: end() gives pointer next to last element, and rbegin() gives pointer to last element.
		*/
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

		So to delete the first occurance of 3, we would do:
			m.erase(m.find(3));

		Note: m.find(3) returns a pointer to the first occurance of 3 in the multiset.

		Therefore, TC: O(logn) for m.find(3), as it walks down the tree to find the first occurance of 3.

		And then, we can delete that pointer using m.erase(pointer)

		Therefore, TC: O(1) for m.erase(pointer), as it directly deletes the node from the tree.

		Note: m.erase(pointer) is constant time operation, but what about RBT rebalancing? It can take O(logn) time.

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
