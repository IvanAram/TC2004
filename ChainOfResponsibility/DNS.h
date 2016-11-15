#pragma once
#include <iostream>
#include <map>
#include <string>

class DNS{
private:
	DNS* next;
protected:
	DNS(std::string _server) : server(_server), next(nullptr) {}
	std::string server;
	std::map<std::string, std::string> IPtable;
public:
	virtual std::string searchName(std::string name) = 0;
	void setNextDNS(DNS* _next){ next = _next; }
	std::string getIP(std::string domainName);
};

std::string DNS::getIP(std::string domainName){
	std::string domain;
	for(int i = domainName.length()-1; i >= 0; i--){
		if(domainName[i] == '.'){
			domain = domainName.substr(i,domainName.length()-i);
			break;
		}
	}
	if(domain == server) return searchName(domainName);
	else{
		if(next != nullptr) return next->getIP(domainName);
		else{
			std::cout << "Couldn't find the server you're looking for" << std::endl;
			return "";
		}
	}
}