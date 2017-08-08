/*
 * Broker.h
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#ifndef BROKER_H_
#define BROKER_H_
#include "MThread.h"
#include "TCPSocket.h"

namespace networking {

class BrokerManager;

class Broker: public MThread {
	BrokerManager* parent;
	TCPSocket* peer1;
	TCPSocket* peer2;
public:
	Broker(TCPSocket* peer1, TCPSocket* peer2, BrokerManager* parent);
	virtual void run();
	virtual ~Broker();
};

} /* namespace networking */

#endif /* BROKER_H_ */
