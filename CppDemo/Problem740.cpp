#include "stdafx.h"
/*
Given an array nums of integers, you can perform operations on the array.

In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

You start with 0 points. Return the maximum number of points you can earn by applying such operations.

Example 1:
Input: nums = [3, 4, 2]
Output: 6
Explanation:
Delete 4 to earn 4 points, consequently 3 is also deleted.
Then, delete 2 to earn 2 points. 6 total points are earned.
Example 2:
Input: nums = [2, 2, 3, 3, 3, 4]
Output: 9
Explanation:
Delete 3 to earn 3 points, deleting both 2's and the 4.
Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
9 total points are earned.
Note:

The length of nums is at most 20000.
Each element nums[i] is an integer in the range [1, 10000].
*/
class Solution {
public:
	// It is not hard to think of this solution and complete it.
	int deleteAndEarn1(vector<int>& nums) {
		map<int, int> m;
		for (int i : nums) m[i]++;
		int contain = 0, not_contain = 0, res = 0;
		for (pair<int, int> p : m) {
			if (m.count(p.first - 1)) {
				res = max(contain, not_contain + p.first * p.second);
				int contain_val = contain;
				contain = not_contain + p.first * p.second;
				not_contain = max(not_contain, contain_val);
			}
			else {
				res = max(contain + p.first * p.second, not_contain + p.first * p.second);
				not_contain = max(contain, not_contain);
				contain = res;
			}
		}
		return res;
	}
	// This solution is so simple but the thought is the same as the previous solution.
	int deleteAndEarn2(vector<int>& nums) {
		vector<int> freqs(10000, 0);
		for (int i : nums) freqs[i - 1]++;
		int skip = 0, take = 0;
		for (int i = 0; i < 10000; i++) {
			int prev_take = take;
			take = skip + freqs[i] * (i + 1);
			skip = max(skip, prev_take);
		}
		return max(skip, take);
	}
};