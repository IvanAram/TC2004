#pragma once
#include "DNS.h"
#include <iostream>

class org : public DNS{
public:
	org(std::string _server = ".org") : DNS(_server){ fillTable(); }
	std::string searchName(std::string name);
	void fillTable();
};

std::string org::searchName(std::string name){
	if(IPtable.count(name) > 0) return IPtable[name];
	else{
		std::cout << name << " was not found in \".org\" server." << std::endl;
		return "";
	}
}

void org::fillTable(){
	IPtable["www.a.org"] = "119.30.0.4";
	IPtable["www.b.org"] = "210.8.29.70";
	IPtable["www.c.org"] = "8.16.0.111";
	IPtable["www.d.org"] = "221.28.12.134";
	IPtable["www.e.org"] = "51.150.99.13";
}