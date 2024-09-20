#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

/* https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// a bit smarter/cleaner without extra data structure for reverse
vvi zigZag2(node* root) {
	vvi result; 
	if (root == NULL) return result;

	queue<node*> q;
	q.push(root);

	int levelNumber = 0;

	while (!q.empty()) {
		int size = q.size(); // #nodes at given level

		vector<int> level(size); // predefined the size of vector for that level

		for (int i=0;i<size;i++) {
			node* temp = q.front();
			q.pop();

			int index = levelNumber%2 == 0 ? i: size - i - 1;
			level[index] = temp->data;

			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		
		result.push_back(level);
		levelNumber++;
	}

	return result;
}

// LOT/BFS (Queue) - used stack for reverse
vvi zigZag(node* root) {
	vvi result; 
	if (root == NULL) return result;

	queue<node*> q;
	q.push(root);

	int levelNumber = 0;

	while (!q.empty()) {
		int size = q.size(); // #nodes at given level

		vector<int> level;
		stack<int> stack;

		for (int i=0;i<size;i++) {
			node* temp = q.front();
			q.pop();

			if (levelNumber%2 == 0)
				level.push_back(temp->data);
			else 
				stack.push(temp->data);

			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
		if (levelNumber%2 == 0)
			result.push_back(level);
		else {
			vector<int> level;
			while (!stack.empty()) {
				level.push_back(stack.top());
				stack.pop();
			}
			result.push_back(level);
		}
		levelNumber++;
	}

	return result;
}

void printVoV(vvi result) {
	for (int i=0;i<result.size();i++) {
		for (auto x: result[i]) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(-2);
	root->right = new node(3);
	root->left->left = new node(-55);
	root->left->right = new node(5);
	root->left->left->left = new node(0);
	root->left->right->right = new node(10182);

	vvi result = zigZag2(root);
	printVoV(result);

	return 0;
}