//
//
//

#include <fstream>

#include "parser12d.hpp"
#include "driver12d.h"


int main(int argc , char **argv)
{
    if (argc <= 1)
    {
        std::cout << "Usage: ...\n";
        exit(1);
    }

    std::ifstream in(argv[1], std::ios::binary);

    yyFlexLexer scanner{ reflex::Input(&in) };
#if 0
    yy::parser parse(scanner);
    return parse();
#else
    for (int i = 0; i < 10; ++i)
    {
        auto nxt = scanner.yylex();
        std::cout << nxt << '\n';
    }

    return 0;
#endif
}