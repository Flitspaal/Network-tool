#pragma once
#include <string>
#include <vector>
#include <mutex>
#include <unordered_set>
#include "Networking.h"


class Icmp : public Networking {
public:
	Icmp(std::string);
	virtual bool ping() override;
	virtual bool scan(int,int) override;
	virtual void printResults() override;

private:
	std::unordered_set<std::string> results_;
	std::mutex mtx_;
	//std::string adress_;
};

