/*
 * Server.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "Server.h"

namespace networking {

Server::Server(ServerHandler* handler) {
	this->handler = handler;
}

Server::~Server() {
	delete(handler); //?
}

} /* namespace networking */
