#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/maximum-depth-of-binary-tree/description/ */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// Note: we can also use LOT type of solution to find height, it will again take O(N) & O(N)
// But rcursive solution might be better, as generally trees are not skewed so SC: O(logN) avg

// Recursive: TC: O(N), SC: O(height) => O(N) height of tree can be N for skew tree
int maxDepth(node* root) { // height of tree
	if (root == NULL) return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return max(leftDepth, rightDepth) + 1;
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

	cout<<maxDepth(NULL);

	return 0;
}