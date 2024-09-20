#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/diameter-of-binary-tree/description/ */

/*
	We can get it done, by calculating diameter passing at each node, and find one which is maxmimum
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

int result = 0;

int diameter(node* root) {
	if (root == NULL) return 0;

	int lh = diameter(root->left);
	int rh = diameter(root->right);

	result = max(result, lh + rh);

	return max(lh, rh) + 1;
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(5);
	root->left->right = new node(5);
	

	result = 0;
	cout<<"height: "<<diameter(root)<<endl;

	cout<<"Diameter: "<<result;

	return 0;
}