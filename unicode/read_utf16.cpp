//
//
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <locale>
#include <codecvt>

int main(int argc, char** argv)
{
    if (argc >= 2)
    {
        for (int i = 1; i < argc; ++i)
        {
            std::cout << "File: " << argv[i] << "\n";
            std::wifstream fin(argv[i], std::ios::binary);
            if (fin) {
                // apply BOM-sensitive UTF-16 facet
#if 1
                fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
#else
                fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf16<wchar_t>));
#endif
                std::cout << "Current locale : " << fin.getloc().name() << '\n';
                // read
                for (wchar_t c; fin.get(c); )
                {
                    std::cout
                        << "0x"
                        << std::setw(4)
                        << std::setfill('0')
                        << std::hex
                        << c << '\n';
#if 0
                    if (char c8 = (c >> 8) & 255) {
                        std::cout << "\\U+"
                            << std::hex << std::setw(4) << std::setfill('0')
                            << (unsigned)c;
                    } else {
                        std::cout << char(c & 255);
                    }
#endif
                }
            } else {
                std::cerr << "Cannot open: " << argv[i] << " file\n";
            }
        }
    } else {
        std::cerr << "Usage: " << argv[0] << " file\n";
    }
}
