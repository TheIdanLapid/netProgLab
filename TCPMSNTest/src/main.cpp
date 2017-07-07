//============================================================================
// Name        : TCPMSNTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "TCPMSNClientTest.h"
using namespace std;
using namespace networking;
int main() {
	bool passFlag = true;
	TCPMSNClientTest clientTest;
	if(!clientTest.test()){
		cout <<"Test Failed"<< endl;
		passFlag = false;
	}
	else
		cout <<"Passed Test successfully"<< endl;
	cout << passFlag << endl; // prints !!!Hello World!!!
	return 0;
}

