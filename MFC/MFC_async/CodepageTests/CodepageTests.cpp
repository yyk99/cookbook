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

    std::cout << "Hello" << std::endl;
}