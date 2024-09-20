#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

struct node {
	int data;
	node* left;
	node* right;

	node(int value) {
		data = value;
		left = right = NULL;
	}
};

void printVoV(vvi result) {
	for (int i=0;i<result.size();i++) {
		for (auto x: result[i]) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

vvi result;

void inorder(node* root, int level) {
        if (root == NULL) return;

        if (result.size() <= level) result.push_back(vector<int>()); // vector<int>() creates empty vector
        result[level].push_back(root->data);

        inorder(root->left, level+1);
        inorder(root->right, level+1);
}

// Using Inorder traversal - check leetcode
// TC: O(N), SC: O(N + N)
void inorderLOT(node* root) {
	inorder(root,0);
    // return result;
}

// BFS (Queue) without using NULL
vvi LOT(node* root) {
	vvi result;
	if (root == NULL) return result;

	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size(); // defines #nodes at given level
		vector<int> level; // it will store nodes at given level

		for (int i=0;i<size;i++) {
			node* currentNode = q.front(); // Queue has front() and back()
			if (currentNode->left) q.push(currentNode->left);
			if (currentNode->right) q.push(currentNode->right);
			level.push_back(currentNode->data);

			q.pop(); // deleting from queue
		}

		result.push_back(level);
	}

	return result;
}

// BFS (Queue) with NULL, TC: O(N) & SC: O(N) bcuz in complete BT last node will have n/2 nodes
void levelOrderTravsersal(node* root) {
	if (root == NULL) return; // If I don't add this condition, then double NULL would lead to infinite loop

	vvi result;
	result.push_back(vector<int>());

	int level = 0; // 0th indexed level

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* temp = q.front();
		q.pop();

		if (temp == NULL) {
			if (q.size() > 0) // to avoid infinite loop
				q.push(NULL);
			
			level++;
			continue;
		}

		if (result.size() <= level) {
			result.push_back(vector<int>());
		}
		result[level].push_back(temp->data);

		if (result.size())

		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}

	printVoV(result);
}

int32_t main() { 
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
#endif
	
	node* root = new node(1);
	root->left = new node(2);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right = new node(3);
	root->right->left = new node(6);
	root->right->right = new node(7);

	// levelOrderTravsersal(root);

	vvi result = LOT(root);
	printVoV(result);



	return 0;
}