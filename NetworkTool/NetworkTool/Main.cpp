#include <iostream>
#include <thread>
#include <vector>
#include <set>
#include "Networking.h"
#include "Icmp.h"
#include "Telnet.h"



int main() {

    std::cout << "what do you want to do" << std::endl;
    std::cout << "1) Ip/Domain Check" << std::endl;
    std::cout << "2) Ip scan" << std::endl;
    int userInput;
    std::string userInput2;
    int userStart;
    int userEnd;
    std::cin >> userInput;

    if(userInput == 1){     
        std::cout << "Enter an IP:";
        std::cin >> userInput2;
        Icmp p(userInput2);
        p.ping();
    }

    if (userInput == 2) {
        std::vector<std::thread> ScanT;
        std::cout << "Enter the first 3 octets (xxx.xxx.xxx.): ";
        std::cin >> userInput2;
        std::cout << "Enter the starting octet: ";
        std::cin >> userStart;
        std::cout << "Enter the end octet: ";
        std::cin >> userEnd;
        Icmp pp(userInput2);

        // Create threads for scanning
        int range = userEnd - userStart + 1;
        int step = range / 3;
        int mid1 = userStart + step;
        int mid2 = userStart + 2 * step;

        ScanT.push_back(std::thread(&Icmp::scan, &pp, userStart, mid1 - 1));
        ScanT.push_back(std::thread(&Icmp::scan, &pp, mid1, mid2 - 1));
        ScanT.push_back(std::thread(&Icmp::scan, &pp, mid2, userEnd));
       
        for (auto& th : ScanT) {
            th.join();
        }

        pp.printResults();
    } 

    return 0;
}

