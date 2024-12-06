#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/*
 *
 */

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        string answer = "";
        for (string word: dictionary) {
            if (word.size() > s.size()) {
                continue;
            }
            int i = 0;
            for (char c : s) {
                if (i < word.size() && c == word[i]) {
                    i++;
                }
            }

            if (i == word.size()) {
                if (answer.size() < word.size()) {
                    answer = word;
                } else if (answer.size() == word.size() && answer > word) {
                    answer = word;
                }
            }
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
    std::vector<string> dictionary = {"ale","apple","monkey","plea"};
    string answer = this->s.findLongestWord("abpcplea", dictionary);
	EXPECT_EQ(answer, "apple");
}

TEST_F(CLASS_NAME, __LINE__)
{
    std::vector<string> dictionary = {"a","b","c"};
    string answer = this->s.findLongestWord("abpcplea", dictionary);
	EXPECT_EQ(answer, "a");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}