#include "stdafx.h"
#include "Tree.h"
#include "InorderTraversal.h"
#include "PreorderTraversal.h"
#include "PostorderTraversal.h"
#include "SequenceTraversal.h"
int main_Tree() {
	BinaryTreeNode* root = buildTestTree();
	cout << "The structure of tree: " << endl;
	printTree(root);
	cout << "The Sequence Traversal: " << endl;
	SequenceI(root);
	cout << endl;
	SequenceR(root);
	cout << endl;
	cout << "The Inorder Traversal: " << endl;
	InOrderI(root);
	cout << endl;
	InOrderR(root);
	cout << endl;
	cout << "The Preorder Traversal: " << endl;
	PreOrderI(root);
	cout << endl;
	PreOrderI2(root);
	cout << endl;
	PreOrderR(root);
	cout << endl;
	cout << "The Postorder Traversal: " << endl;
	PostOrderI(root);
	cout << endl;
	PostOrderR(root);
	cout << endl;
	system("pause");
	return 0;
}