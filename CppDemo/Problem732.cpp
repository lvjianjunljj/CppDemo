#include "stdafx.h"
/*
Implement a MyCalendarThree class to store your events. A new event can always be added.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A K-booking happens when K events have some non-empty intersection (ie., there is some time that is common to all K events.)

For each call to the method MyCalendar.book, return an integer K representing the largest integer such that there exists a K-booking in the calendar.

Your class will be called like this: MyCalendarThree cal = new MyCalendarThree(); MyCalendarThree.book(start, end)
Example 1:

MyCalendarThree();
MyCalendarThree.book(10, 20); // returns 1
MyCalendarThree.book(50, 60); // returns 1
MyCalendarThree.book(10, 40); // returns 2
MyCalendarThree.book(5, 15); // returns 3
MyCalendarThree.book(5, 10); // returns 3
MyCalendarThree.book(25, 55); // returns 3
Explanation:
The first two events can be booked and are disjoint, so the maximum K-booking is a 1-booking.
The third event [10, 40) intersects the first event, and the maximum K-booking is a 2-booking.
The remaining events cause the maximum K-booking to be only a 3-booking.
Note that the last event locally causes a 2-booking, but the answer is still 3 because
eg. [10, 20), [10, 40), and [5, 15) are still triple booked.


Note:

The number of calls to MyCalendarThree.book per test case will be at most 400.
In calls to MyCalendarThree.book(start, end), start and end are integers in the range [0, 10^9].
*/

// The thought of my solution is same as the thought of question7329 and question731 
class MyCalendarThree1 {
public:
	MyCalendarThree1() {

	}

	int book(int start, int end) {
		int res = 1;
		unordered_map<pair<int, int>, int, pair_hash> temp_map;
		for (auto pp : unmap) {
			if (max(pp.first.first, start) < min(pp.first.second, end)) {
				pair<int, int> pai(max(pp.first.first, start), min(pp.first.second, end));
				int tt1 = 0;
				if (unmap.count(pai))
					tt1 = unmap[pai];
				temp_map[pai] = max(pp.second + 1, temp_map[pai]);
				res = max(res, temp_map[pai]);
			}
		}
		for (auto pp : temp_map)
			unmap[pp.first] = max(unmap[pp.first], pp.second);
		if (!unmap[pair<int, int>(start, end)])
			unmap[pair<int, int>(start, end)] = 1;
		k_booking = max(k_booking, res);
		return k_booking;
	}
private:
	struct pair_hash {
		template <class T1, class T2>
		std::size_t operator () (const std::pair<T1, T2> &p) const {
			auto h1 = std::hash<T1>{}(p.first);
			auto h2 = std::hash<T2>{}(p.second);

			// Mainly for demonstration purposes, i.e. works but is overly simple
			// In the real world, use sth. like boost.hash_combine
			return h1 ^ h2;
		}
	};
	unordered_map<pair<int, int>, int, pair_hash> unmap;
	int k_booking = 1;
};

// The fantastic solution.........simple and have less time cost.
class MyCalendarThree2 {
public:
	MyCalendarThree2() {

	}

	int book(int start, int end) {
		ma[start]++;
		ma[end]--;
		int res = 0, cur = 0;
		for (pair<int, int> p : ma) {
			res = max(res, cur += p.second);
		}
		return res;
	}
private:
	map<int, int> ma;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */

 // The similar problem is question729 and question731