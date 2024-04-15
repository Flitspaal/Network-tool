#pragma once
#include <string>
#include "Networking.h"


class Icmp : public Networking {
public:
	Icmp(std::string);
	virtual bool ping() override;


private:
	//std::string adress_;
};

