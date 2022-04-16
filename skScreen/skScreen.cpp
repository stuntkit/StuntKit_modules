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
