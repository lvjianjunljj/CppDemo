#include "stdafx.h"
/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:
Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:
Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.
Example 4:
Input: deadends = ["0000"], target = "8888"
Output: -1
Note:
The length of deadends will be in the range [1, 500].
target will not be in the list deadends.
Every string in deadends and the string target will be a string of 4 digits from the 10,000 possibilities '0000' to '9999'.
*/
class Solution {
public:
	// My dfs method is TLE, test in local machine will have stack overflow error.
	int openLock1(vector<string>& deadends, string target) {
		set<string> dead_set;
		for (string s : deadends) dead_set.insert(s);
		map<string, int> step_map;
		dfs(dead_set, step_map, "0000", 0);
		return step_map.count(target) ? step_map[target] : -1;
	}
	// My bfs solution is a bit complicated to write and have a high time cost. 
	int openLock2(vector<string>& deadends, string target) {
		set<string> dead_set;
		for (string s : deadends) dead_set.insert(s);
		set<string> se;
		queue<pair<string, int>> que;
		que.push(pair<string, int>("0000", 0));
		while (!que.empty()) {
			pair<string, int> cur_pair = que.front();
			que.pop();
			string cur_str = cur_pair.first;
			if (dead_set.count(cur_str)) continue;
			int cur_step = cur_pair.second;
			if (cur_str == target) return cur_step;
			for (int i = 0; i < 4; i++) {
				char source = cur_str[i];
				for (int j : {1, 9}) {
					cur_str[i] = (cur_str[i] - '0' + j) % 10 + '0';
					if (!se.count(cur_str)) {
						se.insert(cur_str);
						que.push(pair<string, int>(cur_str, cur_step + 1));
					}
					cur_str[i] = source;
				}
			}
		}
		return -1;
	}
	// Sequence traversal has less time cost
	int openLock3(vector<string>& deadends, string target) {
		unordered_set<string> dds(deadends.begin(), deadends.end());
		unordered_set<string> q1, q2, pass, visited;
		string init = "0000";
		if (dds.find(init) != dds.end() || dds.find(target) != dds.end()) return -1;
		visited.insert("0000");
		q1.insert("0000"), q2.insert(target);
		int res = 0;
		while (!q1.empty() && !q2.empty()) {
			if (q1.size() > q2.size()) swap(q1, q2);
			pass.clear();
			for (auto ss : q1) {
				vector<string> nbrs = nbrStrs(ss);
				for (auto s : nbrs) {
					if (q2.find(s) != q2.end()) return res + 1;
					if (visited.find(s) != visited.end()) continue;
					if (dds.find(s) == dds.end()) {
						pass.insert(s);
						visited.insert(s);
					}
				}
			}
			swap(q1, pass);
			res++;
		}
		return -1;
	}
private:
	void dfs(set<string>& dead_set, map<string, int>& step_map, string cur_str, int step) {
		step_map[cur_str] = step;
		for (int i = 0; i < 4; i++) {
			char source = cur_str[i];
			for (int j : {1, 9}) {
				cur_str[i] = (cur_str[i] - '0' + j) % 10 + '0';
				if (!dead_set.count(cur_str) && (!step_map.count(cur_str) || step_map[cur_str] > step + 1)) dfs(dead_set, step_map, cur_str, step + 1);
				cur_str[i] = source;
			}
		}
	}
	vector<string> nbrStrs(string key) {
		vector<string> res;
		for (int i = 0; i < 4; i++) {
			string tmp = key;
			tmp[i] = (key[i] - '0' + 1) % 10 + '0';
			res.push_back(tmp);
			tmp[i] = (key[i] - '0' - 1 + 10) % 10 + '0';
			res.push_back(tmp);
		}
		return res;
	}
};