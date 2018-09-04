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
		int ans = INT_MAX;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			stk.top();

		}
		return ans;

	}
};

int main() {
	Solution s;
	stack<int> st;
	st.push(1);
	st.push(2);
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;

	//cout << s.postorder(B) << endl;
	system("pause");
	return 1;
}
