#include <iostream>
#include <csignal>
#include <string>
#include <unistd.h>

using namespace std;

const string CODE = "{PROCESS_CAN_HIDE}";

void handle_signal(int signal) {
    std::cout << "感謝你幫我除掉病毒!" << std::endl;
    std::cout << CODE << std::endl;
    _exit(0);
}

int main() {
    // Register signal handlers
    signal(SIGTERM, handle_signal); // kill PID
    signal(SIGINT, handle_signal);  // Ctrl+C

    while (true) {
        // Empty loop
    }

    return 0;
}