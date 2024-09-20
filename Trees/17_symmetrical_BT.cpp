#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/symmetric-tree/description/ */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// left => root, left, right & right => root, right, left
bool traverse(node* leftSubtree, node* rightSubtree) {
	if (leftSubtree == NULL && rightSubtree == NULL) return true;
	if ((!leftSubtree &&  rightSubtree) || (leftSubtree &&  !rightSubtree)) return false;
	if (leftSubtree->data !=  rightSubtree->data) return false;

	bool left = traverse(leftSubtree->left, rightSubtree->right);
	bool right = traverse(leftSubtree->right, rightSubtree->left);

	return left && right;
}

bool isSymmetrical(node* root) {
	if (root == NULL) return true;

	return traverse(root->left, root->right);
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(2);

	root->left->left = new node(3);
	root->left->right = new node(4);

	root->right->left = new node(4);
	root->right->right = new node(3);

	cout<<isSymmetrical(root);

	return 0;
}