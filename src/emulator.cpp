//
// Created by Mark Wilkinson on 8/22/26.
//

#include "emulator.hpp"
#include "instructions.hpp"
#include <cstdint>

void reboot(CPU& cpu, MEMORY& memory) {

    // Init the Program Counter and Stack Pointer based on the docs
    cpu.PC = 0xFFFC;
    // Substitute the correct 6502 reset values as implementation progresses.
    cpu.SP = 0xFD;

    // Set the registers to 0
    cpu.AReg = 0x00;
    cpu.XReg = 0x00;
    cpu.YReg = 0x00;

    // Set the flags back to 0
    cpu.BFlag = 0;
    cpu.CFlag = 0;
    cpu.DFlag = 0;
    cpu.IFlag = 0;
    cpu.NFlag = 0;
    cpu.ZFlag = 0;
    cpu.OFlag = 0;

    initialize(memory);
}

void initialize(MEMORY& memory) {

    // clear all the memory
    for (uint32_t i = 0; i < MAX_DATA; ++i) {
        memory.Data[i] = 0x00;
    }
}

BYTE fetch(CPU& cpu, MEMORY& memory) {
    // fetch the data where the PC is currently pointing to
    BYTE data = memory.Data[cpu.PC];
    // increment the PC
    cpu.PC++;
    return data;
}

void execute(CPU& cpu, MEMORY& memory, uint32_t cycles) {
    // iterate the cycles to execute the next instruction
    while (cycles > 0) {
        cycles--;
        switch (BYTE opcode = fetch(cpu, memory)) {
            case LDA_IMMEDIATE.opcode: {
                const BYTE value = fetch(cpu, memory);
                cpu.AReg = value;
                cpu.ZFlag = cpu.AReg == 0;
                cpu.NFlag = (cpu.AReg & 0b10000000) > 0; // if bit 7 set of A
                cycles--;
                break;
            }
            default:
                break;
        }
    }
}