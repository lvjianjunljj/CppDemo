#pragma once
extern struct BinaryTreeNode {
	BinaryTreeNode(int _value) {
		value = _value;
		left = NULL;
		right = NULL;
	}

	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
extern void printTree(BinaryTreeNode*);
extern BinaryTreeNode* buildTestTree();