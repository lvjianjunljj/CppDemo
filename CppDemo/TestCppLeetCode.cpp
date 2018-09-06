#include "stdafx.h"


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
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

int main() {
	Solution s;

	//cout << s.postorder(B) << endl;
	system("pause");
	return 1;
}
