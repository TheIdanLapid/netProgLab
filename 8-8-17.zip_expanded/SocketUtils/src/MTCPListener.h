/*
 * MTCPListener.h
 *
 */

#ifndef MTCPLISTENER_H_
#define MTCPLISTENER_H_

//#include <sys/socket.h>
#include "TCPSocket.h"
#include <vector>

using namespace std;
namespace networking {

class MTCPListener {
	typedef vector<TCPSocket*> tSockets;
public:
	vector<TCPSocket*> sockets;
	/**
	 * add socket to listen to
	 */
	void add(TCPSocket* socket);
	int getSocketIndex(string ip, int port);

//	void add(vector<TCPSocket*> sockets);
	TCPSocket* listen(int timeout);

};

} /* namespace networking */

#endif /* MTCPLISTENER_H_ */
