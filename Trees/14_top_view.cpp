#include<bits/stdc++.h>
using namespace std;

#define int long long int

// Top view of BT


/*
	Solution:

	1) (Correct) Simplified version of vertical order (LOT BSF QUEUE) - (think from vertical perscpective i.e., first element of each vertical)
	i.e., once computing vertical order and storing it in VVI, now for each vertical get first element from VVI and store it in VI

	Note: We don't need to use exactly vertial order traversal as previous question as we are only interesed in top element and not rest for each vertical

	Data structure: Queue & Hashing i.e., unordered_map<int,int> (stores vertical-node mapping only for top view nodes)
	Note: 
	1.we don't need to use map<int, int> as it will be BST, and will lead O(logN) time for every insertion and eventual TC will be O(nlogn)
	2. In the worst case, unorded_map time complexity can go from O(1) to O(n), especially for big prime numbers. In this situation, it is highly advisable to use a map instead to avoid getting a TLE(Time Limit Exceeded) error.


	2) (Wrong) LOT BFS QUEUE (think from horizontal perscpective i.e., first and last element of each level)
	i.e., for each level, we will know size, let's say size = k
	now push level[0] and level[k-1] in VI at push_front and push_back

	Wrong: it will produce wrong result as not necesserily each level extreme nodes will be part of top view

*/

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

vector<int> reconstruct(unordered_map<int, int> top) {
	vector<int> result;

	int left = 0, right = 0;

	for (auto node: top) {
		left = min(left, node.first);
		right = max(right, node.first);
	}

	for (int i=left;i<=right;i++) {
		result.push_back(top[i]);
	}

	return result;
}

// LOT-BFS (Queue)
vector<int> topView(node* root) {
	if (root == NULL) return vector<int>();

	queue<pair<node*, int>> q; // {node, col}
	q.push({root, 0});


	// Important: for large prime numbers use map instead otherwise will lead to TLE
	unordered_map<int, int> top; // we can explore idea of using deque and map (BST)
	// map would be better in case of large prime numbers avoiding TLE* -> explore
	// maps are recommended in competetivie coding -> TLE: Sliding Window 1 22.00

	// map (Balanced BST) - best - O(logn), avg - O(logn), worst - O(logn)
	// unorded_map (hashing) - best - O(1), avg - O(1), worst - O(n) because of so many collisions -> can lead to TLE, so using map might be better option
	// https://codeforces.com/blog/entry/111976

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			pair<node*, int> temp = q.front();
			q.pop();

			if (top.find(temp.second) == top.end()) {
				top[temp.second] = temp.first->data;
			}

			if (temp.first->left) q.push({temp.first->left, temp.second-1 });
			if (temp.first->right) q.push({temp.first->right, temp.second+1 });
		}
	}

	for (auto x: top) {
		cout<<x.first<<" : "<<x.second<<endl;
	}
	cout<<endl<<endl;

	return reconstruct(top);
}

void printVector(vector<int> result) {
	for (int i=0;i<result.size();i++) {
		cout<<result[i]<<" ";
	}
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(2);
	// root->right->right = new node(8);
	root->right->left = new node(17);
	root->right->left->right = new node(4);
	root->left->left = new node(6);
	root->left->right = new node(21);
	root->left->right->left = new node(4);
	root->left->right->left->left = new node(5);

	vector<int> top = topView(root);
	printVector(top);


	return 0;
}