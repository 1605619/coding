#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/ */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		val = value;
		left = right = NULL;
	}
};

unordered_map<TreeNode*, bool> visited;

unordered_map<TreeNode*, TreeNode*> getParent(TreeNode* root) {
	unordered_map<TreeNode*, TreeNode*> result;
	if (root == NULL) return result;

	stack<TreeNode*> s;
	s.push(root);

	result[root] = root;
	visited[root] = false;

	while (!s.empty()) {
		TreeNode* temp = s.top();
		s.pop();

		if (temp->left) {
			result[temp->left] = temp;
			visited[temp->left] = false;
			s.push(temp->left);
		}
		if (temp->right) {
			result[temp->right] = temp;
			visited[temp->right] = false;
			s.push(temp->right);
		}
	}

	return result;
}

// O(N)
TreeNode* findNode(TreeNode* root, int start) {
	if (root == NULL) return NULL;

	if (root->val == start) return root;

	TreeNode* left = findNode(root->left, start);
	if (left) return left;

	TreeNode* right = findNode(root->right, start);
	if (right) return right;

	return NULL;
}


// BFS (Queue) - LOT
int burnTree(TreeNode* root, int start) {
	if (root == NULL) return 0;

	TreeNode* startNode = findNode(root, start);
	if (startNode == NULL) return 0;

	unordered_map<TreeNode*, TreeNode*> parent = getParent(root);

	queue<TreeNode*> q;
	q.push(startNode);

	visited[startNode] = true;

	int level = 0;

	while (!q.empty()) {
		int size = q.size();
		level++;

		for (int i=0;i<size;i++) {
			TreeNode* temp = q.front();
			q.pop();

			if (!visited[parent[temp]]) {
				visited[parent[temp]] = true;
				q.push(parent[temp]);
			}

			if (temp->left && !visited[temp->left]) {
				visited[temp->left] = true;
				q.push(temp->left);
			}
			if (temp->right && !visited[temp->right]) {
				visited[temp->right] = true;
				q.push(temp->right);
			}
		}
	}

	return level-1;
}	


int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->right = new TreeNode(1);

	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);

	cout<<burnTree(root, 5);

	return 0;
}