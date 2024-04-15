#include <iostream>
#include "Networking.h"
#include "Icmp.h"
#include "Telnet.h"


int main() {
    std::cout << "Enter an IP:" ;
    std::string userInput;
    std::cin >> userInput;
    std::cout << std::endl <<"Enter a Port number:";

    int userInput2;
    std::cin >> userInput2;
    //std::cout << userInput << std::endl;

    Icmp i(userInput);
    Telnet t(userInput, userInput2);

    if (i.ping()) {
        if (t.portCheck()) {

        }
    }

    return 0;
}