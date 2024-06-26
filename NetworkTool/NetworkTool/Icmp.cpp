#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <thread>
#include <sstream>
#include <chrono>
#include "Icmp.h"


Icmp::Icmp(std::string a) : Networking(a) {}

bool Icmp::ping() {
    // Input
    std::string addr = "ping -n 1 > NUL " + adress_;
    std::cout << adress_ << std::endl;
    
    // Execute ping:
    int result = system(addr.data());

    // Result
    if (result == 0) {
        std::cout << "Ping successful." << std::endl;
        return true;
    }
    else {
        std::cout << "Ping failed." << std::endl;
        return false;
    }
}

bool Icmp::scan(int b, int e)
{ 
    std::ostringstream oss;
    for (int i = b; i <= e ; i++)
    {
        std::string str = adress_ + std::to_string(i);
        std::string addr = "ping -n 1 > NUL " + str;
        int result = system(addr.data());
        std::cout << std::to_string(i)<<"  " << str << "  " << result << std::endl;
        oss << std::to_string(i) << "  " << str << "  " << result << std::endl;
       
        std::lock_guard<std::mutex> lock(mtx_); //anti racing conditions
        results_.push_back(oss.str());
    }
    return true;
}

void Icmp::printResults() {
    std::cout << std::endl << "RESULTS:" << std::endl;

    std::lock_guard<std::mutex> lock(mtx_);
    for (const auto& result : results_) {
        std::cout << result;
    }
    return;
}

