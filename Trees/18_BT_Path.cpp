#include<bits/stdc++.h>
using namespace std;

// #define int long long int

/* https://leetcode.com/problems/binary-tree-paths/description/ */

struct node {
	int val;
	node* left;
	node* right;

	node(int value) {
		val = value;
		left = right = NULL;
	}
};

string convertIntToString(int number) {
	string s, negative;

	if (number < 0) {
		negative = '-';
		number = (-1) * number;
	}

	while (number > 0) {
		s = char(number%10 + 48) + s;
		number /= 10;
	}

	return negative + s;
}

vector<string> paths;

// Note: SC of DFS can be better than BFS, because on an avg, SC: O(logN) in DFS and O(N) in BFS

// we could do it using pass by reference then backtracking step would come into picture
// DFS: O(N) & O(height of tree) i.e., O(N) in skew trees
void traverse(node* root, string path) {
	if (root == NULL) return;

	if (root->left == NULL && root->right == NULL) {
		paths.push_back(path);
		return;
	}

	if (root->left)	traverse(root->left, path + "->" + convertIntToString(root->left->val));
	if (root->right) traverse(root->right, path + "->" + convertIntToString(root->right->val));
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

	if (root) traverse(root, convertIntToString(root->val));

	for (auto path: paths) {
		cout<<path<<endl;
	}

	// int a = 48;

	// cout<<char(a);

	return 0;
}