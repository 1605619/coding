#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/ */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		val = value;
		left = right = NULL;
	}
};

TreeNode* buildTree(vector<int> postorder, vector<int> inorder) {
	if (postorder.size() == 0) return NULL;
	if (postorder.size() == 1) return new TreeNode(postorder[0]);

	int size = postorder.size(), root_val = postorder[size-1];

	TreeNode* root = new TreeNode(root_val);

	int inorderRootIndex = 0;

	while (inorder[inorderRootIndex] != root_val) { // this can be optimised using hashing for inorder i.e., will store index of node as value
		inorderRootIndex++;
	}

	root->left = buildTree(vector<int>(postorder.begin(), postorder.begin() + inorderRootIndex), vector<int>(inorder.begin(), inorder.begin() + inorderRootIndex));
	root->right = buildTree(vector<int>(postorder.begin() + inorderRootIndex, postorder.end() - 1), vector<int>(inorder.begin() + 1 + inorderRootIndex, inorder.end()));

	return root;
}

void print(TreeNode* root) {
	if (root == NULL) return;

	cout<<root->val<<" ";

	print(root->left);



	print(root->right);

	
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,d;
	cin>>n;

	vector<int> postorder, inorder;

	for (int i=0;i<n;i++) {
		cin>>d;
		postorder.push_back(d);
	}

	for (int i=0;i<n;i++) {
		cin>>d;
		inorder.push_back(d);
	}

	TreeNode* root = buildTree(postorder, inorder);
	print(root);

	// vector<int> res(postorder.begin() + 1, postorder.end());
	// for (int i=0;i<res.size();i++) {
	// 	cout<<res[i]<<" ";
	// }

	return 0;
}