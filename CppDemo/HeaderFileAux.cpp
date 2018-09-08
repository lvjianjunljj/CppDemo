#include "stdafx.h"
namespace HeaderFileAux {
	string test() {
		return "test method in namespace TestCppHeaderFileAux";
	}
}

string test()
{
	return "test method outside";
}

