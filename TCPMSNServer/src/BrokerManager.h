/*
 * BrokerManager.h
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#ifndef BROKERMANAGER_H_
#define BROKERMANAGER_H_
#include "TCPSocket.h"
#include "Broker.h"
#include <vector>

namespace networking {

class BrokerManagerHandler{
public:
	virtual void handleReturnedPeer(TCPSocket* peer) = 0;
	virtual ~BrokerManagerHandler();
};


class BrokerManager {
	vector<Broker*> brokers;
	BrokerManagerHandler* handler;
public:
	BrokerManager(BrokerManagerHandler* handler);
	bool createBroker(TCPSocket* peer1, TCPSocket* peer2);
	void releasePeer(TCPSocket* peer);
	void deleteBroker(Broker* broker);
	virtual ~BrokerManager();
};

} /* namespace networking */

#endif /* BROKERMANAGER_H_ */
