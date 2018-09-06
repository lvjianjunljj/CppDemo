#include "stdafx.h"
#include "Tree.h"
// Iteration method
void SequenceI(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	queue<BinaryTreeNode*> qu;
	qu.push(root);
	while (!qu.empty()) {
		root = qu.front();
		qu.pop();
		cout << root->value << " ";
		if (root->left) qu.push(root->left);
		if (root->right) qu.push(root->right);
	}
}

// Recursive method
void SequenceRAuxDfs(vector<BinaryTreeNode*> nodeList) {
	vector<BinaryTreeNode*> nextLevel;
	for (BinaryTreeNode* node : nodeList) {
		cout << node->value << " ";
		if (node->left) nextLevel.push_back(node->left);
		if (node->right) nextLevel.push_back(node->right);
	}
	if (nextLevel.size() > 0) {
		SequenceRAuxDfs(nextLevel);
	}
}
void SequenceR(BinaryTreeNode* root) {
	if (root == NULL) return;
	vector<BinaryTreeNode*> rootLevel({ root });
	SequenceRAuxDfs(rootLevel);
}


