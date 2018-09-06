#include "stdafx.h"
#include "Tree.h"

int getDepth(BinaryTreeNode* node) {
	if (node == NULL) return 0;
	return max(1 + getDepth(node->left), 1 + getDepth(node->right));
}
void setTreePrintGridValue(BinaryTreeNode* node, int index, int start, int end,
	vector<vector<string>>& grid) {
	if (node == NULL) return;
	int mid = (start + end) / 2;
	grid[index][mid] = to_string(node->value);
	setTreePrintGridValue(node->left, index + 1, start, mid - 1, grid);
	setTreePrintGridValue(node->right, index + 1, mid + 1, end, grid);
}

void printTree(BinaryTreeNode* root) {
	int depth = getDepth(root);
	vector<vector<string>> grid;
	for (int i = 0; i < depth; i++) {
		vector<string> line;
		for (int j = 1; j < pow(2, depth); j++) {
			line.push_back(" ");
		}
		grid.push_back(line);
	}
	setTreePrintGridValue(root, 0, 0, pow(2, depth) - 2, grid);
	for (int i = 0; i < depth; i++) {
		for (int j = 0; j < pow(2, depth) - 1; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}

BinaryTreeNode* buildTestTree()
{
	BinaryTreeNode* root = new BinaryTreeNode(1);
	BinaryTreeNode* node2 = new BinaryTreeNode(2);
	BinaryTreeNode* node3 = new BinaryTreeNode(3);
	BinaryTreeNode* node4 = new BinaryTreeNode(4);
	BinaryTreeNode* node5 = new BinaryTreeNode(5);
	BinaryTreeNode* node6 = new BinaryTreeNode(6);
	BinaryTreeNode* node7 = new BinaryTreeNode(7);
	BinaryTreeNode* node8 = new BinaryTreeNode(8);
	BinaryTreeNode* node9 = new BinaryTreeNode(9);
	BinaryTreeNode* node10 = new BinaryTreeNode(10);

	root->left = node2;
	root->right = node3;

	node2->left = node4;
	node2->right = node5;

	node4->left = node6;
	node4->right = node7;

	node5->left = node8;
	node5->right = node9;

	node9->left = node10;

	return root;
}
