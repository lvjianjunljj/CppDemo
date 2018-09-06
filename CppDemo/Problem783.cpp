#include "stdafx.h"
/*
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

		  4
		/   \
	  2      6
	 / \
	1   3

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	// inorder traversal iteration method
	int minDiffInBST(TreeNode* root) {
		int prev = 0, ans = INT_MAX;
		bool start = false;
		stack<TreeNode*> stk;
		while (root != NULL || !stk.empty()) {
			while (root != NULL) {
				stk.push(root);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
			if (start) {
				ans = min(ans, root->val - prev);
			}
			prev = root->val;
			start = true;
			root = root->right;

		}
		return ans;

	}
};