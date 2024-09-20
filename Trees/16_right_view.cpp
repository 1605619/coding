#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/binary-tree-right-side-view/description/ */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// similiarly will be done for right view
vector<int> rightView(node* root) {
	vector<int> right;
	if (root == NULL) return right;

	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			node* temp = q.front();
			q.pop();

			if (i == size-1) right.push_back(temp->data);

			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
	}

	return right;
}

void printVector(vector<int> result) {
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
	root->right = new node(3);
	root->right->right = new node(7);
	root->right->left = new node(6);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left->right = new node(9);
	root->left->right->left = new node(8);

	vector<int> result = rightView(root);
	printVector(result);


	return 0;
}