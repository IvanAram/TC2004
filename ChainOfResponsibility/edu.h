#pragma once
#include "DNS.h"
#include <iostream>

class edu : public DNS{
public:
	edu(std::string _server = ".edu") : DNS(_server){ fillTable(); }
	std::string searchName(std::string name);
	void fillTable();
};

std::string edu::searchName(std::string name){
	if(IPtable.count(name) > 0) return IPtable[name];
	else{
		std::cout << name << " was not found in \".edu\" server." << std::endl;
		return "";
	}
}

void edu::fillTable(){
	IPtable["www.a.edu"] = "190.11.22.45";
	IPtable["www.b.edu"] = "21.53.12.79";
	IPtable["www.c.edu"] = "2.6.8.11";
	IPtable["www.d.edu"] = "112.218.102.14";
	IPtable["www.e.edu"] = "67.210.109.16";
}