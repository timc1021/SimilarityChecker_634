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

TEST(simChecker, Alpha1) {
	string org = "ASD", input = "DSA";

	SimilarityChecker sc(org);
	int actual = sc.alpha(input);

	EXPECT_EQ(actual, 40);
}

TEST(simChecker, Alpha2) {
	string org = "A", input = "BB";

	SimilarityChecker sc(org);
	int actual = sc.alpha(input);

	EXPECT_EQ(actual, 0);
}

TEST(simChecker, Alpha3) {
	string org = "AAABB", input = "BA";

	SimilarityChecker sc(org);
	int actual = sc.alpha(input);

	EXPECT_EQ(actual, 40);
}

TEST(simChecker, Alpha4) {
	string org = "AA", input = "AAE";

	SimilarityChecker sc(org);
	int actual = sc.alpha(input);

	EXPECT_EQ(actual, 20);
}

int main(void) {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}