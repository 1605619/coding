#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/boundary-of-binary-tree/description/ */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

vector<int> leftBoundary(node* root) {
	vector<int> result;
	if (root == NULL || root->left == NULL) return result;

	node* curr = root->left;

	while (true) {
		if (curr->left == NULL && curr->right == NULL) break; // leaf node

		result.push_back(curr->data);

		if (curr->left) {
			curr = curr->left;
			continue;
		}

		if (curr->right) {
			curr = curr->right;
		}
	}

	return result;
}

vector<int> rightBoundary(node* root) {
	vector<int> result;
	if (root == NULL || root->right == NULL) return result;

	node* curr = root->right;

	while (true) {
		if (curr->left == NULL && curr->right == NULL) break; // leaf node

		result.push_back(curr->data);

		if (curr->right) {
			curr = curr->right;
			continue;
		}

		if (curr->left) {
			curr = curr->left;
		}
	}

	return result;
}

vector<int> leaf;
void leadBoundary(node* root) {
	if (root == NULL) return;

	leadBoundary(root->left);
	if (root->left == NULL && root->right == NULL) leaf.push_back(root->data);
	leadBoundary(root->right);
}

//
vector<int> boundary(node* root) {
	vector<int> result;
	if (root == NULL) return result;

	vector<int> left = leftBoundary(root);
	result.insert(result.end(), left.begin(), left.end());

	leadBoundary(root);
	result.insert(result.end(), leaf.begin(), leaf.end());

	vector<int> right = rightBoundary(root);

	int rightSize = right.size();

	for (int i=rightSize-1;i>=0;i--) {
		result.push_back(right[i]);
	}


	return result;
}


void printVector(vector<int> result) {
	cout<<endl;
	for (int i=0;i<result.size();i++) {
		cout<<result[i]<<" ";
	}
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(2);
	// root->right->right = new node(8);
	root->right->left = new node(3);
	root->right->left->right = new node(4);
	root->left->left = new node(6);
	root->left->right = new node(3);
	root->left->right->left = new node(4);
	root->left->right->left->left = new node(5);

	vector<int> result = boundary(root);
	printVector(result);

	return 0;
}