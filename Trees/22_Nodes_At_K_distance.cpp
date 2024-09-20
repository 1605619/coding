#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/ */

struct node {
	int val;
	node* left;
	node* right;

	node(int value) {
		val = value;
		left = right = NULL;
	}
};

map<int, bool> isVisited;

// DFS (stack) O(N) & O(HOT) i.e., a bit better than BFS space complexity
map<int, node*> getParent(node* root) {
	map<int, node*> result;
	if (root == NULL) return result;

	stack<node*> s;
	s.push(root);

	isVisited[root->val] = false;
	result[root->val] = root; // i.e., root's parent is NULL, but inserting root for simplicity and avoiding handling NULL later

	while(!s.empty()) {
		node* temp = s.top();
		s.pop();

		if (temp->left) {
			isVisited[temp->left->val] = false;
			result[temp->left->val] = temp;
			s.push(temp->left);
		}

		if (temp->right) {
			isVisited[temp->right->val] = false;
			result[temp->right->val] = temp;
			s.push(temp->right);
		}
	}

	return result;
}

// DFS (getting parents) + BFS (to find k distant nodes)
vector<int> kDistance(node* root, node* start, int k) {
	vector<int> result;
	if (root == NULL || start == NULL) return result;

	if (k == 0) {
		result.push_back(start->val);
		return result;
	}

	// using map<> (BST) better then unordered_map<> in case of large prime numbers, as unordered_map<> (hasing) can lead to collisons and O(N^2)
	// map<int, pair<node*, int>> parent = getParent(root); // map<curr_node->val, pair<parent, isParentVisisted>>
	// This data structure is complicated and didn't work properly for node visisted
	// i.e., I should have a visited array based on current node, and not parent node

	// let's create two DS, i.e., map of node to parent, and another DS for visited node

	map<int, node*> parent = getParent(root); // map<curr, parent> mapping

	queue<node*> q;
	q.push(start);

	isVisited[start->val] = true; // mark visited

	int level = 0;

	while (!q.empty()) {
		int size = q.size();
		level++;

		if (level > k+1) break;

		for (int i=0;i<size;i++) {
			node* temp = q.front();
			q.pop();

			if (level == k+1) {
				result.push_back(temp->val);
			}

			if(!isVisited[parent[temp->val]->val]) { // visit parent
				isVisited[parent[temp->val]->val] = true; // mark visited
				q.push(parent[temp->val]);
			}
			if (temp->left && !isVisited[temp->left->val]) {
				q.push(temp->left);
				isVisited[temp->left->val] = true; // mark visited
			}
			if (temp->right && !isVisited[temp->right->val]) {
				q.push(temp->right);
				isVisited[temp->right->val] = true; // mark visited
			}
		}
	}

	return result;
}

void print(vector<int> result) {
	for (int i=0;i<result.size();i++) {
		cout<<result[i]<<" ";
	}
	cout<<endl;
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

	vector<int> result = kDistance(root, root, 0);
	print(result);

	return 0;
}