/*
 * BrokerManager.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "BrokerManager.h"

namespace networking {

BrokerManager::BrokerManager(BrokerManagerHandler* handler){
	this->handler = handler;

}

bool BrokerManager::createBroker(TCPSocket* peer1, TCPSocket* peer2){
	Broker * broker = new Broker(peer1,peer2,this);
	if(broker!=NULL){
		brokers.push_back(broker); //add the broker to the brokers list
		return true;
	}
	return false;
}

void BrokerManager::releasePeer(TCPSocket* peer){
	handler->handleReturnedPeer(peer);
}

void BrokerManager::deleteBroker(Broker* broker){
	bool found = false;
	for(unsigned int i=0; !found && i<brokers.size();i++){
		Broker* curr = brokers[i];
		if(curr==broker){
			brokers.erase(brokers.begin()+i);
			found = true;
		}
	}
	//remove the broker from the brokers list
}

BrokerManager::~BrokerManager() {
	if(!brokers.empty())
		brokers.clear(); //?
	delete(handler); //?
}

} /* namespace networking */
