#include "stdafx.h"
/*
You have k lists of sorted integers in ascending order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c if b-a == d-c.

Example 1:
Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Note:
The given list may contain duplicates, so ascending order means >= here.
1 <= k <= 3500
-105 <= value of elements <= 105.
For Java users, please note that the input type has been changed to List<List<Integer>>. And after you reset the code template, you'll see this point.
*/

// It¡¯s not difficult to get this idea, but it¡¯s hard to implement this idea.
class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		typedef pair<int, int> pii;
		typedef pair<int, pii> piii;
		int min_val = INT_MAX, max_val = INT_MIN;
		for (vector<int> v : nums) {
			if (max_val < v[0])
				max_val = v[0];
			if (min_val > v[0])
				min_val = v[0];
		}
		vector<int> res(2);
		res[0] = min_val, res[1] = max_val;
		priority_queue<piii, vector<piii>, greater<piii>> pq;
		for (int i = 0; i < nums.size(); i++) {
			pq.push(piii(nums[i][0], pii(i, 0)));
		}
		while (!pq.empty()) {
			piii cur = pq.top();
			pq.pop();
			if (cur.second.second < nums[cur.second.first].size() - 1) {
				pq.push(piii(nums[cur.second.first][cur.second.second + 1],
					pii(cur.second.first, cur.second.second + 1)));
				max_val = max(max_val, nums[cur.second.first][cur.second.second + 1]);
				min_val = pq.top().first;
				if (max_val - min_val < res[1] - res[0]) {
					res[0] = min_val, res[1] = max_val;
				}
			}
			else {
				break;
			}
		}
		return res;
	}
};
// The similar problem is question908 and question910