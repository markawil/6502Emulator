//
// Created by Mark Wilkinson on 8/22/26.
//

#ifndef INC_6502EMULATOR_EMULATOR_HPP
#define INC_6502EMULATOR_EMULATOR_HPP

#pragma once

#include <array>
#include <cstdint>

using BYTE = std::uint8_t;
using WORD = std::uint16_t;

constexpr std::size_t MAX_DATA = 1024 * 64;

struct CPU {

    WORD PC{}; // Program Counter
    BYTE SP{}; // Stack Pointer

    // Registers
    BYTE XReg{};
    BYTE YReg{};
    BYTE ZReg{};

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

void reboot(CPU& cpu, MEMORY& memory);

#endif //INC_6502EMULATOR_EMULATOR_HPP
