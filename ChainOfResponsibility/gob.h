#pragma once
#include "DNS.h"
#include <iostream>

class gob : public DNS{
public:
	gob(std::string _server = ".gob") : DNS(_server){ fillTable(); }
	std::string searchName(std::string name);
	void fillTable();
};

std::string gob::searchName(std::string name){
	if(IPtable.count(name) > 0) return IPtable[name];
	else{
		std::cout << name << " was not found in \".gob\" server." << std::endl;
		return "";
	}
}

void gob::fillTable(){
	IPtable["www.a.gob"] = "47.45.10.9";
	IPtable["www.b.gob"] = "100.12.211.199";
	IPtable["www.c.gob"] = "186.177.198.1";
	IPtable["www.d.gob"] = "8.8.0.1";
	IPtable["www.e.gob"] = "12.50.13.193";
}