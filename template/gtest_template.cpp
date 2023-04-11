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
	string template_function() { return "template_function"; };
};


#define CLASS_NAME gtest_template

class CLASS_NAME: public ::testing::Test {
private:
	clock_t t0;
	clock_t t1;
protected:
	CLASS_NAME() { }
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
	Solution s = Solution();
	EXPECT_EQ(s.template_function(), "template_function");
}

TEST_F(CLASS_NAME, __LINE__)
{
	#define MAX 1000000
	#define LMAX (long long int)MAX
	long long sum = 0;

	// set_start_time();
	for (int i = 1; i <= MAX; ++i) {
		sum += i;
	}
	// set_end_time();

	EXPECT_EQ(sum, ((1 + LMAX) * LMAX / 2));
	// get_duration_time();
}

/* print output
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from gtest_template
[ RUN      ] gtest_template.45

Duration of Times : 2.591ms, 0.003sec

[       OK ] gtest_template.45 (2 ms)
[----------] 1 test from gtest_template (2 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (2 ms total)
[  PASSED  ] 1 test.
*/

int main(int argc, char* argv[])
{
	testing::InitGoogleTest( &argc, argv );

	return RUN_ALL_TESTS();
}