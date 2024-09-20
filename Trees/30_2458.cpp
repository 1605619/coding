#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description/ */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		val = value;
		left = right = NULL;
	}
};

// O(N) & O(N)
int height(TreeNode* root, int target) {
	if (root == NULL) return 0;

	if (root->val == target) return 0;

	int l = height(root->left, target);
	int r = height(root->right, target);

	return max(l,r) + 1;
}

// O(n*q) = O(10^5 * 10^4) = O(10^9) It will throw TLE in case of skew (vine) tree, we need to do it in O(N) i.e., each query should take O(1)
vector<int> treeQueries(TreeNode* root, vector<int> queries) {
	vector<int> result;

	for (int i=0;i<queries.size();i++) { // m times
		result.push_back(height(root, queries[i]) - 1); // O(logN) in balanced BST, and O(N) in case of skew tree
	}

	return result;
}

void print(vector<int> nums) {
	for (int i=0;i<nums.size();i++) {
		cout<<nums[i]<<" ";
	}
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

	vector<int> heights = treeQueries(root, vector<int>({6}));

	return 0;
}