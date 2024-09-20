#include<bits/stdc++.h>
using namespace std;

#define int long long int

// Bottom view of BT

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

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			pair<node*, int> temp = q.front();
			q.pop();

			top[temp.second] = temp.first->data; // this time we will update it unlike while calculating top view

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
	root->right = new node(3);
	root->right->right = new node(7);
	root->right->left = new node(6);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left->right = new node(9);
	root->left->right->left = new node(8);

	vector<int> top = topView(root);
	printVector(top);


	return 0;
}