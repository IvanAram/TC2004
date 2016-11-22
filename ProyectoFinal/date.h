#pragma once
#include <iostream>

class date{
public:
	int day;
	int month;
	int year;
	date() {}
	date(int d, int m, int y) : day(d), month(m), year(y) {}
	void set(int d, int m, int y){ day=d;month=m;year=y;}

	friend std::ostream& operator<< (std::ostream& stream, const date& other);
};

std::ostream& operator<< (std::ostream& stream, const date& other){
	stream << other.day << "/" << other.month << "/" << other.year;
	return stream;
}