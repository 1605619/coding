#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		val = value;
		left = right = NULL;
	}
};

TreeNode* constructUniqueBT(vector<int> preorder, vector<int> inorder) {
	if (preorder.size() == 0) return NULL;
	if (preorder.size() == 1) return new TreeNode(preorder[0]);

	TreeNode* root = new TreeNode(preorder[0]);

	int inorderIndex = 0;

	while (inorder[inorderIndex] != preorder[0]) {
		inorderIndex++;
	}

	root->left = constructUniqueBT(vector<int>(preorder.begin() + 1, preorder.begin() + inorderIndex + 1), vector<int>(inorder.begin(), inorder.begin() + inorderIndex));
	root->right = constructUniqueBT(vector<int>(preorder.begin() + 1 + inorderIndex, preorder.end()), vector<int>(inorder.begin() + 1 + inorderIndex, inorder.end()));

	return root;
}

void print(TreeNode* root) {
	if (root == NULL) return;

	print(root->left);
	print(root->right);

	cout<<root->val<<" ";
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,d;
	cin>>n;

	vector<int> preorder, inorder;

	for (int i=0;i<n;i++) {
		cin>>d;
		preorder.push_back(d);
	}

	for (int i=0;i<n;i++) {
		cin>>d;
		inorder.push_back(d);
	}

	TreeNode* root = constructUniqueBT(preorder, inorder);
	print(root);

	return 0;
}