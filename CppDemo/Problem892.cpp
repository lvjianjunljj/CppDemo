#include "stdafx.h"
/*
On a N * N grid, we place some 1 * 1 * 1 cubes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell (i, j).

Return the total surface area of the resulting shapes.



Example 1:

Input: [[2]]
Output: 10
Example 2:

Input: [[1,2],[3,4]]
Output: 34
Example 3:

Input: [[1,0],[0,2]]
Output: 16
Example 4:

Input: [[1,1,1],[1,0,1],[1,1,1]]
Output: 32
Example 5:

Input: [[2,2,2],[2,1,2],[2,2,2]]
Output: 46
*/
// It is the surface area not the sum of six view area
class Solution {
public:
	int surfaceArea(vector<vector<int>>& grid) {
		int n = grid.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] > 0) {
					ans += 2;
					ans += i == 0 ? grid[i][j] : max(0, grid[i][j] - grid[i - 1][j]);
					ans += j == 0 ? grid[i][j] : max(0, grid[i][j] - grid[i][j - 1]);
					ans += i == n - 1 ? grid[i][j] : max(0, grid[i][j] - grid[i + 1][j]);
					ans += j == n - 1 ? grid[i][j] : max(0, grid[i][j] - grid[i][j + 1]);
				}
			}
		}
		return ans;
	}
	//wrong answer, result is the sum of six view area
	int surfaceArea2(vector<vector<int>>& grid) {
		int n = grid.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int col_max = 0, row_max = 0;
			for (int j = 0; j < n; j++) {
				row_max = max(row_max, grid[i][j]);
				col_max = max(col_max, grid[j][i]);
				ans += (grid[i][j] > 0 ? 1 : 0) * 2;
			}
			ans += (col_max + row_max) * 2;
		}
		return ans;
	}
};