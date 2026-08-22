#include <iostream>
#include <cstdint>

using BYTE = std::uint8_t;   // 8 bit
using WORD = std::uint16_t;  // 16 bit
using DWORD = std::uint32_t; // 32 bit

#define MAX_DATA (1024 * 64) // 64 Kilobytes

struct CPU {
    WORD PC; // Program counter
    BYTE SP; // Stack pointer

    // Registers
    BYTE XReg, YReg, ZReg;

    // Flags (Carry, Zero, Interrupt Disable, Decimal Mode, Break Command, Overflow, Negative)
    BYTE CFlag, ZFlag, IFlag, DFlag, BFlag, OFlag, NFlag;
};

struct MEMORY {
    BYTE Data[MAX_DATA];
};

void reboot(CPU *cpu, MEMORY *memory);

int main() {

    CPU cpu;
    MEMORY memory;

    std::cout << "Initialized CPU!" << std::endl;

    reboot(&cpu, &memory);

    return 0;
}

void reboot(CPU *cpu, MEMORY *memory) {
    std::cout << "Rebooting CPU!" << std::endl;
}
