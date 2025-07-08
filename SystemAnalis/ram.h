#ifndef RAM_H
#define RAM_H

#include <sysinfoapi.h>
#include <string>
#include <iostream>

#ifdef _WIN32
#define CMD "wmic memorychip get speed"
#else
#define CMD "sudo dmidecode -t memory | grep Speed" // Requires root privileges for dmidecode
#endif

class RAM{

    const int MAX = 1024;
    MEMORYSTATUSEX status;

public:
    RAM();

    DWORDLONG total() const;
    DWORDLONG available() const;
    DWORDLONG used() const;
    DWORD memoryLoad() const;
    std::string speed() const;
};

#endif // RAM_H
