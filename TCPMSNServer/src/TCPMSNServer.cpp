/*
 * TCPMSNServer.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "TCPMSNServer.h"
namespace networking {

TCPMSNServer::TCPMSNServer(){

	server = new Server(this);
	dispatcher = new Dispatcher(this);
	brokerMng = new BrokerManager(this);
}
void TCPMSNServer::handlePeer(TCPSocket* peer){
	this-> dispatcher->addPeer(peer);
}

void TCPMSNServer::managePeerSession(TCPSocket* peer1, TCPSocket* peer2){
	if(this->brokerMng->createBroker(peer1,peer2)){
		dispatcher->removePeer(peer1);
		dispatcher->removePeer(peer2);
	}

}

void TCPMSNServer::handleReturnedPeer(TCPSocket* peer){
	this-> dispatcher->addPeer(peer);

}


TCPMSNServer::~TCPMSNServer() {
	delete(server); //?
	delete(dispatcher); //?
	delete(brokerMng); //?
}

} /* namespace networking */
