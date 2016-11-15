#pragma once
#include "DNS.h"
#include <iostream>

class com : public DNS{
public:
	com(std::string _server = ".com") : DNS(_server) { fillTable(); }
	std::string searchName(std::string name);
	void fillTable();
};

std::string com::searchName(std::string name){
	if(IPtable.count(name) > 0) return IPtable[name];
	else{
		std::cout << name << " was not found in \".com\" server." << std::endl;
		return "";
	}
}

void com::fillTable(){
	IPtable["www.a.com"] = "10.20.30.40";
	IPtable["www.b.com"] = "54.38.21.7";
	IPtable["www.c.com"] = "109.1.50.31";
	IPtable["www.d.com"] = "12.50.34.74";
	IPtable["www.e.com"] = "15.2.39.89";
}