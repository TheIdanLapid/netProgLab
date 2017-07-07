/*
 * TCPMSNServer.h
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#ifndef TCPMSNSERVER_H_
#define TCPMSNSERVER_H_
#include "Server.h"
#include "Dispatcher.h"
#include "BrokerManager.h"

namespace networking {

class TCPMSNServer: public ServerHandler, DispatcherHandler, BrokerManagerHandler {
	Server* server;
	Dispatcher * dispatcher;
	BrokerManager * brokerMng;

public:
	TCPMSNServer();
	virtual void handlePeer(TCPSocket* peer);
	virtual void managePeerSession(TCPSocket* peer1, TCPSocket* peer2);
	virtual void handleReturnedPeer(TCPSocket* peer);
	virtual ~TCPMSNServer();
};

} /* namespace networking */

#endif /* TCPMSNSERVER_H_ */
