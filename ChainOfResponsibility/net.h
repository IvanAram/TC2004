#pragma once
#include "DNS.h"
#include <iostream>

class net : public DNS{
public:
	net(std::string _server = ".net") : DNS(_server){ fillTable(); }
	std::string searchName(std::string name);
	void fillTable();
};

std::string net::searchName(std::string name){
	if(IPtable.count(name) > 0) return IPtable[name];
	else{
		std::cout << name << " was not found in \".net\" server." << std::endl;
		return "";
	}
}

void net::fillTable(){
	IPtable["www.a.net"] = "130.2.0.1";
	IPtable["www.b.net"] = "56.88.7.89";
	IPtable["www.c.net"] = "19.100.5.9";
	IPtable["www.d.net"] = "200.5.50.33";
	IPtable["www.e.net"] = "15.1.1.0";
}