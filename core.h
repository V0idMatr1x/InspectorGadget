//
// Created by chris on 2/5/2023.
//
#include<windows.h>

#pragma INSPECTORGADGET_CORE_H


namespace Memory {

        // A method for getting the total RAM in Gigabytes
        static auto GetAllRAM() -> DWORDLONG {
            MEMORYSTATUSEX ram;
            ram.dwLength = sizeof(MEMORYSTATUSEX);
            GlobalMemoryStatusEx(&ram);

            return ram.ullTotalPhys / 1024.0 / 1024.0 / 1024.0;
        }

        // A method for getting the free RAM in Gigabytes
        static auto GetFreeRAM() -> DWORDLONG {
            MEMORYSTATUSEX ram;
            ram.dwLength = sizeof(MEMORYSTATUSEX);
            GlobalMemoryStatusEx(&ram);

            return ram.ullAvailPhys / 1024.0 / 1024.0 / 1024.0;
        }

        // A method for getting the used RAM in Gigabytes
        static auto GetUsedRAM() -> DWORDLONG {
            MEMORYSTATUSEX ram;
            ram.dwLength = sizeof(MEMORYSTATUSEX);
            GlobalMemoryStatusEx(&ram);

            return (ram.ullTotalPhys - ram.ullAvailPhys) / 1024.0 / 1024.0 / 1024.0;
        }
};

namespace Storage {

        // A method for getting the total storage in Gigabytes
        static auto GetDiskCapacity() -> DWORDLONG {
            ULARGE_INTEGER totalBytes;
            GetDiskFreeSpaceEx("C:\\", NULL, &totalBytes, NULL);

            return totalBytes.QuadPart / 1024.0 / 1024.0 / 1024.0;
        }

        // A method for getting the free storage in Gigabytes
        static auto GetFreeDiskSpace() -> DWORDLONG {
            ULARGE_INTEGER freeBytes;
            GetDiskFreeSpaceEx("C:\\", &freeBytes, NULL, NULL);

            return freeBytes.QuadPart / 1024.0 / 1024.0 / 1024.0;
        }

        // A method for getting the used storage in Gigabytes
        static auto GetUsedDiskSpace() -> DWORDLONG {
            ULARGE_INTEGER freeBytes;
            ULARGE_INTEGER totalBytes;
            GetDiskFreeSpaceEx("C:\\", &freeBytes, &totalBytes, NULL);

            return (totalBytes.QuadPart - freeBytes.QuadPart) / 1024.0 / 1024.0 / 1024.0;
        }
};

namespace CPU {

        // A helper method for getting the raw cpuid
        static auto _cpuid(int pInt[4], unsigned int i) -> void {
            __asm__ __volatile__ (
                    "cpuid":
                    "=a" (pInt[0]),
                    "=b" (pInt[1]),
                    "=c" (pInt[2]),
                    "=d" (pInt[3]) :
                    "a" (i), "c" (0)
                    );
        }

        // A method for getting the CPU name
        static auto GetCPUName() -> std::string {
            int cpuInfo[4] = {-1};
            char cpuName[0x40];
            _cpuid(cpuInfo, 0x80000000);
            unsigned int nExIds = cpuInfo[0];

            memset(cpuName, 0, sizeof(cpuName));

            for (unsigned int i = 0x80000000; i <= nExIds; ++i) {
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

        // A method for getting the CPU core count
        static auto GetCPUCoreCount() -> int {
            SYSTEM_INFO cpu;
            GetSystemInfo(&cpu);

            return cpu.dwNumberOfProcessors;
        }
};

