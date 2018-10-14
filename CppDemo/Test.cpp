#include "stdafx.h"
#include <stdio.h>
#include <time.h>
using namespace std;
int main(int argc, char *argv[])
{
	typedef pair<int, int> pii;
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	string a = "azAZ";
	a[2] = '1';
	cout << a << endl;
	system("pause");
	return 0;
}
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
