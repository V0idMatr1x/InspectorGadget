//
// Created by chris on 2/5/2023.
//

#pragma once


namespace Storage
{

    // Returns the total storage in Gigabytes
    static auto FindDiskCapacity() -> DWORDLONG {
        ULARGE_INTEGER totalBytes;
        GetDiskFreeSpaceEx("C:\\", nullptr, &totalBytes, nullptr);

        return totalBytes.QuadPart / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the free storage in Gigabytes
    static auto FindFreeDiskSpace() -> DWORDLONG {
        ULARGE_INTEGER freeBytes;
        GetDiskFreeSpaceEx("C:\\", &freeBytes, nullptr, nullptr);

        return freeBytes.QuadPart / 1024.0 / 1024.0 / 1024.0;
    }

    // Returns the used storage in Gigabytes
    static auto FindUsedDiskSpace() -> DWORDLONG {
        ULARGE_INTEGER freeBytes;
        ULARGE_INTEGER totalBytes;
        GetDiskFreeSpaceEx("C:\\", &freeBytes, &totalBytes, nullptr);

        return (totalBytes.QuadPart - freeBytes.QuadPart) / 1024.0 / 1024.0 / 1024.0;
    }
};