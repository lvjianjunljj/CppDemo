#include "stdafx.h"
/*
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
*/
class Solution {
public:
	// The function to_string() and stoi() can replace the creation of vector, and this is not a good thought.
	int maximumSwap1(int num) {
		vector<int> num_vec;
		while (num > 0) {
			num_vec.push_back(num % 10);
			num = num / 10;
		}
		for (int i = num_vec.size() - 1; i > 0; i--) {
			if (num_vec[i] < num_vec[i - 1]) {
				int j = i;
				for (int k = i - 2; k >= 0; k--)
					if (num_vec[k] >= num_vec[i - 1])
						i = k + 1;
				for (int k = j + 1; k < num_vec.size(); k++)
					if (num_vec[k] < num_vec[i - 1])
						j = k;
				swap(num_vec[i - 1], num_vec[j]);
				break;
			}
		}
		int res = 0;
		for (int i = num_vec.size() - 1; i >= 0; i--) {
			res = res * 10 + num_vec[i];
		}
		return res;
	}
	// The thought is more fantastic than maximumSwap1.
	int maximumSwap2(int num) {
		string num_str = to_string(num);
		int max_val = -1, max_index = -1, left_index = -1, right_index = -1;
		for (int i = num_str.length() - 1; i >= 0; i--) {
			if (num_str[i] > max_val) {
				max_val = num_str[i];
				max_index = i;
			}
			else if (num_str[i] < max_val) {
				left_index = i;
				right_index = max_index;
			}
		}
		if (left_index >= 0) {
			cout << left_index << endl;
			swap(num_str[left_index], num_str[right_index]);
		}
		return stoi(num_str);
	}
	// The length of str based on num is short, so the time cost of double layer for loop is not big.
	int maximumSwap3(int num) {
		int res = num;
		for (int i = 1; i <= num; i *= 10)
			for (int j = i * 10; j <= num; j *= 10)
				res = max(res, num + num / i % 10 * (j - i) + num / j % 10 * (i - j));
		return res;
	}
};
