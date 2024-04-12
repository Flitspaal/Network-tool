#pragma once
#include "Networking.h"
#include <string>

class Telnet : public Networking {
public:
	Telnet(int);
	Telnet(std::string);
	~Telnet() {};
	virtual void portCheck() override;
private:
	int port_;
	std::string adress_;
};

