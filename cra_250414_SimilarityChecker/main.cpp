#include "iostream"
#include "gmock/gmock.h"
#include "similarityChecker.cpp"

TEST(simChecker, TC1) {
	EXPECT_EQ(1, 1);
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}