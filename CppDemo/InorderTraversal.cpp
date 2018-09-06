#include "stdafx.h"
#include "Tree.h"

// Iteration method
void InOrderI(BinaryTreeNode* root) {
	stack<BinaryTreeNode*> stk;
	while (root || !stk.empty()) {
		while (root) {
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		cout << root->value << " ";
		root = root->right;
	}
}

// Recursive method
void InOrderR(BinaryTreeNode* root) {
	if (root == NULL) return;
	InOrderR(root->left);
	cout << root->value << " ";
	InOrderR(root->right);
}
