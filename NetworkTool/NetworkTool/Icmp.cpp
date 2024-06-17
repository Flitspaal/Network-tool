#include <iostream>
#include <stdio.h>
#include <windows.h>

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

bool Icmp::scan()
{ 
    for (int i = 0; i <= 255 ; i++)
    {
        std::string str = adress_ + std::to_string(i);
        std::string addr = "ping -n 1 > NUL " + str;
        int result = system(addr.data());
        std::cout << std::to_string(i)<<"  " << str << "  " << result << std::endl;
        if (i == 255) return true;
    }
    return true;
}

