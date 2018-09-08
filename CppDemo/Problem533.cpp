#include "stdafx.h"
/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
Example 1:
Input: ["23:59","00:00"]
Output: 1
Note:
The number of time points in the given list is at least 2 and won't exceed 20000.
The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
	// The tow method is just to familiar with the usage of sort and priority_queue with compare rule.
	int findMinDifference(vector<string>& timePoints) {
		sort(timePoints.begin(), timePoints.end(), comp);
		int hour1 = 0, minute1 = 0, ans = INT_MAX;
		for (int i = 0; i < timePoints[timePoints.size() - 1].length(); i++) {
			if (timePoints[timePoints.size() - 1][i] == ':') {
				hour1 = stoi(timePoints[timePoints.size() - 1].substr(0, i)) - 24;
				minute1 = stoi(timePoints[timePoints.size() - 1].substr(i + 1, timePoints[timePoints.size() - 1].length()));
				break;
			}
		}
		for (int j = 0; j < timePoints.size(); j++) {
			int hour2 = 0, minute2 = 0;
			hour2 = stoi(timePoints[j].substr(0, 2));
			minute2 = stoi(timePoints[j].substr(3, 2));
			int cur = (hour2 - hour1) * 60 + minute2 - minute1;
			hour1 = hour2;
			minute1 = minute2;
			ans = min(ans, cur);
		}
		return ans;

	}
	int findMinDifference2(vector<string>& timePoints) {
		int ans = INT_MAX;
		priority_queue<vector<int>, vector<vector<int>>, minHeap> minQueue;
		for (int j = 0; j < timePoints.size(); j++) {
			int hour = stoi(timePoints[j].substr(0, 2));
			int minute = stoi(timePoints[j].substr(3, 5));
			vector<int> v({ hour, minute });
			minQueue.push(v);
		}
		int hourFirst = -1, minuteFirst = -1, hourPrev = -1, minutePrev = -1, hourCur = 0, minuteCur = 0;
		while (!minQueue.empty()) {
			hourCur = minQueue.top()[0];
			minuteCur = minQueue.top()[1];
			if (hourFirst < 0) {
				hourFirst = hourCur;
				minuteFirst = minuteCur;
			}
			else {
				int cur = (hourCur - hourPrev) * 60 + minuteCur - minutePrev;
				ans = min(ans, cur);
			}
			hourPrev = hourCur;
			minutePrev = minuteCur;
			minQueue.pop();
		}
		ans = min(ans, (hourFirst - hourPrev + 24) * 60 + minuteFirst - minutePrev);
		return ans;
	}
	// The simplest method 
	int findMinDifference3(vector<string>& times) {
		int n = times.size();
		sort(times.begin(), times.end());
		int mindiff = INT_MAX;
		for (int i = 0; i < times.size(); i++) {
			int diff = abs(timeDiff(times[(i - 1 + n) % n], times[i]));
			diff = min(diff, 1440 - diff);
			mindiff = min(mindiff, diff);
		}
		return mindiff;
	}
private:
	// If you define the comparator funtion in class inner, you should add the key word "static"
	static bool comp(string timePoint1, string timePoint2) {
		int hour1 = 0, hour2 = 0, minute1 = 0, minute2 = 0;
		for (int i = 0; i < timePoint1.length(); i++) {
			if (timePoint1[i] == ':') {
				hour1 = stoi(timePoint1.substr(0, i));
				minute1 = stoi(timePoint1.substr(i + 1, timePoint1.length()));
				break;
			}
		}
		for (int i = 0; i < timePoint2.length(); i++) {
			if (timePoint2[i] == ':') {
				hour2 = stoi(timePoint2.substr(0, i));
				minute2 = stoi(timePoint2.substr(i + 1, timePoint2.length()));
				break;
			}
		}
		if (hour1 < hour2) {
			return true;
		}
		else if (hour1 > hour2) {
			return false;
		}
		else {
			return minute1 < minute2;
		}
	}
	int timeDiff(string t1, string t2) {
		int h1 = stoi(t1.substr(0, 2));
		int m1 = stoi(t1.substr(3, 2));
		int h2 = stoi(t2.substr(0, 2));
		int m2 = stoi(t2.substr(3, 2));
		return (h2 - h1) * 60 + (m2 - m1);
	}
	struct minHeap {
		bool operator()(vector<int> v1, vector<int> v2) {
			if (v1[0] > v2[0]) {
				return true;
			}
			else if (v1[0] < v2[0]) {
				return false;
			}
			else {
				return v1[1] > v2[1];
			}
		}
	};
};