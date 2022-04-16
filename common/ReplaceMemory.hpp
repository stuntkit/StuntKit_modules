#include <string>
#include <sstream>
#include <windows.h>
// #include <Wincrypt.h>


void replaceMemory(DWORD address, const char data[], uint32_t length);

void replaceMemory(DWORD address, float number);
void replaceMemory(DWORD address, uint32_t number);
