//
// Created by Mark Wilkinson on 8/22/26.
//

#include "emulator.hpp"

void reboot(CPU& cpu, MEMORY& memory) {
    cpu = {};
    memory.Data.fill(0);

    // Substitute the correct 6502 reset values as implementation progresses.
    cpu.SP = 0xFD;
}