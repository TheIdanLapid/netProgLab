/*
 * Broker.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "Broker.h"
#include "BrokerManager.h"
using namespace std;
namespace networking {

Broker::Broker(TCPSocket* peer1, TCPSocket* peer2, BrokerManager* parent){
	cout<<"BROKER CREATED"<<endl;
	this->parent = parent;
	this->peers = new MTCPListener();
	this->peers->sockets.push_back(peer1);
	this->peers->sockets.push_back(peer2);
	brokerOn = true;
//	msg = malloc();
	to = NULL;
	from = NULL;
	MThread::start();
//	waitForThread();
}

int Broker::sendMessage(TCPSocket* to,int len, const char* buff){
	if (buff != NULL)
	{
		int res = to->write((char*)&len,4); //the length of the message
		cout<<"Broker.cpp-> int size: "<<res<<endl;
		if (res<4)
			return -1;
		res = to->write(buff,len); //the message
		cout<<"Broker.cpp-> message size: "<<res<<endl;
		if (res<4)
			return -1;
	}
	return 0;
}

int Broker::readMessage(TCPSocket* from){
	memset(msg,0,1024);
	int rcvCmd = 0;
	int rc = from->recv((char*)&rcvCmd,4);
	if(rc!=4){
		cerr<<"fail to read command from socket"<<endl;
		return -1;
	}
	int command = ntohl(rcvCmd);
	int len = 0;
	char buff[1024];
	rc = 0;
	switch(command){
		case SEND_MSG_TO_PEER:
			rc = from->recv((char*)&len,4);
			if(rc<0){
				cerr<<"Fail to read command from socket"<<endl;
			}
			len = ntohl(len);
			rc = from->recv(buff,len);
			if(rc<0){
				cerr<<"Fail to read command from socket"<<endl;
			}
			buff[len] = '\0';
			memcpy(buff,msg,1024);
			cout<<"MESSAGE RECEIVED: "<<msg<<endl;
			break;

		case EXIT:
			parent->handler->handleReturnedPeer(to);
			brokerOn = false;
			break;

		case CLOSE_SESSION_WITH_PEER:
			parent->handler->handleReturnedPeer(from);
			parent->handler->handleReturnedPeer(to);
			brokerOn = false;
			break;
	}
	return 0;
}


void Broker::run(){
	while(brokerOn){
		cout<<"Broker is on! with "<<peers->sockets.size()<<" peers."<<endl;

		from = this->peers->listen(3);
		while (from==NULL)
			this->peers->listen(3);
		cout<<from<<" (is from)"<<endl;
//		printf("%s %d s[0]=%x\n", __FILE__, __LINE__,peers->sockets[0]);
//		printf("%s %d from=%x\n", __FILE__, __LINE__, from);
		if(peers->sockets[0]->getIP()==from->getIP() && peers->sockets[0]->getPort()==from->getPort()){
			to = this->peers->sockets[1];
		}
		else{
			to = this->peers->sockets[0];
		}
		cout<<"From port: "<<from->getPort()<<endl;
		cout<<"To port: "<<to->getPort()<<endl;
		int result = readMessage(from);
		if(result == -1){
			cout<<"sorry, couldn't read the message - please try again"<<endl;
		}
		else{
			result = sendMessage(to,1024,msg);
			if(result == -1){
				cout<<"sorry, couldn't send the message - please try again"<<endl;
			}
		}
	}
	peers->sockets.clear();
//	parent->deleteBroker(this);
//	delete this;
	cout<<"brokeroff"<<endl;
}

Broker::~Broker() {
	cout<<"Broker closed!"<<endl;
	peers->sockets.clear();
	parent->deleteBroker(this);
}
} /* namespace networking */
