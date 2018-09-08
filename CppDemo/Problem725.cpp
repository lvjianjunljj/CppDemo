#include "stdafx.h"
/*
Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
Example 1:
Input:
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
Example 2:
Input:
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
Note:

The length of root will be in the range [0, 1000].
Each value of a node in the input will be an integer in the range [0, 999].
k will be an integer in the range [1, 50].
*/
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