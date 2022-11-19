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
    if (argc == 2)
    {
        // open as a byte stream
        std::wifstream fin(argv[1], std::ios::binary);
        if (fin) {
            // apply BOM-sensitive UTF-16 facet
            fin.imbue(std::locale(fin.getloc(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
            std::cout << "Current locale : " << fin.getloc().name() << '\n';
            // read     
            for (wchar_t c; fin.get(c); )
            {
                // std::cout << std::showbase << std::hex << c << '\n';
                if (char c8 = (c >> 8) & 255) {
                    std::cout << "\\U+"
                        << std::hex << std::setw(4) << std::setfill('0')
                        << (unsigned)c;
                } else {
                    std::cout << char(c&255);
                }
            }
        } else {
            std::cerr << "Cannot open: " << argv[1] << " file\n";
        }
    } else {
        std::cerr << "Usage: " << argv[0] << " file\n";
    }
}