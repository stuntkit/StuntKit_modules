#include "init.hpp"

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: return Initialize();
    case DLL_PROCESS_DETACH: return Finalize();
    }
    return TRUE;
}


/*
void FixRatio()
{
    // 40b37, Polish D3D
    DWORD address = 0x440b37;

    // 0x40'15'55'55 = 2,3333, 21:9
    float ratio = 2.33333333f;
    DWORD flOldProtect;
    if (VirtualProtect((PVOID)address, 4, PAGE_EXECUTE_READWRITE, &flOldProtect)) // 0x40 = PAGE_EXECUTE_READWRITE
    {
        memcpy((PVOID)address, &ratio, 4);
        VirtualProtect((PVOID)address, 4, flOldProtect, &flOldProtect);
    }
}
*/