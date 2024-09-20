#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/count-complete-tree-nodes/description/ */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		val = value;
		left = right = NULL;
	}
};

int leftHeight(TreeNode* root) {
	if (root == NULL) return 0;

	int height = 1;

	while (root->left) {
		root = root->left;
		height++;
	}

	return height;
}

int rightHeight(TreeNode* root) {
	if (root == NULL) return 0;

	int height = 1;

	while (root->right) {
		root = root->right;
		height++;
	}

	return height;
}

int count(TreeNode* root) {
	if (root == NULL) return 0;

	int lh = leftHeight(root);
	int rh = rightHeight(root);

	if (lh == rh) return pow(2,lh) - 1; // or, "(1<<lh) - 1", i.e., for N=1 001 move bits left lh times, would have given me power

	int leftCount = count(root->left);
	int rightCount = count(root->right);

	return 1 + leftCount + rightCount;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(4);

	cout<<count(root);

	return 0;
}