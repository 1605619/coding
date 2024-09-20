#include<bits/stdc++.h>
using namespace std;

// #define int long long int

/* https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/ */

/*LCA also helps with finding the path between node A and node B in a BT*/

struct node {
	int val;
	node* left;
	node* right;

	node(int value) {
		val = value;
		left = right = NULL;
	}
};

// Approch 1 (Better and simpler): -> 1 traversal O(N) & Aux space

node* LCA(node* root, node* p, node* q) {
	if (root == NULL) return NULL;

	if (root == p || root == q) return root;

	node* left = LCA(root->left, p , q);
	node* right = LCA(root->right, p , q);

	if (left && right) return root;
	if (left && !right) return left;
	if (!left && right) return right;

	return NULL;
}


// Approch 2: -> 2 tree traversals i.e., O(2N) + extra vectors i.e., O(2N) to store path + Aux space

// DFS: O(N) & O(logN) to O(N) 
bool paths(node* root, vector<node*> &path, node* target) {
	if (root == NULL) return false;
	if (root->val == target->val) {
		path.push_back(root);
		return true;
	}

	path.push_back(root);

	if(paths(root->left, path, target)) return true;
	if(paths(root->right, path, target)) return true;

	path.pop_back(); // backtracking

	return false;
}

// O(N)
node* LCA_2(node* root, node* p, node* q) {
	if (root == NULL) return NULL;

    vector<node*> path1, path2;

    if(!paths(root, path1, p)) return NULL; // O(N)
    if(!paths(root, path2, q)) return NULL; // O(N)

    for (auto x: path1) {
    	cout<<x->val<<" ";
    }
    cout<<endl;
    for (auto x: path2) {
    	cout<<x->val<<" ";
    }
    cout<<endl;

    int i = 0, size = min(path1.size(), path2.size());

    node* result = NULL;

    while (i < size) {	 // O(logN) to O(N)
        if (path1[i] == path2[i]) {
            result = path1[i];
        }
        i++;
    }

    return result;
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

	node* lowest = LCA(root, root->left, root->left->right->right);

	cout<<lowest->val;

	return 0;
}