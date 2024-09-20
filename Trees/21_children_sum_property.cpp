#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://www.naukri.com/code360/problems/childrensumproperty_790723 */
/* solution: https://www.youtube.com/watch?v=fnmisPM6cVo&list=PLkjdNRgDmcc0Pom5erUBU4ZayeU9AyRRu&index=30*/

struct node {
	int val;
	node* left;
	node* right;

	node(int value) {
		val = value;
		left = right = NULL;
	}
};

// Idea: Increase value of child nodes as equal to root node as we go down, and while coming back, make root = left + right

// (DFS) Recursion approch (though initially I thought of BFS but DFS works fine here)
// O(N) & O(HOT) -> O(N) in case of skew tree
node* childrenSum(node* root, node* parent) {
	if (root == NULL) return NULL;

	if (parent)
		root->val = max(root->val, parent->val);

	node* left = childrenSum(root->left, root);
	node* right = childrenSum(root->right, root);

	int sum = 0;

	if (left) sum += left->val;
	if (right) sum += right->val;

	root->val = max(root->val, sum);

	return root;
}

void inorder(node* root) {
	if (root) {
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
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

	inorder(root);
	cout<<endl<<endl;

	node* result = childrenSum(root, NULL);
	inorder(result);

	return 0;
}