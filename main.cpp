#include <iostream>
#include "emulator.hpp"

int main() {

    CPU cpu = CPU();
    MEMORY memory = MEMORY();

    std::cout << "Rebooting CPU!" << std::endl;

    reboot(cpu, memory);

    return 0;
}
