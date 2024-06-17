#include <iostream>
#include "Networking.h"
#include "Icmp.h"
#include "Telnet.h"


int main() {
    std::cout << "what do you want to do" << std::endl;
    std::cout << "1) Ip/Domain Check" << std::endl;
    std::cout << "2) Ip scan" << std::endl;
    int userInput;
    std::string userInput2;
    std::cin >> userInput;
    if(userInput == 1){     
        std::cout << "Enter an IP:";
        std::cin >> userInput2;
        Icmp p(userInput2);
        p.ping();
    }
    if (userInput == 2) {
        std::cout << "Enter the first 3 octets (xxx.xxx.xxx.):";
        std::cin >> userInput2;
        Icmp pp(userInput2);

        pp.scan();
    }
   
    //std::cout << userInput << std::endl;


//    if (i.ping()) {
 //       if (t.portCheck()) {

//        }
//    }

    return 0;
}