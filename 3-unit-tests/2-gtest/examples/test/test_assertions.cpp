#include "list.hpp"

#include <gtest/gtest.h>

#include <iostream>

TEST(List, FailedAssert) {
    // Arrange
    otus::List<int> list;
    const size_t expected = 10;

    // Act (empty for this test)

    // Assert
    std::cout << "Before the assert" << std::endl;
    ASSERT_EQ(list.size(), expected); // This should fail
    std::cout << "After the assert" << std::endl;
}

TEST(List, FailedExpect) {
    // Arrange
    otus::List<int> list;
    const size_t expected = 10;

    // Act (empty for this test)

    // Assert
    std::cout << "Before the expect" << std::endl;
    EXPECT_EQ(list.size(), expected); // This should fail
    std::cout << "After the expect" << std::endl;

    EXPECT_LE(list.size(), expected);
}

TEST(List, Success) {
    // Arrange
    otus::List<int> list;
    const size_t expected = 0;

    // Act (empty for this test)

    // Assert
    EXPECT_EQ(list.size(), expected);
}

TEST(List, EmptyExceptions) {
    // Arrange
    otus::List<int> list;

    // Act (empty again)

    // Assert
    EXPECT_THROW(
        list.pop_back(),
        std::exception
    );
    EXPECT_THROW(
        list.pop_front(),
        std::exception
    );

    EXPECT_THROW(
        list.size(),
        std::exception
    );
}

TEST(Assertions, Strings) {
    const char * first = "Hello, World!";
    const char * second = "hello, world!";

    EXPECT_STREQ(first, second);
    EXPECT_STRNE(first, second);
    EXPECT_STRCASEEQ(first, second);
}

TEST(Assertions, DISABLED_DisabledTestExample) {
    const char * first = "Hello, World 2!";
    const char * second = "hello, world 2!";

    EXPECT_STREQ(first, second);
    EXPECT_STRNE(first, second);
    EXPECT_STRCASEEQ(first, second);
}
TEST(DISABLED_Assertions, DisabledTestExample2) {
    const char * first = "Hello, World 3!";
    const char * second = "hello, world 3!";

    EXPECT_STREQ(first, second);
    EXPECT_STRNE(first, second);
    EXPECT_STRCASEEQ(first, second);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}