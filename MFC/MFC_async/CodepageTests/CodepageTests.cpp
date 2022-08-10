//
//
//

#include <iostream>
#include <wtypes.h>
#include <gtest/gtest.h>

class CodepageF : public testing::Test
{
public:

};

TEST(CodepageF, t1)
{
    std::cout << "sizeof(CHAR): " << sizeof(CHAR) << std::endl;
    std::cout << "sizeof(WCHAR): " << sizeof(WCHAR) << std::endl;

    std::cout << "Hello" << std::endl;
    std::wcout << L"Hello" << std::endl;
}

TEST(CodepageF, t2)
{
    std::wstring s(L"Пассатижи");
    for (auto c : s)
        printf("\\x%02x", c & 255);
    printf("\n");

    std::wcout << "sizeof(s[0]):" << sizeof(s[0]) << std::endl;
    std::wcout << "s.size():" << s.size() << std::endl;
    std::wcout << "s:" << s << std::endl;
}

TEST(CodepageF, t3)
{
    std::string s("Пассатижи");
    for (auto c : s)
        printf("\\x%02x", c & 255);
    printf("\n");

    std::cout << "sizeof(s[0]):" << sizeof(s[0]) << std::endl;
    std::cout << "s.size():" << s.size() << std::endl;
    std::cout << "s:" << s << std::endl;
}