#include "Networking.h"

Networking::Networking(std::string a, int b) : adress_(a), port_(b) { }

Networking::Networking(std::string a) : adress_(a), port_(0) {}

Networking::Networking(int b) : port_(b), adress_("0.0.0.0") { }

