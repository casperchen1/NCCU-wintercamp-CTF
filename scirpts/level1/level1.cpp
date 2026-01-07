#include <iostream>
#include <csignal>
#include <string>
#include <unistd.h>

using namespace std;

const string CODE = "{PROCESS_CAN_HIDE}";

void handle_signal(int signal) {
    std::cout << "Thank you for killing the virus for me!" << std::endl;
    std::cout << CODE << std::endl;
    _exit(0);
}

int main() {
    // Register signal handlers
    signal(SIGTERM, handle_signal); // kill PID
    signal(SIGINT, handle_signal);  // Ctrl+C

    while (true) {
        
    }

    return 0;
}