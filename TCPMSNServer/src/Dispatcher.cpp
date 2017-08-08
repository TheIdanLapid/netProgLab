/*
 * Dispatcher.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "Dispatcher.h"

namespace networking {

Dispatcher::Dispatcher(DispatcherHandler* handler) {
	this->handler = handler;
}

void Dispatcher::addPeer(TCPSocket* peer){
	peers.push_back(peer);
}

void Dispatcher::removePeer(TCPSocket* peer){
	bool found = false;
	for(unsigned int i=0; !found && i<peers.size();i++){
		TCPSocket* curr = peers[i];
		if(curr==peer){
			peers.erase(peers.begin()+i);
			found = true;
		}
	}
}

void Dispatcher::close(){
	if(!peers.empty())
		peers.clear();
}

Dispatcher::~Dispatcher() {
	delete(handler); //?
}

} /* namespace networking */
