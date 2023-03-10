//
// Created by chris on 2/5/2023.
//

#pragma once


class Computer
{

    private:

        // Returns raw cpu id
        static auto _cpuid(int *pInt, unsigned int i) -> void {
            __asm__ __volatile__ (
                    "cpuid":
                    "=a" (pInt[0]),
                    "=b" (pInt[1]),
                    "=c" (pInt[2]),
                    "=d" (pInt[3]) :
                    "a" (i), "c" (0));
        }

    public:

        // Returns the Motherboard name
        static auto FindMotherboardName() -> std::string {
            HKEY hKey;
            LONG result { RegOpenKeyEx(HKEY_LOCAL_MACHINE, R"(HARDWARE\DESCRIPTION\System\BIOS)", 0, KEY_READ, &hKey) };

            char  board[80];
            DWORD dwBufLen { sizeof(board) };
            result = RegQueryValueEx(hKey, "BaseBoardProduct", nullptr, nullptr, (LPBYTE) board, &dwBufLen);

            if (result != ERROR_SUCCESS) {
                return "Unknown";
            }
            RegCloseKey(hKey);
            return board;
        }

        // Returns the CPU name
        static auto FindCPUName() -> std::string {
            int cpuInfo[4] {-1};
            char cpuName[0x40];
            _cpuid(cpuInfo, 0x80000000);
            unsigned int x { static_cast<unsigned int>(cpuInfo[0]) };

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
        static auto FindCPUCoreCount() -> DWORD {
            SYSTEM_INFO cpu;
            GetSystemInfo(&cpu);

            return cpu.dwNumberOfProcessors;
        }

        // Returns the GPU name from the bus id
        static auto FindGPUName() -> std::string {
            DISPLAY_DEVICE gpu;
            gpu.cb = sizeof(DISPLAY_DEVICE);

            EnumDisplayDevices(nullptr, 0, &gpu, 0);

            return gpu.DeviceString;
        }
};
