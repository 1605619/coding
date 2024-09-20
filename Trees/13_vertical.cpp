#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define vvi vector<vector<int>>

/* https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/ */

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

// Approch 1 (recommended):

int leftWidth = 0, rightWidth = 0;

// O(N) & O(height of tree)
void width(node* root, int col) {
	if (root == NULL) return;

	width(root->left, col-1);

	leftWidth = min(leftWidth, col);
	rightWidth = max(rightWidth, col);

	width(root->right, col+1);
}

// supporting function
vector<int> concatAndSortVector(vvi vec) {
	vector<int> result;
	int size = vec.size();

	for (int i=0;i<size;i++) {
		sort(vec[i].begin(), vec[i].end()); // sorting vector for each level

		result.insert(result.end(), vec[i].begin(), vec[i].end()); // concat all levels
	}

	return result;
}

// LOT - BFS (Queue). 
// TC: O(N) & SC: O(size of lowest level of tree) because that will be stored in queue and O(N) in worst case
vector<int> verticalForCol(node* root, int col) {
	if (root == NULL) return vector<int>();

	vvi colResult;

	queue<pair<node*, int>> q;
	q.push(make_pair(root, 0));

	while (!q.empty()) {
		int size = q.size();
		vector<int> level;

		for (int i=0;i<size;i++) {
			pair<node*, int> temp = q.front();
			q.pop();

			if (temp.second == col) level.push_back(temp.first->data);  

			if (temp.first->left) q.push({temp.first->left, temp.second-1}); // This is also a way to make & push pair in one go
			if (temp.first->right) q.push({temp.first->right, temp.second+1});
		}

		colResult.push_back(level);
	}

	// concat vectors for given col
	return concatAndSortVector(colResult);
} 

// O(N+N), SC: O(N+N) in worst case
vvi vertical(node* root) {
	vvi result;
	if (root == NULL) return result;

	leftWidth = rightWidth = 0;
	width(root,0);

	for (int i = leftWidth; i <= rightWidth; i++) {
		result.push_back(verticalForCol(root,i));
	}

	return result;
}


// Approch 2 (Not recommended due to higher TC): Using map<int, map<int, multiset<int>>> 
// map & multiset uses balanced BST internally

vvi reconstructObject(map<int, map<int, multiset<int>>> m) {
	vvi result;

	for (auto vertical: m) { // each vertical
		vector<int> levelVector;
		for (auto level: vertical.second) { // each level within a vertical
			for (auto x: level.second) { // each node within a level for a vertical
				levelVector.push_back(x);
			}
		}
		result.push_back(levelVector);
	}

	return result;
}

// TC: O(NlogN) because, BFS takes O(N) and one insertion to BST takes O(logN) on avg
vvi vertical(node* root) {
	vvi result;
	if (root == NULL) return result;

	// sorted at vertical and at level because of Balanced BST / Red-Black tree
	map<int, map<int, multiset<int>>> order; // map<vertical_col, map<level, multiset<node->data>>>
	// instead of using map we could use unorderd_map (hasing) then insertion time could reduce to O(1) from O(logN)

	queue<pair<node*, pair<int, int>>> q; // queue<node, vertical, level>
	q.push({root, {0, 0}}); // make_pair(first, second) can be used too

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			pair<node*, pair<int, int>> temp = q.front();
			q.pop();

			order[temp.second.first][temp.second.second].insert(temp.first->data); // TC: O(logn + logm + logk) = O(log(m*n*k)), n = #verticals, m = #levels, k = #nodes in particular level of a vertical 

			if (temp.first->left) q.push({temp.first->left, {temp.second.first-1, temp.second.second+1}});
			if (temp.first->right) q.push({temp.first->right, {temp.second.first+1, temp.second.second+1}});
		}
	}

	return reconstructObject(order);
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
	root->left = new node(2);
	root->right = new node(2);
	// root->right->right = new node(8);
	root->right->left = new node(17);
	root->right->left->right = new node(4);
	root->left->left = new node(6);
	root->left->right = new node(21);
	root->left->right->left = new node(4);
	root->left->right->left->left = new node(5);

	vvi result = vertical(root);
	printVoV(result);


	return 0;
}