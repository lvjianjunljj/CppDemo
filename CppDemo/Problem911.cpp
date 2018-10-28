#include "stdafx.h"
/*
In an election, the i-th vote was cast for persons[i] at time times[i].

Now, we would like to implement the following query function: TopVotedCandidate.q(int t) will return the number of the person that was leading the election at time t.

Votes cast at time t will count towards our query.  In the case of a tie, the most recent vote (among tied candidates) wins.



Example 1:

Input: ["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
Output: [null,0,1,1,0,0,1]
Explanation:
At time 3, the votes are [0], and 0 is leading.
At time 12, the votes are [0,1,1], and 1 is leading.
At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
This continues for 3 more queries at time 15, 24, and 8.


Note:

1 <= persons.length = times.length <= 5000
0 <= persons[i] <= persons.length
times is a strictly increasing array with all elements in [0, 10^9].
TopVotedCandidate.q is called at most 10000 times per test case.
TopVotedCandidate.q(int t) is always called with t >= times[0].
*/

// My solution based on binary search,It is the standard thought.
class TopVotedCandidate {
public:
	TopVotedCandidate(vector<int> persons, vector<int> times) {
		int person = 0, count = 0;
		unordered_map<int, int> vote_map;
		for (int i = 0; i < persons.size(); i++) {
			if (++vote_map[persons[i]] >= count) {
				person = persons[i];
				count = vote_map[persons[i]];
			}
			time_cand_vec.push_back(pair<int, int>(times[i], person));
		}
	}

	int q(int t) {
		int start = 0, end = time_cand_vec.size() - 1;
		while (start < end) {
			int mid = (start + end + 1) / 2;
			if (t >= time_cand_vec[mid].first)
				start = mid;
			else
				end = mid - 1;
		}
		return time_cand_vec[start].second;
	}
private:
	vector<pair<int, int>> time_cand_vec;
};
//The solution on leetcode website is more simple.
// Note the function upper_bound().
class TopVotedCandidate2 {
public:
	map<int, int> m;
	TopVotedCandidate2(vector<int> persons, vector<int> times) {
		int n = persons.size(), lead = -1;
		unordered_map<int, int> count;
		for (int i = 0; i < n; ++i) m[times[i]] = persons[i];
		for (auto it : m) {
			if (++count[it.second] >= count[lead])lead = it.second;
			m[it.first] = lead;
		}
	}

	int q(int t) {
		return (--m.upper_bound(t))->second;
	}
};