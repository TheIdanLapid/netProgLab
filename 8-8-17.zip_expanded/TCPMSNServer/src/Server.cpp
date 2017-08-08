/*
 * Server.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "Server.h"
using namespace std;
namespace networking {

Server::Server(ServerHandler* handler) {
	this->handler = handler;
	socket = new TCPSocket(MSNGR_PORT);
	exitFromServer = false;
	start();
}

void Server::run() {
	while (!exitFromServer) {
		cout<<"Server is running..."<<endl;
		TCPSocket* peer = socket->listenAndAccept();
		cout<<peer->getPort()<<" REMOTE PEER PORT"<<endl;
		if (peer == NULL) {
			cout<<"can't connect the peer"<<endl;
			break;
		}

		handler->handlePeer(peer);
	}
}

void Server::exit() {
	socket->close();
//	waitForThread();
	delete socket;
}

Server::~Server() {
	cout<<"Server.cpp closed!"<<endl;
//	delete(handler); //?
}

} /* namespace networking */
