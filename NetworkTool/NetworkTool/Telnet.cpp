#include "Telnet.h"

#include <string>

Telnet::Telnet(int p) : port_(p) {
}

Telnet::Telnet(std::string a) : adress_(a) {
}

void Telnet::portCheck() {
}
