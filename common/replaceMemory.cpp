#include "../common/ReplaceMemory.hpp"

void replaceMemory(DWORD address, const char data[], uint32_t length)
{
    DWORD flOldProtect;
    if (VirtualProtect((PVOID)address, length, PAGE_EXECUTE_READWRITE, &flOldProtect))
    {
        memcpy((PVOID)address, &data[0], length);
        VirtualProtect((PVOID)address, length, flOldProtect, &flOldProtect);
    }
}


void replaceMemory(DWORD address, float number)
{
    char data[4];
    memcpy(data, &number, 4);
    replaceMemory(address, data, 4);
}

void replaceMemory(DWORD address, uint32_t number)
{
    char data[4];
    memcpy(data, &number, 4);
    replaceMemory(address, data, 4);
}
