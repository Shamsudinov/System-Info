#include "ram.h"

RAM::RAM(){

    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx(&status);
}

DWORDLONG RAM::total() const{
    return status.ullTotalPhys/(MAX * MAX);
}

DWORDLONG RAM::available() const{
    return status.ullAvailPhys/(MAX * MAX);
}

DWORDLONG RAM::used() const{
    return status.ullTotalPhys / (MAX * MAX) - status.ullAvailPhys / (MAX * MAX);
}

DWORD RAM::memoryLoad() const{
    return status.dwMemoryLoad;
}

std::string RAM::speed() const
{
    FILE* pipe = popen(CMD, "r");
    if (!pipe) {
        return "Error executing command." ;
    }

    char buffer[128];
    std::string result = "";
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}
