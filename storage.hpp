//
// Created by chris on 2/5/2023.
//

#include <windows.h>

#pragma INSPECTORGADGET_STORAGE_H

namespace Storage {

    // Returns the total storage in Gigabytes
    static auto GetDiskCapacity() -> DWORDLONG {
        ULARGE_INTEGER totalBytes;
        GetDiskFreeSpaceEx("C:\\", NULL, &totalBytes, NULL);

        return totalBytes.QuadPart / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the free storage in Gigabytes
    static auto GetFreeDiskSpace() -> DWORDLONG {
        ULARGE_INTEGER freeBytes;
        GetDiskFreeSpaceEx("C:\\", &freeBytes, NULL, NULL);

        return freeBytes.QuadPart / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the used storage in Gigabytes
    static auto GetUsedDiskSpace() -> DWORDLONG {
        ULARGE_INTEGER freeBytes;
        ULARGE_INTEGER totalBytes;
        GetDiskFreeSpaceEx("C:\\", &freeBytes, &totalBytes, NULL);

        return (totalBytes.QuadPart - freeBytes.QuadPart) / 1024.0 / 1024.0 / 1024.0;
    }
};