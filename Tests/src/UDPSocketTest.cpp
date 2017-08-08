//============================================================================
// Name        : Test.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "UDPSocket.h"
#include "UDPSocketTest.h"

using namespace std;
using namespace networking;

UDPSocketTest::UDPSocketTest() {
	// TODO Auto-generated constructor stub

}

UDPSocketTest::~UDPSocketTest() {
	// TODO Auto-generated constructor stub

}

bool UDPSocketTest::testUDPSocket(){
	//create UDP server
		UDPSocket* server = new UDPSocket(3435);
	//create udp client
		UDPSocket* client = new UDPSocket();



	//send a message from the client to the server
	string msg = "checking sendto and recv";
	client->connect("127.0.0.1", 3435);
	client->write(msg);
//	client->sendTo(msg,"127.0.0.1", 3435);
	char buf[100];
	memset((void*)buf,0,100);


	cout<<"the message : "<<msg<<" was sent"<<endl;

	// read the message by the server
	int cc = server->recv(buf, 100);

	if (cc<0)
		{
			perror("error receiving a message");
			return false;
		}
	if (cc != (int)msg.length()){
			perror("wrong size");
			return false;
	}
	// compare the message sent with the message received
	if (msg != buf){
			perror("wrong message");
			return false;
		}
	cout<<"the message : "<<buf<<" received"<< endl;


	//test the reply and fromaddr methods
		server->reply("checking reply");
		memset((void*)buf,0,100);
		client->recv(buf, 100);
		cout<<"the message : "<<buf<<" received"<< endl;

		cout<<"address = "<<server->fromAddr()<<endl;
		cout<<"address = "<<client->fromAddr()<<endl;


	//close all sockets


	//clear mem

	return true;
}
