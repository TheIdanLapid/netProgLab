/*
 * MTCPListener.cpp
 */

#include "MTCPListener.h"

namespace networking {
void MTCPListener::add(TCPSocket* socket){
	sockets.push_back(socket);

}

void MTCPListener::add(vector<TCPSocket*> sockets){
	this->sockets = sockets;
}

TCPSocket* MTCPListener::listen(){
	fd_set set;
	int nfd = 0;
	FD_ZERO(&set);
	tSockets::iterator iter = sockets.begin();
	for(;iter!= sockets.end();iter++){
		TCPSocket* sock = *iter;
		int fd = sock->getSocketFd();
		FD_SET(fd,&set);
		if (fd >= nfd){
			nfd = fd+1;
		}
	}

	int rc = select(nfd, &set,NULL,NULL,NULL); //last param is TIMEOUT
	if (rc<1){
		FD_ZERO(&set);
		return NULL;
	}

	iter = sockets.begin();
	for(;iter!= sockets.end();iter++){
		TCPSocket* sock = *iter;
		int fd = sock->getSocketFd();
		if(FD_ISSET(fd,&set)){
			FD_ZERO(&set);
			return sock;
		}
	}
	FD_ZERO(&set);
	return NULL;
}


} /* namespace networking */
