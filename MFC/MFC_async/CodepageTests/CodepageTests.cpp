//
//
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <wtypes.h>
#include <stringapiset.h>
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

    {
        int wchars_num = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, NULL, 0);
        std::vector<wchar_t> wstr(wchars_num);

        MultiByteToWideChar(CP_UTF8, 0, s.c_str(), -1, wstr.data(), int(wstr.size()));
        
        for (auto c : wstr)
            printf("\\x%04x", c & 0xffff);
        printf("\n");

        FILE* fp = fopen("CodepageF_t3.txt", "wb");

        ASSERT_TRUE(fp != NULL);
        fwrite("\xff\xfe", 2, 1, fp);
        fwrite(wstr.data(), wstr.size(), sizeof(wstr[0]), fp);
        fclose(fp);
    }
}

TEST(CodepageF, t4)
{
    {
        uint8_t s[] = u8"1234567";
        printf("sizeof(s) = %d\n", (int)sizeof(s));
        printf("strlen(s) = %d\n", (int)strlen((const char*)s));
        for (auto c : s)
            printf("\\x%02x", c & 255);
        printf("\n");
    }
    {
        char s[] = u8"Пассатижи";
        printf("sizeof(s) = %d\n", (int)sizeof(s));
        printf("strlen(s) = %d\n", (int)strlen((const char*)s));
        for (auto c : s)
            printf("\\x%02x", c & 255);
        printf("\n");
        FILE* f = fopen("t4.txt", "wb");
        ASSERT_NE(nullptr, f);
        fputs((const char*)s, f);
        fclose(f);
    }
    {
        uint8_t s[] = "Пассатижи";
        printf("strlen(s) = %d\n", (int)strlen((const char*)s));
        for (auto c : s)
            printf("\\x%02x", c & 255);
        printf("\n");
    }
    //std::wcout << "sizeof(s[0]):" << sizeof(s[0]) << std::endl;
    //std::wcout << "s.size():" << s.size() << std::endl;
    //std::wcout << "s:" << s << std::endl;
}

/**
 * @brief 
 * @param  
 * @param  
*/
TEST(CodepageF, t5)
{
    int a = 1, b = 1;

    if (a > b) {
        ;
    } else {
        ;
    }

    switch (a) {
    case 1:
        break;
    case 2:
        break;
    default:
        ;
    }

    for (int i = 0; i < a; ++i) {
        ;
    }
}