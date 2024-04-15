#pragma once
#include "Networking.h"
#include <string>

class Telnet : public Networking {
public:
	Telnet(std::string, int);
	~Telnet() {};
	virtual bool portCheck() override;
};