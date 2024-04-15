#include "Telnet.h"

#include <string>
#include <iostream>

Telnet::Telnet(std::string a, int p) : Networking(a,p) {
}

bool Telnet::portCheck() {
    // Input
    std::string addr = "ping -n 1 > NUL " + adress_;

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
