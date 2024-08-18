// #include <gtest/gtest.h>
#include "AssignCookies.cpp" // Include the file where the cookies function is defined

TEST(CookiesTest, BasicTest) {
    vi greed = {1, 2, 3, 5, 8};
    vi cookie = {2, 1, 4, 6, 3};
    EXPECT_EQ(cookies(greed, cookie), 4);
}

TEST(CookiesTest, NoCookies) {
    vi greed = {1, 2, 3};
    vi cookie = {};
    EXPECT_EQ(cookies(greed, cookie), 0);
}

TEST(CookiesTest, NoGreedyChildren) {
    vi greed = {};
    vi cookie = {1, 2, 3};
    EXPECT_EQ(cookies(greed, cookie), 0);
}

TEST(CookiesTest, MoreCookiesThanGreedyChildren) {
    vi greed = {1, 2};
    vi cookie = {1, 2, 3, 4};
    EXPECT_EQ(cookies(greed, cookie), 2);
}

TEST(CookiesTest, MoreGreedyChildrenThanCookies) {
    vi greed = {1, 2, 3, 4, 5};
    vi cookie = {1, 2};
    EXPECT_EQ(cookies(greed, cookie), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}