//
// Created by chris on 2/5/2023.
//

#include <windows.h>

#pragma INSPECTORGADGET_MEM_H

namespace Memory {

    // Returns the total RAM in Gigabytes
    static auto GetAllRAM() -> DWORDLONG {
        MEMORYSTATUSEX ram;
        ram.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&ram);

        return ram.ullTotalPhys / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the free RAM in Gigabytes
    static auto GetFreeRAM() -> DWORDLONG {
        MEMORYSTATUSEX ram;
        ram.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&ram);

        return ram.ullAvailPhys / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the used RAM in Gigabytes
    static auto GetUsedRAM() -> DWORDLONG {
        MEMORYSTATUSEX ram;
        ram.dwLength = sizeof(MEMORYSTATUSEX);
        GlobalMemoryStatusEx(&ram);

        return (ram.ullTotalPhys - ram.ullAvailPhys) / 1024.0 / 1024.0 / 1024.0;
    }
};
