#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;


/*
There is a room with n bulbs labeled from 1 to n that all are turned on initially, and four buttons on the wall. Each of the four buttons has a different functionality where:

- Button 1: Flips the status of all the bulbs.
- Button 2: Flips the status of all the bulbs with even labels (i.e., 2, 4, ...).
- Button 3: Flips the status of all the bulbs with odd labels (i.e., 1, 3, ...).
- Button 4: Flips the status of all the bulbs with a label j = 3k + 1 where k = 0, 1, 2, ... (i.e., 1, 4, 7, 10, ...).
You must make exactly presses button presses in total. For each press, you may pick any of the four buttons to press.

Given the two integers n and presses, return the number of different possible statuses after performing all presses button presses.

n개의 전구가 있는 방이 있고, 처음에는 모든 전구가 켜져 있습니다. 벽에는 4개의 버튼이 있으며, 각 버튼은 다음과 같은 기능을 합니다:

버튼 1: 모든 전구의 상태를 반전시킵니다.
버튼 2: 짝수 번호의 전구 상태를 반전시킵니다 (즉, 2, 4, ...).
버튼 3: 홀수 번호의 전구 상태를 반전시킵니다 (즉, 1, 3, ...).
버튼 4: j = 3k + 1 형태의 번호를 가진 전구의 상태를 반전시킵니다. 여기서 k = 0, 1, 2, ... (즉, 1, 4, 7, 10, ...).
당신은 정확히 'presses'번 버튼을 눌러야 합니다. 각 누름마다 4개의 버튼 중 아무 버튼이나 선택할 수 있습니다.

두 개의 정수 n과 presses가 주어졌을 때, 모든 버튼 누름을 수행한 후 가능한 서로 다른 전구 상태의 개수를 반환하세요.

예를 들어, n=2(전구가 2개)이고 presses=2(버튼을 2번 눌러야 함)인 경우, 가능한 모든 조합을 시도해서 최종적으로 나올 수 있는 서로 다른 전구 상태의 개수를 찾아야 합니다.

Constraints:
- 1 <= n <= 1000
- 0 <= presses <= 1000

 */

class Solution {
public:
    int flipLights(int n, int presses) {
        // 6개 이상의 전구는 패턴이 반복됨
        n = min(n, 6);

        // presses가 0인 경우
        if (presses == 0) {
            return 1;
        }

        // n이 1인 경우
        if (n == 1) {
            return 2;  // 켜짐/꺼짐 두 가지 상태만 가능
        }

        // n이 2인 경우
        if (n == 2) {
            return presses >= 2 ? 4 : 3;
        }

        // n >= 3인 경우
        if (presses == 1) {
            return 4;
        }
        else if (presses == 2) {
            return 7;
        }
        else {  // presses >= 3
            return 8;
        }
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
	EXPECT_EQ(this->s.flipLights(1, 1), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.flipLights(2, 1), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.flipLights(3, 1), 4);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}