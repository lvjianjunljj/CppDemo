#include "stdafx.h"
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
/*
Given an n-ary tree, return the postorder traversal of its nodes' values.
Note: Recursive solution is trivial, could you do it iteratively?
*/

class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> ans;
		dfs(root, ans);
		return ans;
	}
	void dfs(Node* node, vector<int>& ans) {
		if (node == NULL) {
			return;
		}
		for (Node* child : node->children) {
			dfs(child, ans);
		}
		ans.push_back(node->val);
	}

	// The most boring solution
	vector<int> postorder2(Node* root) {
		if (root == NULL) return {};
		vector<int> res;
		stack<Node*> stk;
		stk.push(root);
		while (!stk.empty())
		{
			Node* temp = stk.top();
			stk.pop();
			for (int i = 0; i < temp->children.size(); i++) stk.push(temp->children[i]);
			res.push_back(temp->val);
		}
		reverse(res.begin(), res.end());
		return res;
	}
	// The standard recursive solution
	vector<int> postorder3(Node* root) {
		vector<int> result;
		if (root) {
			vector<int> res;
			for (auto & ch : root->children) {
				vector<int> r = postorder(ch);
				res.insert(res.end(), r.begin(), r.end());
			}
			result.insert(result.end(), res.begin(), res.end());
			result.push_back(root->val);
		}
		return result;
	}
	//Theiterative solution, same as the postorder2
	vector<int> postorder4(Node* root) {
		stack<Node*> s; s.push(root);
		vector<int> result;
		while (!s.empty() && root) {
			Node * n = s.top(); s.pop();
			result.insert(result.begin(), n->val);
			for (auto & ch : n->children) s.push(ch);
		}
		return result;
	}
};