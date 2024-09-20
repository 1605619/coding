#include<bits/stdc++.h>
using namespace std;

#define int long long int

/*

	1. Full BT: either has 0 or 2 children
	2. Complete BT: All levels completly filled except last level, and last level has nodes as left as possible
	3. Perfect BT: All leaf nodes at same level
	4. Balanced BT: A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
	5. Degenerate BT: Skew trees

*/

struct node {
	int data;
	node* left;
	node* right;

	node (int value) { // constructor
		data = value;
		left = right = NULL;
	}
};

// O(N) & O(heightOfTree) i.e., in worst case of skew tree = O(N)
void preorder(node* root) {
	if (root != NULL) {
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

void inorder(node* root) {
	if (root != NULL) {
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);

	preorder(root);
	cout<<endl;

	return 0;
}