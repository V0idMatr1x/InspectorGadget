//
// Created by chris on 2/5/2023.
//

#pragma INSPECTORGADGET_COMPUTER_H

namespace Computer {

    // Returns the raw cpuid
    static auto _cpuid(int pInt[4], unsigned int i) -> void {
        __asm__ __volatile__ (
                "cpuid":
                "=a" (pInt[0]),
                "=b" (pInt[1]),
                "=c" (pInt[2]),
                "=d" (pInt[3]) :
                "a" (i), "c" (0));
    }

    // Returns the CPU name
    static auto GetCPUName() -> std::string {
        int cpuInfo[4] = {-1};
        char cpuName[0x40];
        _cpuid(cpuInfo, 0x80000000);
        unsigned int x = cpuInfo[0];

        memset(cpuName, 0, sizeof(cpuName));

        for (unsigned int i = 0x80000000; i <= x; ++i) {
            _cpuid(cpuInfo, i);

            if (i == 0x80000002)
                memcpy(cpuName, cpuInfo, sizeof(cpuInfo));
            else if (i == 0x80000003)
                memcpy(cpuName + 16, cpuInfo, sizeof(cpuInfo));
            else if (i == 0x80000004)
                memcpy(cpuName + 32, cpuInfo, sizeof(cpuInfo));
        }

        return cpuName;
    }

    // Returns the CPU core count
    static auto GetCPUCoreCount() -> int {
        SYSTEM_INFO cpu;
        GetSystemInfo(&cpu);

        return cpu.dwNumberOfProcessors;
    }

    // Returns the GPU name from the bus id
    static auto GetGPUName() -> std::string {
        DISPLAY_DEVICE displayDevice;
        displayDevice.cb = sizeof(DISPLAY_DEVICE);

        EnumDisplayDevices(nullptr, 0, &displayDevice, 0);

        return displayDevice.DeviceString;
    }
};