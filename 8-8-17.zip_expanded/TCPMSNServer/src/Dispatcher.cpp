/*
 * Dispatcher.cpp
 *
 *  Created on: Jul 3, 2017
 *      Author: user
 */

#include "Dispatcher.h"
using namespace std;
namespace networking {

Dispatcher::Dispatcher(DispatcherHandler* handler) {
	this->handler = handler;
	this->peers = new MTCPListener();
	this->peersOn = false;
	this->closed = false;
	mutex = PTHREAD_MUTEX_INITIALIZER;
	peeread = false; //make sure the command is read only one time
}

void Dispatcher::addPeer(TCPSocket* peer){
	Guard guard(&mutex);
	peers->add(peer);
	cout<<"Added peer with port: "<<peer->getPort()<<" to dispacher's peers list"<<endl;
	if(!peersOn){
		peersOn = true;
		start();
//		waitForThread();
	}
}

bool Dispatcher::removePeer(TCPSocket* peer){
	if (peer==NULL)
	{
		cout<<"PEER IS NULL!"<<endl;
		return false;
	}
	int i = 0;
	tSockets::iterator iter = peers->sockets.begin();
	for(;iter!= peers->sockets.end();iter++)
	{
		if (*iter!=NULL)
		{
			TCPSocket* curr = *iter;
			cout<<curr<<" is the current socket with port: "<<curr->getPort()<<endl;
			if(curr->getIP()==peer->getIP() && curr->getPort()==peer->getPort()){
				cout<<"Peer index to delete: "<<i<<endl;
				cout<<"Peer to delete: "<<peers->sockets[i]<<endl;
				Guard guard(&mutex);
				peers->sockets.erase(peers->sockets.begin()+i);
				if(peers->sockets.size()==0){
					peersOn = false;
				}
				return true;
			}
			i++;
		}
		else
		{
			cout<<"dispacher.cpp-> iter null"<<endl;
		}
	}
	return false;

}

void Dispatcher::run(){
	//while(peersOn){
//	bool peeread = false; //make sure the command is read only one time
//	while (peersOn&& !peeread){
	while(!closed){
		if (peersOn&& !peeread){
			TCPSocket* peer = peers->listen(4);

			if(!peer){ //timeout without any peer ready
				cout<<"there is no ready peer"<<endl;
			}
			else
			{
				int command = readCommand(peer);
				cout<<"COMMAND FROM PEER:"<<command<<endl;
				if(command>0){
					cout<<"GOT COMMAND FROM PEER"<<endl;
					peeread = true;
				}
				int len = 0;
				string ip;
				char buff[100];
				int rc = 0;
				int port = 0;
				string data;
				switch(command){

				case OPEN_SESSION_WITH_PEER:
					cout<<"Got open session command"<<endl;
					waitForThread();
					cout<<"Done waiting!"<<endl;
					rc = peer->recv((char*)&len,4); //recv msg length
					if(rc<0){
						cerr<<"Fail to read command from socket"<<endl;
					}
					len = ntohl(len);
					rc = peer->recv(buff,len); //recv msg
					if(rc<0){
						cerr<<"Fail to read command from socket"<<endl;
					}
					buff[len] = '\0';
					data = buff;


					ip = data.substr(0,data.find_first_of(":"));
					port = atoi((data.substr(data.find_first_of(":") + 1)).c_str());
					int index = getPeerIndex(ip,port);
					if(index!=-1){
						int com = handler->managePeerSession(peer,peers->sockets[index]);
						if(com==SESSION_ESTABLISHED){
							cout<<"SESSION_ESTABLISHED"<<endl;
							sendFeedback(peer,6);
							removePeer(peer); //remove the peer that requested to open session
							sendFeedback(peers->sockets[index],6);
							removePeer(peers->sockets[index]);//remove the other peer
						}
						else if(com==SESSION_REFUSED){
							cout<<"SESSION_REFUSED"<<endl;
							sendFeedback(peer,5);
						}
					}
					else
					{
						cout<<"Peer not found!"<<endl;
						sendFeedback(peer,5);
					}
					break;
				}
			}
		}
//		cout<<"!closed"<<endl;
	}
	cout<<"end of dispatcher run loop"<<endl;
}
int Dispatcher::getPeerIndex(string ip,int port){
	return peers->getSocketIndex(ip,port);
}

int Dispatcher::sendFeedback(TCPSocket* peer, int command){
	int cmdNet = htonl(command);
	int res = peer->write((char*)&cmdNet,4); //the command int from the protocol

	if (res<4)
	{
		cout<<"Could not send feedback! "<<command<<endl;
		return -1;
	}
	return res;
}

int Dispatcher::readCommand(TCPSocket* peer){
	int rcvCmd = 0;
	int rc = peer->recv((char*)&rcvCmd,4);
	if(rc!=4){
		cerr<<"fail to read command from peer"<<endl;
		return -1;
	}
	return ntohl(rcvCmd);
}

void Dispatcher::close(){
	closed = true;
	Guard guard(&mutex);
	if(!peers->sockets.empty())
		peers->sockets.clear();
}

Dispatcher::~Dispatcher() {
	cout<<"dispacher closed!"<<endl;
}

} /* namespace networking */
