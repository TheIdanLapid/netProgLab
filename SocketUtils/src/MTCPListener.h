/*
 * MTCPListener.h
 *
 */

#ifndef MTCPLISTENER_H_
#define MTCPLISTENER_H_

#include <sys/socket.h>
#include "TCPSocket.h"
#include <vector>

using namespace std;
namespace networking {

class MTCPListener {
	typedef vector<TCPSocket*> tSockets;
	vector<TCPSocket*> sockets;

public:
	/**
	 * add socket to listen to
	 */
	void add(TCPSocket* socket);
	void add(vector<TCPSocket*> sockets);
	TCPSocket* listen();

};

} /* namespace networking */

#endif /* MTCPLISTENER_H_ */
