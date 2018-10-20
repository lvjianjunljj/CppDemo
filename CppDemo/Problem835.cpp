#include "stdafx.h"
/*
Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does not include any kind of rotation.)

What is the largest possible overlap?

Example 1:

Input: A = [[1,1,0],
			[0,1,0],
			[0,1,0]]
	   B = [[0,0,0],
			[0,1,1],
			[0,0,1]]
Output: 3
Explanation: We slide A to right by 1 unit and down by 1 unit.
Notes:

1 <= A.length = A[0].length = B.length = B[0].length <= 30
0 <= A[i][j], B[i][j] <= 1
*/
class Solution {
public:
	// My solution is so boring and have a high time complexity: M2N2
	int largestOverlap1(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> A_co;
		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < A[i].size(); j++) {
				if (A[i][j]) {
					vector<int> temp_co(2);
					temp_co[0] = i;
					temp_co[1] = j;
					A_co.push_back(temp_co);
				}
			}
		}
		int res = 0;
		for (int i = 1; i < A.size() * 2; i++) {
			for (int j = 1; j < A[0].size() * 2; j++) {
				int temp = 0;
				for (vector<int> co : A_co) {
					if (co[0] - A.size() + i < 0 || co[0] - A.size() + i >= A.size() ||
						co[1] - A[0].size() + j < 0 || co[1] - A[0].size() + j >= A[0].size())
						continue;
					if (B[co[0] - A.size() + i][co[1] - A[0].size() + j]) {
						temp++;
					}
				}
				res = max(res, temp);
			}
		}
		return res;
	}

	/*
	Fantastic solution, 
	but I replace the 100 with (N * 2 - 1)(you should deeply understand why replace the 100 with (N * 2 - 1)), 
	this make the solution still work when the size of A is not limited.
	*/
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int n = A.size(), res = 0;
		vector<int> LA, LB;
		unordered_map<int, int> m;
		for (int i = 0; i < n * n; i++) if (A[i / n][i % n]) LA.push_back(i / n * (2 * n - 1) + (i % n));
		for (int i = 0; i < n * n; i++) if (B[i / n][i % n]) LB.push_back(i / n * (2 * n - 1) + (i % n));
		for (int i : LA) for (int j : LB) m[i - j]++;
		for (pair<int, int> p : m) res = max(res, p.second);
		return res;
	}
};