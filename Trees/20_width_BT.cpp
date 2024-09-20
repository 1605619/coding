#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/maximum-width-of-binary-tree/description/ */

struct node {
	int val;
	node* left;
	node* right;

	node(int value) {
		val = value;
		left = right = NULL;
	}
};

// BFS (Queue) as we calculate width at given level
int width(node* root) {
	int maxWidth = 0;
	if (root == NULL) return maxWidth;

	queue<pair<node*, int>> q; // pair(node, index) -> taking 0 based indexing i.e., 2i+1 and 2i+2
	q.push({root, 1}); // starting with index 1 but using 0 based indexing formulas

	while (!q.empty()) {
		int size = q.size(); // #nodes at given level

		int minIndex = 0, maxIndex = 0;
		int l = 0, r = 0;

		for (int i=0;i<size;i++) {
			pair<node*, int> temp = q.front();
			q.pop();

			if (i == 0) minIndex = temp.second;
			if (i == size-1) maxIndex = temp.second;

			if (temp.second > 0) {
				l = 2*(temp.second - 1) + 1;
				r = 2*(temp.second - 1) + 2;
			}

			if (temp.first->left) q.push({temp.first->left, l});
			if (temp.first->right) q.push({temp.first->right, r});
		}

		maxWidth = max(maxWidth, maxIndex - minIndex + 1);
	}

	return maxWidth;
}	



int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(3);
	root->left = new node(5);
	root->right = new node(1);

	root->left->left = new node(6);
	root->left->right = new node(2);
	root->right->left = new node(0);
	root->right->right = new node(8);
	
	root->left->right->left = new node(7);
	root->left->right->right = new node(4);

	cout<<width(root);

	return 0;
}