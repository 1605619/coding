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

string convertIntToString(int number) {
	string s, negative;

	if (number == 0) return "0";

	if (number < 0) {
		negative = '-';
		number = (-1) * number;
	}

	while (number > 0) {
		s = char(number%10 + 48) + s;
		number /= 10;
	}

	return negative + s;
}

int convertStringToInt(string s) {
	int number = 0, isNegative = 0;

	if (s[0] == '-') {
		isNegative = 1;
		s = string(s.begin() + 1, s.end());
	}

	int size = s.size();

	int ten = 1;

	for (int i=size-1;i>=0;i--) {
		int n = s[i]-48;
		number += n*ten;
		ten *= 10;
	}

	if (isNegative) return (-1)*number;
	return number;
}


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
    			result += convertIntToString(temp->val) + ",";
    		}
    		else {
    			result += "NULL,";
    		}
    		

    		if (temp && temp->left) {
    			q.push(temp->left);
    		}
    		if (temp && temp->left == NULL) {
    			q.push(NULL);
    		}

    		if (temp && temp->right) {
    			q.push(temp->right);
    		}
    		if (temp && temp->right == NULL) {
    			q.push(NULL);
    		}
    	}
    }

    return result;
}

int outerRange = 10001;

// int extractNumber(string s) {
// 	int num = 0;

// 	string n = "";

// 	int size = s.size(), i = 0;

// 	while (i < size && s[i] != ',') {
// 		n += s[i];
// 	}

// 	if (n == "NULL") return outerRange; // as per the leetcode constraint

// 	return convertStringToInt(n);
// }


TreeNode* deserialize(string data) {
	TreeNode* root = NULL;
	if (data == "") return root;

	int n = extractNumber(s);
	if (n == outerRange) return NULL;

	root = new TreeNode(n);

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int size = q.size();

		for (int i=0;i<size;i++) {
			TreeNode* temp = q.front();
			q.pop();

			TreeNode* node = new 

			if ()
		}
	}





    return root;
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

	// TreeNode* deserialized = deserialize(serialized);
	// print(deserialized);


	return 0;
}