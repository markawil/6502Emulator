//
// Created by Mark Wilkinson on 8/22/26.
//

#ifndef INC_6502EMULATOR_EMULATOR_HPP
#define INC_6502EMULATOR_EMULATOR_HPP

#pragma once

#include <array>

// Based off of:
// https://6502.org/users/obelisk/6502/

using BYTE = std::uint8_t;
using WORD = std::uint16_t;

constexpr std::size_t MAX_DATA = 1024 * 64;

struct CPU {

    /* Program Counter
     * The program counter is a 16 bit register which points to the next instruction to be executed.
     * The value of program counter is modified automatically as instructions are executed.
     */
    WORD PC{};
    /* Stack Pointer
    * The processor supports a 256 byte stack located between $0100 and $01FF.
    * The stack pointer is an 8 bit register and holds the low 8 bits of the next free location on the stack.
    * The location of the stack is fixed and cannot be moved.
    * Pushing bytes to the stack causes the stack pointer to be decremented.
    * Conversely pulling bytes causes it to be incremented.
     */
    BYTE SP{};

    // Registers
    /* Accumulator Register
     * The 8 bit accumulator is used all arithmetic and logical operations (with the exception of increments and decrements).
     * The contents of the accumulator can be stored and retrieved either from memory or the stack.
     */
    BYTE AReg{};
    /* Index Register X
    The 8 bit index register is most commonly used to hold counters or offsets for accessing memory.
    The value of the X register can be loaded and saved in memory, compared with values held in memory
    or incremented and decremented. The X register has one special function. It can be used to get a copy of the stack pointer or change its value.
    */
    BYTE XReg{};
    /* Index Register Y
     * The Y register is similar to the X register in that it is available for holding counter or offsets memory access and supports
     * the same set of memory load, save and compare operations as wells as increments and decrements. It has no special functions.
     */
    BYTE YReg{};

    // Flags
    BYTE CFlag{}; // Carry
    BYTE ZFlag{}; // Zero
    BYTE IFlag{}; // Interrupt Disable
    BYTE DFlag{}; // Decimal Mode
    BYTE BFlag{}; // Break Command
    BYTE OFlag{}; // Overflow
    BYTE NFlag{}; // Negative
};

struct MEMORY {
    std::array<BYTE, MAX_DATA> Data{};
};

// Emulates rebooting the CPU and the Memory
void reboot(CPU& cpu, MEMORY& memory);

// Initializes the memory to its default state
void initialize(MEMORY& memory);

// Executes the next instruction in the PC
void execute(CPU& cpu, MEMORY& memory, uint32_t cycles);

// Fetches the next instruction in the PC
BYTE fetch(CPU& cpu, MEMORY& memory);

#endif //INC_6502EMULATOR_EMULATOR_HPP
