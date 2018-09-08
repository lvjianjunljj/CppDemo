#include "stdafx.h"
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// The creation of lenList is unnecessary
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int len = 0;
		ListNode* cur = root;
		while (cur != NULL) {
			len++;
			cur = cur->next;
		}
		vector<int> lenList(k);
		int index = 0;
		while (len > 0) {
			int lenLast = k - index;
			lenList[index] = (len + lenLast - 1) / lenLast;
			len -= lenList[index++];
		}
		vector<ListNode*> ans(k);
		ans[0] = root;
		index = 0;
		while (root != NULL && index < k - 1) {
			if (lenList[index] == 1) {
				ans[++index] = root->next;
				root->next = NULL;
				root = ans[index];
			}
			else {
				root = root->next;
				lenList[index]--;
			}
			
		}
		return ans;
	}
	// The simplest method in the Leetcode website
	vector<ListNode*> splitListToParts2(ListNode* root, int k) {
		vector<ListNode*> ans(k, nullptr);
		int len = 0;
		for (ListNode* node = root; node; node = node->next)
			len++;
		int n = len / k, r = len % k;
		ListNode* node = root, *prev = nullptr;
		for (int i = 0; i < k && node; i++, r--) {
			ans[i] = node;
			for (int j = 0; j < n + (r > 0); j++) {
				prev = node;
				node = node->next;
			}
			prev->next = nullptr;
		}
		return ans;
	}
};
int main()
{
	Solution s;
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	cout << s.splitListToParts(&node1, 2)[0] << endl;
	cout << s.splitListToParts(&node1, 2)[1] << endl;
	system("pause");
	return 1;
}
