#include "stdafx.h"
#include "Tree.h"

// Iteration method
void PreOrderI(BinaryTreeNode* root) {
	if (root == NULL) {
		return;
	}
	stack<BinaryTreeNode*> stk;
	stk.push(root);
	while (!stk.empty()) {
		root = stk.top();
		stk.pop();
		cout << root->value << " ";
		if (root->right) stk.push(root->right);
		if (root->left) stk.push(root->left);
	}
}

// Iteration method: imitate in-order traversal iterative method
void PreOrderI2(BinaryTreeNode* root) {
	stack<BinaryTreeNode*> stk;
	while (root || !stk.empty()) {
		while (root) {
			stk.push(root);
			cout << root->value << " ";
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		root = root->right;
	}
}

// Recursive method
void PreOrderR(BinaryTreeNode* root) {
	if (root == NULL) return;
	cout << root->value << " ";
	PreOrderR(root->left);
	PreOrderR(root->right);
}

