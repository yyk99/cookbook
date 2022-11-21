//
//
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <codecvt>

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
                std::cout << std::hex << (unsigned int)c << ' ';
            }
            std::cout << '\n';
        }
    }
}
