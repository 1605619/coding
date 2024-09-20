#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/binary-tree-preorder-traversal/description/ */
// Do it iteratively

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// DFS (stack) TC: O(N), SC: O(N)
vector<int> preorder(node* root) {
	vector<int> result;
	if (root == NULL) return result;

	stack<node*> s;
	s.push(root);

	while (!s.empty()) {
		node* temp = s.top();
		s.pop();

		result.push_back(temp->data);

		// preorder: root, left, right -> as we need to travel left first in tree, so keep it on top of stack
		if (temp->right) s.push(temp->right); // IMPORTANT: we need to first insert right then left child for preorder
		if (temp->left) s.push(temp->left);
	}

	return result;
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
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right = new node(3);
	root->right->left = new node(6);
	root->right->right = new node(7);

	vector<int> preOrder = preorder(root);
	printVector(preOrder);

	return 0;
}