#include "iostream"
#include "string"
using namespace std;

class SimilarityChecker {
public:
	SimilarityChecker(string question) : question{question} {

	}

	int charNumTest(string input) {
		double score;
		int len1 = question.size();
		int len2 = input.size();

		if (len1 == len2)
			return 60;

		if (len1 > len2) {
			if (len2 >= len1 * 2)
				return 0;
			score = ((double)1 - ((double)len1 - len2) / len2) * 60;
		}
		else {
			if (len1 >= len2 * 2)
				return 0;
			score = ((double)1 - ((double)len2 - len1) / len1) * 60;
		}

		return score;
	}

	int alpha(string input) {
		int SameCnt = 0, TotalCnt = 0;

		for (char c = 'A'; c <= 'Z'; c++) {
			if (strIncludesChar(question, c) || strIncludesChar(input, c))
				TotalCnt++;

			if (strIncludesChar(question, c) && strIncludesChar(input, c))
				SameCnt++;
		}

		return getAlphaScore(SameCnt, TotalCnt);
	}

	bool strIncludesChar(string str, char c) {
		return (str.find(c) != string::npos);
	}

	int getAlphaScore(int same_count, int total_count) {
		return ((double)same_count / total_count * maxAlphaScore);
	}

private:
	const int maxAlphaScore = 40;
	string question;
};