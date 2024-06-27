#include <iostream>
//#include <stdio.h>
#include <windows.h>
#include <thread>
#include <sstream>
#include <unordered_set>
#include <chrono>
#include <algorithm> // Include for std::sort
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
    
    for (int i = b; i <= e ; i++){
        std::ostringstream oss;
        std::string str = adress_ + std::to_string(i);
        std::string addr = "ping -n 1 > NUL " + str;
        int result = system(addr.data());
        oss << std::to_string(i) << "  " << str << "  " << result << std::endl;

        std::lock_guard<std::mutex> lock(mtx_); //anti racing conditions
        results_.insert(oss.str());                
    }
    return true;
}

void Icmp::printResults() {
    std::cout << std::endl << "RESULTS:" << std::endl;
    std::cout << "scan:" << "  " << "IP: " << "  " << "Result:" << std::endl;

    std::lock_guard<std::mutex> lock(mtx_);

    // Copy set to vector
    std::vector<std::string> resultsVec(results_.begin(), results_.end());

    // Custom comparator to sort based on the first number in the string
    std::sort(resultsVec.begin(), resultsVec.end(), [](const std::string& a, const std::string& b) {
        int numA = std::stoi(a.substr(0, a.find(' ')));
        int numB = std::stoi(b.substr(0, b.find(' ')));
        return numA < numB;
        });

    // Print sorted results
    for (const auto& result : resultsVec) {
        std::cout << result;
    }
}

