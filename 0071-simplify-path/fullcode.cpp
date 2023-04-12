#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


/*
1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
 */

class Solution {
public:
	void path_check(string* path, vector<string> *result) {
		if (path->empty()) {
			return ;
		}
		if ((*path) == ".") {
			return ;
		}
		if ((*path) == "..") {
			if (result->empty() == false) {
				result->pop_back();
			}
			return ;
		}
		result->push_back((*path));
	}
	string simplifyPath(string path) {
		if (path.empty()) {
			return "";
		}
		vector<string> result{};
		string tmp;
		for (size_t i = 1; i < path.length(); ++i) {
			if (path[i] == '/') {
				this->path_check(&tmp, &result);
				tmp.clear();
				continue;
			}
			tmp += path[i];
		}
		if (tmp.empty() == false) {
			path_check(&tmp, &result);
		}
		string res = "";
		if (result.empty()) {
			return "/";
		}
		for (size_t i = 0; i < result.size(); i++) {
			res += ("/" + result[i]);
		}
		return res;
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
	string input = "/home/";
	string output = "/home";
	EXPECT_EQ(this->s.simplifyPath(input), output);
}

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "/../";
	string output = "/";
	EXPECT_EQ(this->s.simplifyPath(input), output);
}

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "/home//foo/";
	string output = "/home/foo";
	EXPECT_EQ(this->s.simplifyPath(input), output);
}

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "/test/./test";
	string output = "/test/test";
	EXPECT_EQ(this->s.simplifyPath(input), output);
}

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "/a/./b/../../c/";
	string output = "/c";
	EXPECT_EQ(this->s.simplifyPath(input), output);
}

TEST_F(CLASS_NAME, __LINE__)
{
	string input = "/a//b////c/d//././/..";
	string output = "/a/b/c";
	EXPECT_EQ(this->s.simplifyPath(input), output);
}

