#include "stdafx.h"
#include "Tree.h"

// Iteration method
void PostOrderI(BinaryTreeNode* root) {
	// Unable to use before initialization
	BinaryTreeNode* prev = NULL;
	stack<BinaryTreeNode*> stk;
	while (root) {//walk into the leftest child
		stk.push(root);
		root = root->left;
	}
	while (!stk.empty()) {
		root = stk.top();
		if (root->right == NULL || root->right == prev) {
			// When the right child of a node is empty or has been visited
			//it means that the node can be accessed.
			cout << root->value << " ";
			stk.pop();
			prev = root;
		}
		else {//or visit the right child
			root = root->right;
			while (root) {
				stk.push(root);
				root = root->left;
			}
		}
	}
}

// Recursive method
void PostOrderR(BinaryTreeNode* root) {
	if (root == NULL) return;
	PostOrderR(root->left);
	PostOrderR(root->right);
	cout << root->value << " ";
}

