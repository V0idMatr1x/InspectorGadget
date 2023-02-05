#include <iostream>
#include "core.h"

int main() {
    std::cout << "Installed Memory: " << Memory::GetAllRAM() << "GB" << std::endl;
    std::cout << "Used Memory: " << Memory::GetUsedRAM() << "GB" << std::endl;
    std::cout << "Free Memory: " << Memory::GetFreeRAM() << "GB" << std::endl;
    std::cout << "Disk Capacity: " << Storage::GetDiskCapacity() << "GB" <<std::endl;
    std::cout << "Free Disk Space: " << Storage::GetFreeDiskSpace() << "GB" << std::endl;
    std::cout << "Used Disk Space: " << Storage::GetUsedDiskSpace() << "GB" << std::endl;
    std::cout << "CPU: " << CPU::GetCPUName() << "%" << std::endl;
    std::cout << "CPU Cores: " << CPU::GetCPUCoreCount() << std::endl;
}
