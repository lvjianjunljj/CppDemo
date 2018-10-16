#include "stdafx.h"
/*
Alice has a hand of cards, given as an array of integers.

Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

Return true if and only if she can.



Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
Example 2:

Input: hand = [1,2,3,4,5], W = 4
Output: false
Explanation: Alice's hand can't be rearranged into groups of 4.


Note:

1 <= hand.length <= 10000
0 <= hand[i] <= 10^9
1 <= W <= hand.length
*/
class Solution {
public:
	// The time complexity of my solution is MN, N is the size of hand, it is not good enough.
	bool isNStraightHand1(vector<int>& hand, int W) {
		if (hand.size() % W) return false;
		sort(hand.begin(), hand.end());
		queue<int> q;
		unordered_map<int, int> m;
		for (int i : hand) {
			if (q.empty() || q.back() != i) q.push(i);
			if (!m.count(i)) m[i] = 0;
			m[i]++;
		}
		while (!q.empty()) {
			if (!m[q.front()]) {
				q.pop();
				continue;
			}
			int cur = q.front();
			for (int i = 0; i < W; i++) {
				if (!m[cur + i]) return false;
				m[cur + i]--;
			}
		}
		return true;
	}
	// The map in cpp is just like TreeMap in java, it has default or custom collation
	bool isNStraightHand2(vector<int>& hand, int W) {
		if (hand.size() % W) return false;
		map<int, int> m;
		for (int i : hand) {
			if (!m.count(i)) m[i] = 0;
			m[i]++;
		}
		for (pair<int, int> p : m) {
			if (p.second < 0) return false;
			if (p.second == 0) continue;
			for (int i = 1; i < W; i++) {
				if (!m[p.first + i]) return false;
				m[p.first + i] -= p.second;
			}
		}
		return true;
	}
	// The solution in Dicussion is more simple
	bool isNStraightHand3(vector<int>& hand, int W) {
		map<int, int> c;
		for (int i : hand) c[i]++;
		for (auto it : c)
			if (c[it.first] > 0)
				for (int i = W - 1; i >= 0; --i)
					if ((c[it.first + i] -= c[it.first]) < 0)
						return false;
		return true;
	}
};
// In fact, the time cost of three solution is almost the same