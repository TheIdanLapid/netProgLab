/*
 * Socket.h
 *
 *  Created on: Jun 14, 2017
 *      Author: user
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "MThread.h"
#include "FileInterface.h"
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include "Socket.h"
using namespace std;

namespace networking {

class Socket : public FileInterface
{
public:
	struct sockaddr_in local, remote;
	int socket_fd;
	Socket();
	Socket(int type);
	int bind(int port);
	virtual int connect(string ip, int port);
	virtual int read(char* buff, int size);
	virtual int write(const string& msg);
	virtual void close();
	virtual ~Socket();
};

} /* namespace networking */

#endif /* SOCKET_H_ */
