#include <iostream>
#include "core.h"

// Returns the host OS as a static value
static auto host() -> std::string {
    return "Windows";
}

// Returns the native resolution of the screen and converts it to a string
static auto GetNativeResolution() -> std::string {
    DEVMODE devMode;
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode);
    return std::to_string(devMode.dmPelsWidth) + "x" + std::to_string(devMode.dmPelsHeight);
}

int main() {
    std::cout << "OS: " << host() << std::endl;
    std::cout << "Installed Memory: " << Memory::GetAllRAM() << "GB" << std::endl;
    std::cout << "Used Memory: " << Memory::GetUsedRAM() << "GB" << std::endl;
    std::cout << "Free Memory: " << Memory::GetFreeRAM() << "GB" << std::endl;
    std::cout << "Disk Capacity: " << Storage::GetDiskCapacity() << "GB" <<std::endl;
    std::cout << "Free Disk Space: " << Storage::GetFreeDiskSpace() << "GB" << std::endl;
    std::cout << "Used Disk Space: " << Storage::GetUsedDiskSpace() << "GB" << std::endl;
    std::cout << "CPU: " << Computer::GetCPUName() << std::endl;
    std::cout << "CPU Cores: " << Computer::GetCPUCoreCount() << std::endl;
    std::cout << "GPU: " << Computer::GetGPUName() << std::endl;
    std::cout << "Native Resolution: " << GetNativeResolution() << std::endl;

}
