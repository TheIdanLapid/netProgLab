/*
 * TCPMSNServerTest.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: user
 */

#include "TCPMSNServerTest.h"

using namespace std;
namespace networking {

TCPMSNServerTest::TCPMSNServerTest() {
	server = NULL;
	handler1 = new CLIHandler();
	handler2 = new CLIHandler();
	client1 = new TCPMSNClient(handler1);
	client2 = new TCPMSNClient(handler2);
}

void TCPMSNServerTest::run() {
	server = new TCPMSNServer();

//	sleep(2);
	int success = 0;

	success = client1->connect(MSNGR_IP);

	if (success==0)
	{
		cout<<"client1 didn't connect!"<<endl;
		delete(this);
	}
//	sleep(2);

	success = client2->connect(MSNGR_IP);
	if (success==0)
	{
		cout<<"client2 didn't connect!"<<endl;
		delete(this);
	}

//	sleep(4);
	cout<<"Port: "<<client1->getPort()<<" is opening session with port: "<<client2->getPort()<<endl;
	success = client1->openSession(MSNGR_IP,client2->getPort());
	if (success==0)
	{
		cout<<"client1 didn't open session!"<<endl;
		delete(this);
	}

//	sleep(2);
	client1->sendMessage("message from 1 to 2");
//	sleep(2);
	cout<<"lastRcvdMsg of 1: "<<handler1->lastRcvdMsg<<endl;
//	sleep(2);

	client2->sendMessage("message from 2 to 1");
	sleep(2);

	cout<<"lastRcvdMsg of 2: "<<handler2->lastRcvdMsg<<endl;
//	if (success==0)
//	{
//		cout<<"client1 didn't send msg!"<<endl;
//		delete(this);
//	}
//	while(true){}

	cout<<"~~~~~~~~~~end of test~~~~~~~~~~~~"<<endl;

	client1->closeSession();
	client1->disconnect();
	client2->disconnect();
}

bool TCPMSNServerTest::testTCPMSNServer() {
	cout<<"testing server..."<<endl<<flush;
	MThread::start();
	waitForThread();
	cout<<"end of the test"<<endl;
	return true;
}

TCPMSNServerTest::~TCPMSNServerTest() {
	delete(server);
	cout<<"TCPMSNServerTEST closed!"<<endl;
}

} /* namespace networking */
