#pragma once
#include <string>
#include <stdio.h>

class Networking
{
public:
	Networking(std::string a, int b);
	Networking(std::string a);
	Networking(int b);
	//Networking(char s[]);
	
	virtual bool ping() { return true; };
	virtual bool scan(int s,int e) { return true; };
	virtual bool portCheck() { return false; };
	virtual void printResults() { };

protected:
	std::string adress_;
	int port_;

};

