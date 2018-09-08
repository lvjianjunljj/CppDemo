#include "stdafx.h"
#include "HeaderFileAux.h"
using std::cout;
using std::string;
using std::stringstream;

void main_HeaderFile(int i = 3) {
	cout << HeaderFileAux::test() << endl;
	cout << test() << endl;
}
