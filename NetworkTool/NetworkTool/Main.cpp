#include <iostream>
#include "Networking.h"
#include "Icmp.h"
#include "Telnet.h"


int main() {
    std::cout << "Enter an IP:" << std::endl;
    std::string userInput;
    std::cin >> userInput;
    std::cout << userInput << std::endl;
    Icmp i(userInput);
    Telnet t(userInput);
    if (i.ping()) {

    }

    return 0;
}