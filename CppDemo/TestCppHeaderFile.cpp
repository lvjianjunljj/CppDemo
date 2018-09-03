#include "stdafx.h"
#include "TestCppHeaderFileAux.h"
using std::cout;
using std::string;
using std::stringstream;

void testMethod(int i = 3) {
	cout << TestCppHeaderFileAux::test() << endl;
	cout << test() << endl;
}
