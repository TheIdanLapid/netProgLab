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
	printf("%s %d\n",__FILE__, __LINE__);
	sleep(2);
	int success = 0;
	printf("%s %d\n",__FILE__, __LINE__);
	success = client1->connect(MSNGR_IP);
	printf("%s %d\n",__FILE__, __LINE__);
	if (success==0)
	{
		cout<<"client1 didn't connect!"<<endl;
		delete(this);
	}
	sleep(2);
	printf("%s %d\n",__FILE__, __LINE__);
	success = client2->connect(MSNGR_IP);
	if (success==0)
	{
		cout<<"client2 didn't connect!"<<endl;
		delete(this);
	}
	printf("%s %d\n",__FILE__, __LINE__);
	sleep(4);
	cout<<"Port: "<<client1->getPort()<<" is opening session with port: "<<client2->getPort()<<endl;
	success = client1->openSession(MSNGR_IP,client2->getPort());
	if (success==0)
	{
		cout<<"client1 didn't open session!"<<endl;
		delete(this);
	}
	printf("%s %d\n",__FILE__, __LINE__);
	sleep(2);
	client1->sendMessage("message from 1 to 2");
	sleep(2);
	printf("%s %d %x\n",__FILE__, __LINE__, handler1->lastRcvdMsg);
	cout<<"lastRcvdMsg of 1: "<<handler1->lastRcvdMsg<<endl;
	sleep(2);
	printf("%s %d\n",__FILE__, __LINE__);
	client2->sendMessage("message from 2 to 1");
	sleep(2);
	printf("%s %d\n",__FILE__, __LINE__);
	cout<<"lastRcvdMsg of 2: "<<handler2->lastRcvdMsg<<endl;
//	if (success==0)
//	{
//		cout<<"client1 didn't send msg!"<<endl;
//		delete(this);
//	}
//	while(true){}
	printf("%s %d\n",__FILE__, __LINE__);
	cout<<"~~~~~~~~~~end of test~~~~~~~~~~~~"<<endl;
	printf("%s %d\n",__FILE__, __LINE__);
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
