#include "gameVersion.hpp"

GameVersion::GameVersion() {
    this->hash = calculateGameHash();

    hash = getGameHash();
    if (hash == "E4BAF3E5CACD51AFCE61007F72781167") {
        release = Release::International;
        api = API::DirectX;
    }
    else if (hash == "C5801F89E46C53A67AC8D7C18A94ACD8") {
        release = Release::International;
        api = API::Glide;
    }
    else if (hash == "CE9A034310D45EED6D6E2C1B6014376E") {
        release = Release::Polish;
        api = API::DirectX;
    }
    else if (hash == "7D7EB6DFB099CF06FEF28F436CAE6E52") {
        release = Release::Polish;
        api = API::Glide;
    }

}

const bool GameVersion::isKnownGameVersion()
{
    if (release == Release::Unknown || api == API::Unknown)
    {
        return false;
    }
    return true;
}

const std::string GameVersion::getGameHash() {
    return hash;
}

const API GameVersion::getAPI()
{
    return api;
}

const Release GameVersion::getRelease()
{
    return release;
}

std::string GameVersion::calculateGameHash()
{
    std::string hash = "";

    char SGPpath[MAX_PATH];

    BOOL bResult = FALSE;
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    HANDLE hFile = NULL;
    BYTE rgbFile[BUFSIZE];
    DWORD cbRead = 0;
    BYTE rgbHash[MD5LEN];
    DWORD cbHash = 0;
    CHAR rgbDigits[] = "0123456789ABCDEF";

    GetModuleFileName(0, SGPpath, MAX_PATH);
    hFile = CreateFile(SGPpath,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_SEQUENTIAL_SCAN,
        NULL);

    if (INVALID_HANDLE_VALUE == hFile)
    {
        OutputDebugString("Error opening SGP file");
        return hash;
    }

    // Get handle to the crypto provider
    if (!CryptAcquireContext(&hProv,
        NULL,
        NULL,
        PROV_RSA_FULL,
        CRYPT_VERIFYCONTEXT))
    {
        OutputDebugString("CryptAcquireContext failed");
        CloseHandle(hFile);
        return hash;
    }

    if (!CryptCreateHash(hProv, CALG_MD5, 0, 0, &hHash))
    {
        OutputDebugString("CryptAcquireContext failed");
        CloseHandle(hFile);
        CryptReleaseContext(hProv, 0);
        return hash;
    }

    while (bResult = ReadFile(hFile, rgbFile, BUFSIZE,
        &cbRead, NULL))
    {
        if (0 == cbRead)
        {
            break;
        }

        if (!CryptHashData(hHash, rgbFile, cbRead, 0))
        {
            OutputDebugString("CryptHashData failed");
            CryptReleaseContext(hProv, 0);
            CryptDestroyHash(hHash);
            CloseHandle(hFile);
            return hash;
        }
    }

    if (!bResult)
    {
        OutputDebugString("ReadFile failed");
        CryptReleaseContext(hProv, 0);
        CryptDestroyHash(hHash);
        CloseHandle(hFile);
        return hash;
    }

    cbHash = MD5LEN;
    if (CryptGetHashParam(hHash, HP_HASHVAL, rgbHash, &cbHash, 0))
    {
        std::stringstream ss;
        for (DWORD i = 0; i < cbHash; i++)
        {
            ss << rgbDigits[rgbHash[i] >> 4] << rgbDigits[rgbHash[i] & 0xf];
        }
        hash = ss.str();
    }
    else
    {
        OutputDebugString("CryptGetHashParam failed");
    }

    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
    CloseHandle(hFile);

    return hash;
}