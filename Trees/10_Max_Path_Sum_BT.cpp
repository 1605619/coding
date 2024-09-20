#include<bits/stdc++.h>
using namespace std;

#define int long long int

/* HARD: https://leetcode.com/problems/binary-tree-maximum-path-sum/ */
/*Solution: Use pasted screenshot*/

struct node {
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = right = NULL;
	}
};

int result = INT_MIN;

int maxPathSum(node* root) {
    if (root == NULL) return 0;

    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);

    int sum = root->data;

    /*

        can't do below one as, if leftSum or rightSum has to be considered, root->val can't be missed

        int sum = 0;

        if (root->val > 0) sum += root->val;
    
    */

    if (leftSum > 0 && leftSum >= rightSum) sum += leftSum;
    else if (rightSum > 0 && rightSum > leftSum) sum += rightSum;

    int pathSum = root->data;

    if (leftSum > 0) pathSum += leftSum;
    if (rightSum > 0) pathSum += rightSum;

    result = max(pathSum, result);

    return sum; // if sum < 0, I can return 0 as well
}
10_
// Cleaner version of code
int maxPathSum2(node* root) {
    if (root == NULL) return 0;

    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);

    result = max({result, root->data , root->data + rightSum, root->data + leftSum, root->data + leftSum + rightSum}); // find max pathSum

    return root->data + max({leftSum, rightSum, 0}); // returns pathsum
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

	result = INT_MIN;
	cout<<maxPathSum2(root)<<endl<<endl;

	cout<<result;

	return 0;
}