#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/balanced-binary-tree/ */

/*
	Balanced BT: for every node, | height of left subtree - height of right subtree | <= 1
*/ 

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// Approch 1 i.e., modify HOT function

// func returns -1 if tree not balanced
int heightOfTree(node* root) {
	if (root == NULL) return 0;

	int lh = heightOfTree(root->left);
	int rh = heightOfTree(root->right);

	if (lh == -1 || rh == -1) return -1;

	if (ads(lh-rh) > 1) return -1;

	return max(lh, rh) + 1;

}


// Approch 2 i.e., using HOT + global variable

bool isBalancedBT = true;

// TC: O(N), SC: O(HOT) i.e., O(logN) and worst O(N) skew trees
int isBalanced(node* root) {
	if (root == NULL) return 0;

	int lh = isBalanced(root->left);
	int rh = isBalanced(root->right);

	if (abs(lh - rh) > 1) {
		isBalancedBT = false;
	}

	return max(lh, rh) + 1;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(2);
	root->left->left = new node(3);
	root->left->right = new node(3);
	root->right = new node(2);
	root->left->left->left = new node(4);
	root->left->left->right = new node(4);

	isBalancedBT = true; // resetting value
	cout<<isBalanced(root)<<endl;

	cout<<"Is BT balanced: "<<isBalancedBT;


	return 0;
}