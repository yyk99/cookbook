//
//
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <codecvt>

// Based on
// https://stackoverflow.com/questions/4775437/read-unicode-utf-8-file-into-wstring
std::wstring readFile(const char* filename)
{
    std::wifstream wif(filename);
    wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}

int main(int argc, char** argv)
{
    if (argc >= 2)
    {
        for (int i = 1; i < argc; ++i)
        {
            std::cout << "File: " << argv[i] << "\n";
            auto s = readFile(argv[i]);

            for (wchar_t c : s)
            {
                std::cout << std::hex << std::setw(4) << std::setfill('0') << (unsigned int)c << ' ';
            }
            std::cout << '\n';
        }
    }
}
