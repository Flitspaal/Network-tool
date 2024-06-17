#pragma once
#include <string>
#include "Networking.h"


class Icmp : public Networking {
public:
	Icmp(std::string);
	virtual bool ping() override;
	virtual bool scan() override;


private:
	//std::string adress_;
};

