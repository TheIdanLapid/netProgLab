/*
 * CLIHandler.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: user
 */

#include "CLIHandler.h"

namespace networking {

CLIHandler::CLIHandler() {
	// TODO Auto-generated constructor stub

}
void CLIHandler::onMessageRecieved(char* message){
	lastRcvdMsg = message;
	cout<<"message: "<<message<<endl;
}
void CLIHandler::onOpenSession(string ip, int port){
	lastRcvdMsg = "onOpenSession";
	cout<<"onOpenedSession"<<endl;
}
void CLIHandler::onClosedSession(){
	lastRcvdMsg = "onClosedSession";
	cout<<"onClosedSession"<<endl;
}

CLIHandler::~CLIHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace networking */
