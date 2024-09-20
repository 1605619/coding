#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/binary-tree-postorder-traversal/description/ */
/* soln: https://www.youtube.com/watch?v=2YBhNLodD8Q&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=11 */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// Iterative using 2 stacks, TC: O(N), SC: (2N)
vector<int> postorder(node* root) {
	vector<int> result;
	if (root == NULL) return result;

	stack<node*> stack1;
	stack1.push(root);

	stack<node*> stack2;

	while(!stack1.empty()) {
		node* temp = stack1.top();
		stack1.pop();

		stack2.push(temp);

		if (temp->left) stack1.push(temp->left);
		if (temp->right) stack1.push(temp->right);
	}

	while (!stack2.empty()) {
		result.push_back(stack2.top()->data);
		stack2.pop();
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

	vector<int> result = postorder(root);
	printVector(result);

	return 0;
}