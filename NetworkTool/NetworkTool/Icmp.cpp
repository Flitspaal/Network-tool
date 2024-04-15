#include <iostream>

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
