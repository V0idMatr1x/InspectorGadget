// STL Dependencies
#include <iostream>
#include <windows.h>

// Statically Linked Dependencies
#include "memory.hpp"
#include "storage.hpp"
#include "computer.hpp"
#include "windows.hpp"


static auto asciiArt() -> const char* {
    return R"(


                        _.-;:q=._
                      .' j=""^k;:\.
                     ; .F       ";`Y
                    ,;.J_        ;'j
                  ,-;"^7F       : .F           _________________
                 ,-'-_<.        ;gj. _.,---""''               .'
                ;  _,._`\.     : `T"5,                       ;
                : `?8w7 `J  ,-'" -^q. `                     ;
                 \;._ _,=' ;   n58L Y.                     .'
                   F;";  .' k_ `^'  j'                     ;
                   J;:: ;     "y:-='                      ;
                    L;;==      |:;   jT\                  ;
                    L;:;J      J:L  7:;'       _         ;
                    I;|:.L     |:k J:.' ,  '       .     ;
                    |;J:.|     ;.I F.:      .           :
                   ;J;:L::     |.| |.J  , '   `    ;    ;
                 .' J:`J.`.    :.J |. L .    ;         ;
                ;    L :k:`._ ,',j J; |  ` ,        ; ;
              .'     I :`=.:."_".'  L J             `.'
            .'       |.:  `"-=-'    |.J              ;
        _.-'         `: :           ;:;           _ ;
    _.-'"             J: :         /.;'       ;    ;
  ='_                  k;.\.    _.;:Y'     ,     .'
     `"---..__          `Y;."-=';:='     ,      .'
              `""--..__   `"==="'    -        .'
                        `""--..__            .'
                                    `""--..__'
    )";
}

// Returns the host OS as a constant string value
std::string const OS { "Windows" };
static auto host() -> std::string {
    return OS;
}

// Returns the native resolution of the screen and converts it to a string
static auto resolution() -> std::string {
    DEVMODE devMode;
    EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &devMode);
    return std::to_string(devMode.dmPelsWidth) + "x" + std::to_string(devMode.dmPelsHeight);
}

int main()
{
    // Standard Output Color (Green)
    system("color 0A");

    // Output
    std::cout << asciiArt() << std::endl;
    std::cout << "OS: " << host() << std::endl;
    std::cout << "Edition: " << Windows::Edition() << std::endl;
    std::cout << "WSL: " << Windows::WSLStatus() << std::endl;
    std::cout << "Motherboard: " << Computer::FindMotherboardName() << std::endl;
    std::cout << "Installed Memory: " << Memory::FindAllRAM() << "GB" << std::endl;
    std::cout << "Used Memory: " << Memory::FindUsedRAM() << "GB" << std::endl;
    std::cout << "Free Memory: " << Memory::FindFreeRAM() << "GB" << std::endl;
    std::cout << "Disk Capacity: " << Storage::FindDiskCapacity() << "GB" <<std::endl;
    std::cout << "Free Disk Space: " << Storage::FindFreeDiskSpace() << "GB" << std::endl;
    std::cout << "Used Disk Space: " << Storage::FindUsedDiskSpace() << "GB" << std::endl;
    std::cout << "CPU: " << Computer::FindCPUName() << std::endl;
    std::cout << "CPU Cores: " << Computer::FindCPUCoreCount() << std::endl;
    std::cout << "GPU: " << Computer::FindGPUName() << std::endl;
    std::cout << "Native Resolution: " << resolution() << std::endl;
}
