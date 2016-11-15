#pragma once
#include "DNS.h"
#include <iostream>

class mx : public DNS{
public:
	mx(std::string _server = ".mx") : DNS(_server){ fillTable(); }
	std::string searchName(std::string name);
	void fillTable();
};

std::string mx::searchName(std::string name){
	if(IPtable.count(name) > 0) return IPtable[name];
	else{
		std::cout << name << " was not found in \".mx\" server." << std::endl;
		return "";
	}
}

void mx::fillTable(){
	IPtable["www.a.mx"] = "18.53.31.193";
	IPtable["www.b.mx"] = "180.132.0.1";
	IPtable["www.c.mx"] = "10.0.0.31";
	IPtable["www.d.mx"] = "102.220.19.35";
	IPtable["www.e.mx"] = "59.22.149.19";
}