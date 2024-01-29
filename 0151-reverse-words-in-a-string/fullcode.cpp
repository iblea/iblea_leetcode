#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;


/*
 *
 */

class Solution {
public:
    string reverseWords(string s) {
		stringstream stream;
		string split_word;
		string answer = "";

		cout << s << endl;
		stream.str(s);
		while (stream >> split_word) {
			answer = (split_word + " ");
		}
		if (answer.empty() == false) {
			answer.erase(answer.size() - 1);
		}
		return answer;
    }
};




#define CLASS_NAME gtest_template

class CLASS_NAME: public ::testing::Test {
private:
	clock_t t0;
	clock_t t1;
public:
	Solution s;
protected:
	CLASS_NAME() { this->s = Solution(); }
	~CLASS_NAME() override { }

	void SetUp() override { set_start_time(); }
	void TearDown() override { set_end_time(); get_duration_time(); }

	void set_start_time() {
		this->t0 = clock(); // or gettimeofday or whatever
	}
	void set_end_time() {
		this->t1 = clock(); // or gettimeofday or whatever
	}

	// 시간 관련 체크
	void get_duration_time() {
		double elapsedSec = (double)(this->t1 - this->t0) / (double)1000000;
		double elapsedMS = (double)(this->t1 - this->t0) / (double)1000;

		cout << setprecision(3) << fixed << endl << "Duration of Times : ";
		cout << elapsedMS << "ms, " << elapsedSec << "sec" << endl << endl;
	}

};

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "the sky is blue";
	string answer = "blue is sky the";

	EXPECT_EQ(this->s.reverseWords(input), answer);
}

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "  hello world  ";
	string answer = "world hello";

	EXPECT_EQ(this->s.reverseWords(input), answer);
}

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "a good   example";
	string answer = "example good a";

	EXPECT_EQ(this->s.reverseWords(input), answer);
}
