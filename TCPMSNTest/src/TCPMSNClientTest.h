/*
 * TCPMSNClientTest.h
 *
 *  Created on: Jun 18, 2017
 *      Author: user
 */

#ifndef TCPMSNCLIENTTEST_H_
#define TCPMSNCLIENTTEST_H_
#include "TCPMSNClient.h"
#include <iostream>
#include <unistd.h>
using namespace std;
namespace networking {

class ClientHandlerTest: public TCPMSNClientHandler{
public:
	ClientHandlerTest(){

	}
	string lastRcvdMsg;
	virtual void onMessageRecieved(string message);
	virtual void onOpenSession(string ip, int port);
	virtual void onClosedSession();
	virtual ~ClientHandlerTest();
};


class TCPMSNClientTest {
public:
	TCPMSNClientTest();
	bool test();
	virtual ~TCPMSNClientTest();
};

} /* namespace networking */

#endif /* TCPMSNCLIENTTEST_H_ */
