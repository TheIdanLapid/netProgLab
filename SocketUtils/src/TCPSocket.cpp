/*
 * TCPPSocket.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: Idan & Shdema
 */

#include "TCPSocket.h"
//#include <iostream>
//#include <sys/types.h>
//#include <netinet/in.h>
//#include <inttypes.h>
//#include <arpa/inet.h>
//#include <netdb.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <strings.h>
//#include <unistd.h>
//#include <stdio.h>
//#include <string>
//#include <sstream>
using namespace std;
using namespace networking;


	TCPSocket::TCPSocket(int port):Socket(SOCK_STREAM) {
		if(port!=9999)
			bind(port);
//		socket_fd = ::socket(AF_INET, SOCK_STREAM, 0);
//
//		int optval;
//
//		optval = 1;
//		setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
//
//		if(socket_fd < 0)
//		{
//			perror("Error: Didn't create a socket.");
//			close();
//		}
//		bzero((char *) &serv_name, sizeof(serv_name));
//
//		serv_name.sin_family = (short)AF_INET;
//		serv_name.sin_addr.s_addr = htonl(INADDR_ANY);
//		serv_name.sin_port = htons(port);
//
//		if(::bind(socket_fd, (struct sockaddr *)&serv_name, sizeof(serv_name))<0)
//		{
//			perror("server: Error: didn't bind.");
//		}
	}

	TCPSocket::TCPSocket(string peerIp, int port):Socket(SOCK_STREAM) {
		if(port!=9999)
			connect(peerIp,port);
//		socket_fd = ::socket(AF_INET, SOCK_STREAM, 0);
//		int optval;
//
//		optval = 1;
//
//		setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
//
//
//		if(socket_fd < 0)
//		{
//			perror("client: Error: Didn't create a socket.");
//			close();
//		}
//		bzero(&cli_name, sizeof(cli_name));
//
//		cli_name.sin_family = AF_INET;
//		cli_name.sin_addr.s_addr=inet_addr(peerIp.c_str());
//		cli_name.sin_port = htons(port);
//
//
////		sleep(1);
//
//		if(::connect(socket_fd, (struct sockaddr*)&cli_name, sizeof(cli_name))<0)
//		{
//			perror("client: Error: Didn't connect to server.");
//		}
	}
	TCPSocket::TCPSocket(int socket_fd,struct sockaddr_in serv_name,struct sockaddr_in cli_name) {

			this->socket_fd = socket_fd;
			this->local = serv_name;
			this->remote = cli_name;

		}


	TCPSocket* TCPSocket::listenAndAccept() {
		TCPSocket* tcp = new TCPSocket(this->socket_fd, this->local, this->remote);
		::listen(socket_fd,1);
		size_t len = sizeof(local);
		tcp->socket_fd = ::accept(socket_fd,(struct sockaddr *)&local,(unsigned int*)&len);
		if (tcp->socket_fd<0)
		{
			perror("Error creating socket");
			close();
		}
//		return new TCPSocket(connect_sock,serv_name.sin_port,cli_name.sin_port, inet_ntoa(cli_name.sin_addr));
		return tcp;
	}

	int TCPSocket::recv(char* buffer, int length) {
		int recv = ::read(socket_fd,buffer,length);
		return recv;
	}

	int TCPSocket::send(const string& msg) {
		int send = ::write(socket_fd,msg.c_str(),msg.size());
		return send;
	}

	int TCPSocket::write(const char* msg,int size){
		return ::write(socket_fd,msg,size);
	}

//	void TCPSocket::close() {
//		::close(this->socket_fd);
//	}

	string TCPSocket::fromAddr() {
		return inet_ntoa(local.sin_addr);

	}
	int TCPSocket::getSocketFd() const {
		return this->socket_fd;
	}

	TCPSocket::~TCPSocket() {
	}
