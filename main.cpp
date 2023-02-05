#include <iostream>
#include "core.h"

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
    std::cout << asciiArt() << std::endl;
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
