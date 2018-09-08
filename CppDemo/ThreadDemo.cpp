#include "stdafx.h"

void greeting(int index) {
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Hello multithread!   " << index << endl;
}

void main_Thread()
{
	time_t nowtime = time(NULL);
	thread t1{ greeting, 0 };
	vector<thread> thread_list(20);
	for (int i = 0; i < thread_list.size(); i++) {
		thread_list[i] = thread{ greeting, i };
	}
	t1.join();
	for (int i = 0; i < thread_list.size(); i++) {
		thread_list[i].join();
	}
	this_thread::sleep_for(chrono::seconds(4));
	int last = time(NULL) - nowtime;
	cout << "last time:" << last << endl;
}

