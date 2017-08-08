/*
 * MTCPListener.cpp
 */

#include "MTCPListener.h"

namespace networking {
void MTCPListener::add(TCPSocket* socket){
	sockets.push_back(socket);
	cout<<"socket "<<socket<<" added to sockets vector!"<<endl;
}

//void MTCPListener::add(vector<TCPSocket*> sockets){
//	this->sockets = sockets;
//}

TCPSocket* MTCPListener::listen(int timeout){
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
	struct timeval time;
	time = (struct timeval){timeout};
	int rc = select(nfd, &set,NULL,NULL,&time); //last param is TIMEOUT
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

int MTCPListener::getSocketIndex(string ip, int port) {
	int i = 0;
	tSockets::iterator iter = sockets.begin();
	for(;iter!= sockets.end();iter++){
		TCPSocket* curr = *iter;
		cout<<i<<endl;
		cout<<curr<<" is the current socket with port: "<<curr->getPort()<<endl;
		if(curr->getIP()==ip && curr->getPort()==port){
			cout<<"Peer index: "<<i<<endl;
			cout<<"Peer: "<<sockets[i]<<endl;
			return i;
		}

		i++;
	}
	return -1;
}


} /* namespace networking */


