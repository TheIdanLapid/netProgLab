/*
 * main.cpp
 *
 *  Created on: May 8, 2017
 *      Author: Shdema & Idan
 */
#include "TCPSocketTest.h"
#include "UDPSocketTest.h"

using namespace std;
using namespace networking;

int main(int argc, char **argv) {
	TCPSocketTest tcpTest;
	UDPSocketTest udpTest;

	if(udpTest.testUDPSocket())
	{
		cout<<"UDP TEST OK"<<endl;
	}
	else
		cout<<"UDP TEST FAIL"<<endl;

	if(tcpTest.testTCPSocket())
	{
		cout<<"TCP TEST OK"<<endl;
	}
	else
		cout<<"TCP TEST FAIL"<<endl;

}



