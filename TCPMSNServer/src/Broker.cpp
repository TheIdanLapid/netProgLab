/*
 * Broker.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "Broker.h"

namespace networking {

Broker::Broker(TCPSocket* peer1, TCPSocket* peer2, BrokerManager* parent){
	this->parent = parent;
	this->peer1 = peer1;
	this->peer2 = peer2;

}

void Broker::run(){
	while(true){

	}
//	parent->releasePeer(peer1);
//	parent->releasePeer(peer2);
//	parent->deleteBroker(this);
	delete this;
}


Broker::~Broker() {}

} /* namespace networking */
