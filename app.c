#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

extern "C"
{
#include "sample.h"
}


TEST_GROUP(TG1){};
TEST_GROUP(TG2){};

TEST(TG1, test_case1)
{
    int a = ret_sub(5, 4);
    CHECK_EQUAL_TEXT(2, a, "test_case1 Fail...");
}

TEST(TG1, test_case2)
{
    int a = ret_add(5, 4);
    CHECK_EQUAL_TEXT(9, a, "test_case2 Fail...");
}

TEST(TG2, test_case3)
{
    int* ptr = NULL;
    int a = 0;
    POINTERS_EQUAL_TEXT(&a, ptr, "test_case3 Fail...");
}

TEST(TG2, test_case4)
{
    int a = 0;
    int* ptr = NULL;
    ptr = &a;
    POINTERS_EQUAL_TEXT(&a, ptr, "test_case4 Fail...");
}

int main(int argc, char *argv[])
{
    CommandLineTestRunner::RunAllTests(argc, argv);
    return 0;
}
