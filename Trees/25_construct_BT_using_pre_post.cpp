#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/ */

/*
	Note: A unique BT can't be constructed using preorder and postorder, but needs inorder

	therefore:

	preorder + postorder = multile BTs
	preorder + inorder = unique BTs
	postorder + inorder = unique BTs
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		val = value;
		left = right = NULL;
	}
};

int totalNodesInLeftSubtree(vector<int> &preorder, vector<int> &postorder) {
	int target = preorder[1];

	int i = 0;

	while (postorder[i] != target) {
		i++;
	}

	return i;
}

TreeNode* constructTree(vector<int> &preorder, vector<int> &postorder) {
	if (preorder.size() == 0) return NULL; // or postorder.size()
	if (preorder.size() == 1) return new TreeNode(preorder[0]);

	// TreeNode* root = new TreeNode(preorder[0]);

	int start1PostorderIndex = 0;
	int end1PostorderIndex = totalNodesInLeftSubtree(preorder, postorder);

	int leftBTSize = end1PostorderIndex - start1PostorderIndex + 1;

	vector<int> LBTPreorder(preorder.begin() + 1, preorder.begin() + leftBTSize + 1);
	vector<int> LBTPostorder(postorder.begin(), postorder.begin() + leftBTSize);

	vector<int> RBTPreorder(preorder.begin() + leftBTSize + 2, preorder.end());
	vector<int> RBTPostorder(postorder.begin(), postorder.begin() + leftBTSize);

	// for (int i=0;i<LBTPreorder.size();i++) {
	// 	cout<<LBTPreorder[i]<<" ";
	// }
	// cout<<endl;
	// for (int i=0;i<LBTPostorder.size();i++) {
	// 	cout<<LBTPostorder[i]<<" ";
	// }

	// root->left = constructTree(); 
	// root->right = constructTree();

	return NULL;

}

void inorder(TreeNode* root) {
	if (root == NULL) return;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	int n,d;
	cin>>n;

	vector<int> preorder, postorder;

	for (int i=0;i<n;i++) {
		cin>>d;
		preorder.push_back(d);
	}

	for (int i=0;i<n;i++) {
		cin>>d;
		postorder.push_back(d);
	}

	TreeNode* root = constructTree(preorder, postorder);
	inorder(root);

	// cout<<totalNodesInLeftSubtree(preorder, postorder);

	return 0;
}