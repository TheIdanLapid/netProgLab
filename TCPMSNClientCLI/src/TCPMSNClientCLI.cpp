/*
 * TCPMSNClientCLI.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: user
 */




/*
 * main.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: user
 */


#include <iostream>
#include "TCPMSNClient.h"
#include "CLIHandler.h"
using namespace std;
using namespace networking;

int main() {
	CLIHandler* handler = new CLIHandler();
	cout << "Welcome to Messenger!" << endl;
	TCPMSNClient* client = new TCPMSNClient(handler);
	string command;
	while (true) {
		cout << "Please enter a command:" << endl;
		cin >> command;
		if (command == "c") {
			string ip;
			cout << "Enter the server's ip:" << endl;
			cin >> ip;
			client->connect(ip);

		} else if (command == "o") {
			cout << "Please enter the peer's ip:" << endl;
			string ip;
			cin >> ip;
			cout << "Please enter the peer's port:" << endl;
			int port;
			cin >> port;
			client->openSession(ip,port);

		} else if (command == "s") {
			cout << "Please enter a message:" << endl;
			string msg;
			getline(std::cin, msg);
			client->sendMessage(msg);
		}

		else if (command == "cs") {
			client->closeSession();
		}

		else if (command == "d") {
			client->disconnect();
		}

		else if (command == "x") {
			cout<<"Bye!"<<endl;
			break;
		}
	}
	return 0;

}


