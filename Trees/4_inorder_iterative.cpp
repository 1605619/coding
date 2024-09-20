#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/binary-tree-inorder-traversal/description/ */
/* solution: https://www.youtube.com/watch?v=lxTGsVXjwvM&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=10 */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// DFS (stack)
vector<int> inorder(node* root) {
	vector<int> result;
	if (root == NULL) return result;

	stack<node*> s;

	node* curr = root;

	while (!s.empty() || curr) {
		if (curr != NULL) { // left
			s.push(curr);
			curr = curr->left;
		}
		else { // root + right
			curr = s.top();
			s.pop();
			result.push_back(curr->data);

			curr = curr->right;
		}
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

	vector<int> result = inorder(root);
	printVector(result);

	return 0;
}