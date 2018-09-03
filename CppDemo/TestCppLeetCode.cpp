#include "stdafx.h"
class Solution {
public:
	bool judgeCircle(string moves) {
		int leftCount = 0;
		int upCount = 0;
		for (char c : moves) {
			if (c == 'U') {
				upCount++;
			}
			else if (c == 'D') {
				upCount--;
			}
			else if (c == 'L') {
				leftCount++;
			}
			else {
				leftCount--;
			}
		}
		return leftCount == 0 && upCount == 0;
	}
	// make use of the key: switch
	bool judgeCircle2(string moves) {
		int v = 0;
		int h = 0;
		for (char ch : moves) {
			switch (ch) {
			case 'U': v++; break;
			case 'D': v--; break;
			case 'R': h++; break;
			case 'L': h--; break;
			}
		}
		return v == 0 && h == 0;
	}
};

int main() {
	Solution s;
	cout << s.judgeCircle("UDLR") << endl;
	system("pause");
	return 1;
}