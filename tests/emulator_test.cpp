//
// Created by Mark Wilkinson on 8/22/26.
//

#include "emulator.hpp"
#include <gtest/gtest.h>

TEST(RebootTest, InitializesStackPointer) {
    CPU cpu{};
    MEMORY memory{};

    reboot(cpu, memory);

    EXPECT_EQ(cpu.SP, 0xFD);
}

TEST(RebootTest, ClearsRegisters) {
    CPU cpu{};
    MEMORY memory{};

    cpu.XReg = 42;
    cpu.YReg = 17;

    reboot(cpu, memory);

    EXPECT_EQ(cpu.XReg, 0);
    EXPECT_EQ(cpu.YReg, 0);
}
