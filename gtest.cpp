#include <gtest/gtest.h>
#include <sstream>
#include "HappyNumber.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// TEST Parser
TEST(Parser, Valid) {
    std::istringstream input("1 2\n3\n4\n5\n6 7\n8\n9");
    std::vector<int> expected = {1,2,3,4,5,6,7,8,9};
    EXPECT_EQ(Parser::get_data(input), expected);
}

TEST(Parser, EmptyInput) {
    std::istringstream input("");
    std::vector<int> result = Parser::get_data(input);
    EXPECT_TRUE(result.empty());
}

TEST(Parser, LineWithLetters) {
    std::istringstream input("abc");
    EXPECT_THROW(Parser::get_data(input), std::runtime_error);
}

// TEST HappyNumber
TEST(HappyNumberTest, NegativeThrows) {
    EXPECT_THROW(HappyNumber(-1), std::invalid_argument);
}

TEST(HappyNumberTest, KnownHappy) {
    EXPECT_TRUE(HappyNumber(19).is_happy());
    EXPECT_TRUE(HappyNumber(7).is_happy());
}

TEST(HappyNumberTest, KnownUnhappy) {
    EXPECT_FALSE(HappyNumber(20).is_happy());
    EXPECT_FALSE(HappyNumber(4).is_happy());
}
