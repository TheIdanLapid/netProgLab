/*
 * TCPMSNClientTest.cpp
 *
 *  Created on: Jun 18, 2017
 *      Author: user
 */

#include "TCPMSNClientTest.h"
namespace networking {

	void ClientHandlerTest::onMessageRecieved(string message){
		lastRcvdMsg = message;
		cout<<"message: "+ message<<endl;
	}
	void ClientHandlerTest::onOpenSession(string ip, int port){
		lastRcvdMsg = "onOpenSession";
		cout<<"onOpenedSession"<<endl;
	}
	void ClientHandlerTest::onClosedSession(){
		lastRcvdMsg = "onClosedSession";
		cout<<"onClosedSession"<<endl;
	}
	ClientHandlerTest::~ClientHandlerTest(){}

	TCPMSNClientTest::TCPMSNClientTest() {
		// TODO Auto-generated constructor stub

	}

	bool TCPMSNClientTest::test(){

		//create client1
		cout<<"create client1:"<<endl;
		ClientHandlerTest handler1;
		ClientHandlerTest handler2;
		TCPMSNClient client1(&handler1);

		//connect client1 to the server
		cout<<"connect client1 to server:"<<endl;
		int rc1 = client1.connect("127.0.0.1");
		if(rc1<0){
			cerr<<"client1 failed to connect" <<endl;
			return false;
		}

		//create client2
		cout<<"create client2:"<<endl;
		TCPMSNClient client2(&handler2);

		//connect client2 to the server
		cout<<"connect client2 to server:"<<endl;
		int rc2 = client2.connect("127.0.0.1");
		if(rc2<0){
			cerr<<"client2 failed to connect" <<endl;
			return false;
		}

		sleep(5);
		//open session from client1 to client2
		cout<<"open session from client1 to client2:"<<endl;
		int client2Port = client2.getPort();
		client1.openSession("127.0.0.1",client2Port);

		//check that the session was opened successfully

		sleep(5); // give the server time to open the session between the two peers
		if(handler1.lastRcvdMsg.compare("onOpenSession")!=0){
			cerr<<"client1 failed to open session"<<endl;
			return false;
		}
		sleep(5);
		if(handler2.lastRcvdMsg.compare("onOpenSession")!=0){
				cerr<<"client2 failed to open session"<<endl;
				return false;
		}
		cout<<"client1 and client2 have opened sessions"<<endl;

		//send msg from client1 to client2
		cout<<"send msg from client1 to client2:"<<endl;
		client1.sendMessage("dlthjrtkg");

		//compare msg
		cout<<"compare the recieved msg in client2 to the msg was sent from client1:"<<endl;
		sleep(5);
		if(handler2.lastRcvdMsg.compare("dlthjrtkg")!=0){
			cerr<<"client1 failed to send msg to client2"<<endl;
			return false;
		}

		//send msg from client2 to client1
		cout<<"send msg from client2 to client1:"<<endl;
		client2.sendMessage("TFGERYE");

		//compare msg
		cout<<"compare the recieved msg in client1 to the msg was sent from client2:"<<endl;
		sleep(5);
		if(handler1.lastRcvdMsg.compare("TFGERYE")!=0){
			cerr<<"client2 failed to send msg to client1"<<endl;
			return false;
		}
		//close session
		cout<<"close session from client1 to client2:"<<endl;
		client1.closeSession();

		sleep(5); // give the server time to open the session between the two peers
		if(handler1.lastRcvdMsg.compare("onClosedSession")!=0){
			cerr<<"client1 failed to close the session"<<endl;
			return false;
		}
		if(handler2.lastRcvdMsg.compare("onClosedSession")!=0){
			cerr<<"client2 failed to close the session"<<endl;
			return false;
		}

		//disconnect client1
		cout<<"disconnect client1:"<<endl;
		client1.disconnect();

		//disconnect client2
		cout<<"disconnect client2:"<<endl;
		client2.disconnect();

		//close clients
		//close client1
		cout<<"close client1"<<endl;
		client1.exit();

		//close client2
		cout<<"close client2"<<endl;
		client2.exit();

		return true;
	}

	TCPMSNClientTest::~TCPMSNClientTest() {
	}

} /* namespace networking */
