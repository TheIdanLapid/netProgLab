/*
 * Dispatcher.h
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#ifndef DISPATCHER_H_
#define DISPATCHER_H_
#include "TCPSocket.h"
#include <vector>
namespace networking {

class DispatcherHandler{
public:
	virtual void managePeerSession(TCPSocket* peer1, TCPSocket* peer2) = 0;
	virtual ~DispatcherHandler();
};

class Dispatcher {
	vector<TCPSocket*> peers;
	DispatcherHandler* handler;


public:
	void addPeer(TCPSocket* peer);
	void removePeer(TCPSocket* peer);
	void close();
	Dispatcher(DispatcherHandler* handler);
	virtual ~Dispatcher();
};

} /* namespace networking */

#endif /* DISPATCHER_H_ */
