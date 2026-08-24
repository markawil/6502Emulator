//
// Created by Mark Wilkinson on 8/22/26.
//

#include "emulator.hpp"
#include <gtest/gtest.h>

#include <algorithm>

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
    cpu.AReg = 10;

    reboot(cpu, memory);

    EXPECT_EQ(cpu.XReg, 0);
    EXPECT_EQ(cpu.YReg, 0);
    EXPECT_EQ(cpu.AReg, 0);
}

TEST(RebootTest, ClearsFlags) {
    CPU cpu{};
    MEMORY memory{};

    cpu.CFlag = 1;
    cpu.ZFlag = 1;
    cpu.IFlag = 1;
    cpu.DFlag = 1;
    cpu.BFlag = 1;
    cpu.OFlag = 1;
    cpu.NFlag = 1;

    reboot(cpu, memory);

    EXPECT_EQ(cpu.CFlag, 0);
    EXPECT_EQ(cpu.ZFlag, 0);
    EXPECT_EQ(cpu.IFlag, 0);
    EXPECT_EQ(cpu.DFlag, 0);
    EXPECT_EQ(cpu.BFlag, 0);
    EXPECT_EQ(cpu.OFlag, 0);
    EXPECT_EQ(cpu.NFlag, 0);
}

TEST(MemoryTest, InitializeClearsAllMemory) {
    MEMORY memory{};
    memory.Data.fill(0xFF);

    initialize(memory);

    EXPECT_TRUE(std::all_of(
        memory.Data.begin(),
        memory.Data.end(),
        [](BYTE value) { return value == 0x00; }
    ));
}
