/*
 * Socket.cpp
 *
 *  Created on: Jun 14, 2017
 *      Author: user
 */

#include "Socket.h"

namespace networking {

Socket::Socket(){
	socket_fd = socket (AF_INET, SOCK_STREAM, 0);
	int optval;

	optval = 1;

	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
}
Socket::Socket(int type) {
	socket_fd = socket (AF_INET, type, 0);
	int optval;

	optval = 1;

	setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
	if(socket_fd < 0)
	{
		perror("Error: Didn't create a socket.");
	}
}

int Socket::bind(int port){
	struct sockaddr_in s_in;
	bzero((char *) &s_in, sizeof(s_in));
	s_in.sin_family = (short)AF_INET;
	s_in.sin_addr.s_addr = htonl(INADDR_ANY);
	s_in.sin_port = htons(port);

	fflush(stdout);
	if( ::bind(socket_fd, (struct sockaddr *)&s_in, sizeof(s_in))<0)
	{
		perror("Error: didn't bind.");
		return -1;
	}
	return 1;
}

int Socket::connect(string ip, int port){

	bzero(&remote, sizeof(remote));

	remote.sin_family = AF_INET;
	remote.sin_addr.s_addr=inet_addr(ip.data());
	remote.sin_port = htons(port);


	//		sleep(1);

	if(::connect(socket_fd, (struct sockaddr*)&remote, sizeof(remote))<0)
	{
		perror("client: Error: Didn't connect to server.");
		return -1;
	}
	return 1;
}

int Socket::read(char* buff, int size) {
	return ::read(socket_fd,buff,size);

}
int Socket::write(const string& msg) {
	return ::write(socket_fd,msg.c_str(),msg.size());
}

void Socket::close() {
	::close(socket_fd);
}

Socket::~Socket() {
	// TODO Auto-generated destructor stub
}

} /* namespace networking */
