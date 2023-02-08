//
// Created by chris on 2/5/2023.
//

#pragma INSPECTORGADGET_MEM_H


namespace Memory
{

    // Returns the total RAM in Gigabytes
    static auto FindAllRAM() -> DWORDLONG {
        MEMORYSTATUSEX ram;
        ram.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&ram);

        return ram.ullTotalPhys / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the free RAM in Gigabytes
    static auto FindFreeRAM() -> DWORDLONG {
        MEMORYSTATUSEX ram;
        ram.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&ram);

        return ram.ullAvailPhys / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the used RAM in Gigabytes
    static auto FindUsedRAM() -> DWORDLONG {
        MEMORYSTATUSEX ram;
        ram.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&ram);

        return (ram.ullTotalPhys - ram.ullAvailPhys) / 1024.0 / 1024.0 / 1024.0;
    }
};