#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/ */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int value) {
		val = value;
		left = right = NULL;
	}
};

string serialize(TreeNode* root) {
	string result = "";
	if (root == NULL) return result;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			TreeNode* temp = q.front();
			q.pop();

			if (temp) {
				result += to_string(temp->val) + ",";
			}
			else {
				result += "null,";
			}

			if (temp && temp->left) q.push(temp->left); 
			if (temp && !temp->left) q.push(NULL); // "temp &&" is important for an edge case, i.e., it should insert NULL to queue only for valid nodes

			if (temp && temp->right) q.push(temp->right);
			if (temp && !temp->right) q.push(NULL);
		}
	}

	// these two steps are extra and not required
	result = string(result.begin(), result.end()-1); // removing extra comma from end
	result = "[" + result + "]"; // Just to make it look better like: [3,5,1,6,2,0,8,7,4,null,null,null,null,null,null,null,null,null,null]

	return result;
}

TreeNode* deserialize(string tree) {
	if (tree.size() == 0) return NULL;

	tree = string(tree.begin()+1, tree.end()-1); // removing [ and ]
	stringstream str(tree);

	string node;
	getline(str, node, ',');

	TreeNode* root = new TreeNode(stoi(node));

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode* temp = q.front(); // created a new pointer pointing to address loc of 'root'
		q.pop();

		getline(str, node, ',');

		if (node == "null") {
			temp->left = NULL;
		}
		else {
			TreeNode* leftNode = new TreeNode(stoi(node));
			temp->left = leftNode;
			q.push(leftNode);
		}

		getline(str, node, ',');

		if (node == "null") {
			temp->right = NULL;
		}
		else {
			TreeNode* rightNode = new TreeNode(stoi(node));
			temp->right = rightNode;
			q.push(rightNode);
		}
	}

	return root; // this address never changes so we returned it
}

void print(TreeNode* root) {
	if (root == NULL) return;

	cout<<root->val<<" ";
	print(root->left);
	print(root->right);
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
	
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(4);

	string serialized = serialize(root);
	cout<<"serialized: "<<serialized<<endl;

	TreeNode* deserialized = deserialize(serialized);
	print(deserialized);

	return 0;
}