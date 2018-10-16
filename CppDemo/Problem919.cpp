#include "stdafx.h"
/*
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Write a data structure CBTInserter that is initialized with a complete binary tree and supports the following operations:

CBTInserter(TreeNode root) initializes the data structure on a given tree with head node root;
CBTInserter.insert(int v) will insert a TreeNode into the tree with value node.val = v so that the tree remains complete, and returns the value of the parent of the inserted TreeNode;
CBTInserter.get_root() will return the head node of the tree.


Example 1:

Input: inputs = ["CBTInserter","insert","get_root"], inputs = [[[1]],[2],[]]
Output: [null,1,[1,2]]
Example 2:

Input: inputs = ["CBTInserter","insert","insert","get_root"], inputs = [[[1,2,3,4,5,6]],[7],[8],[]]
Output: [null,3,4,[1,2,3,4,5,6,7,8]]


Note:

The initial given tree is complete and contains between 1 and 1000 nodes.
CBTInserter.insert is called at most 10000 times per test case.
Every value of a given or inserted node is between 0 and 5000.
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// My solution with queue.
class CBTInserter1 {
public:
	CBTInserter1(TreeNode* root) {
		nq = new queue<TreeNode*>;
		this->root = root;
		queue<TreeNode*> temp;
		temp.push(root);
		while (temp.front() != NULL && !temp.empty()) {
			if (temp.front()->left == NULL || temp.front()->right == NULL) {
				this->nq->push(temp.front());
			}
			temp.push(temp.front()->left);
			temp.push(temp.front()->right);
			temp.pop();
		}
	}

	int insert(int v) {
		TreeNode* cur = new TreeNode(v);
		this->nq->push(cur);
		if (this->nq->empty()) {
			return 0;
		}
		else {
			TreeNode* parent = this->nq->front();
			if (parent->left == NULL) {
				parent->left = cur;
			}
			else {
				parent->right = cur;
				this->nq->pop();
			}
			return parent->val;
		}
	}

	TreeNode* get_root() {
		return root;
	}
private:
	queue<TreeNode*>* nq;
	TreeNode* root;
};

// The simple solution with vector.
class CBTInserter2 {
public:
	CBTInserter2(TreeNode* root) {
		node_vec.push_back(root);
		for (int i = 0; i < node_vec.size(); i++) {
			if (node_vec[i]->left != NULL) node_vec.push_back(node_vec[i]->left);
			if (node_vec[i]->right != NULL) node_vec.push_back(node_vec[i]->right);
		}
	}

	int insert(int v) {
		node_vec.push_back(new TreeNode(v));
		if (node_vec.size() % 2) node_vec[node_vec.size() / 2 - 1]->right = node_vec[node_vec.size() - 1];
		else node_vec[node_vec.size() / 2 - 1]->left = node_vec[node_vec.size() - 1];
		return node_vec[node_vec.size() / 2 - 1]->val;
	}

	TreeNode* get_root() {
		return node_vec[0];
	}
private:
	vector<TreeNode*> node_vec;
};


/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
