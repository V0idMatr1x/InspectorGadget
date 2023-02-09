//
// Created by chris on 2/7/2023.
//

#pragma once


namespace Windows {

    // Check's for & returns the licensed Windows edition
    static auto Edition() -> std::string {
        HKEY hKey;
        LONG result { RegOpenKeyEx(HKEY_LOCAL_MACHINE, R"(SOFTWARE\Microsoft\Windows NT\CurrentVersion)", 0, KEY_READ, &hKey) };

        char  edition[80];
        DWORD dwBufLen { sizeof(edition) };
        result = RegQueryValueEx(hKey, "EditionID", nullptr, nullptr, (LPBYTE) edition, &dwBufLen);

        if (result != ERROR_SUCCESS) {
            return "Unknown";
        }
        RegCloseKey(hKey);
        return edition;
    }

   // Check's if WSL is enabled or not
    static auto WSLStatus() -> std::string {
         HKEY hKey;
         LONG result { RegOpenKeyEx(HKEY_LOCAL_MACHINE, R"(SOFTWARE\Microsoft\Windows\CurrentVersion\Lxss)", 0, KEY_READ, &hKey) };

         if (result != ERROR_SUCCESS) {
              return "Disabled";
         }
         RegCloseKey(hKey);
         return "Enabled";
    }
};
