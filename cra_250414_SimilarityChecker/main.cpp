#include "iostream"
#include "string"
#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace std;

TEST(simChecker, TC1) {
	string org = "ASD", input = "DSA";

	SimilarityChecker sc(org);
	int actual = sc.charNumTest(input);

	EXPECT_EQ(actual, 60);
}

TEST(simChecker, TC2) {
	string org = "A", input = "BB";

	SimilarityChecker sc(org);
	int actual = sc.charNumTest(input);

	EXPECT_EQ(actual, 0);
}

TEST(simChecker, TC3) {
	string org = "AAABB", input = "BAA";

	SimilarityChecker sc(org);
	int actual = sc.charNumTest(input);

	EXPECT_EQ(actual, 20);
}

TEST(simChecker, TC4) {
	string org = "AA", input = "AAE";

	SimilarityChecker sc(org);
	int actual = sc.charNumTest(input);

	EXPECT_EQ(actual, 30);
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}