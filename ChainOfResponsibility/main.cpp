#include <iostream>
#include "com.h"
#include "org.h"
#include "net.h"
#include "mx.h"
#include "edu.h"
#include "gob.h"

DNS* chainOfResponsibility(){
	DNS* serverCom = new com();
	DNS* serverMx = new mx();
	DNS* serverOrg = new org();
	DNS* serverNet = new net();
	DNS* serverEdu = new edu();
	DNS* serverGob = new gob();

	serverCom->setNextDNS(serverMx);
	serverMx->setNextDNS(serverOrg);
	serverOrg->setNextDNS(serverNet);
	serverNet->setNextDNS(serverEdu);
	serverEdu->setNextDNS(serverGob);

	return serverCom;
}

int main(){
	DNS* chainOfDNS = chainOfResponsibility();
	std::string domainName, ip;
	char op = 'y';
	while(op == 'y'){
		std::cout << "\nEnter address: ";
		std::cin >> domainName;
		ip = chainOfDNS->getIP(domainName);
		if(ip != "") std::cout << "\nDOMAIN NAME: " << domainName << "\nIP ADDRESS: " << ip << "\n" << std::endl;
		std::cout << "Search another IP? [y/n]: ";
		std::cin >> op;
	}
}