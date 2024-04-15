#pragma once
#include <string>

class Networking
{
public:
	Networking(std::string a, int b);
	Networking(std::string a);
	Networking(int b);
	
	virtual bool ping() { return true; };
	virtual bool portCheck() { return false; };

protected:
	std::string adress_;
	int port_;
};

