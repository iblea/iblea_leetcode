#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;


/*
You are given two jugs with capacities x liters and y liters. You have an infinite water supply. Return whether the total amount of water in both jugs may reach target using the following operations:

Fill either jug completely with water.
Completely empty either jug.
Pour water from one jug into another until the receiving jug is full, or the transferring jug is empty.

두 개의 물병이 있는데, 각각 x 리터와 y 리터를 담을 수 있는 용량을 가지고 있습니다. 무한한 물 공급이 가능한 상황에서, 다음과 같은 작업들을 통해 두 물병에 있는 물의 총량이 목표량(target)에 도달할 수 있는지 여부를 반환하는 문제입니다:

가능한 작업들:

어느 한 물병을 완전히 채우기
어느 한 물병을 완전히 비우기
한 물병에서 다른 물병으로 물을 부어서, 받는 물병이 가득 차거나 붓는 물병이 완전히 빌 때까지 물을 옮기기

1 <= x, y, target <= 10**3

*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        set<pair<int, int>> visited;

        queue<pair<int, int>> q;
        q.push({0, 0});

        while (! q.empty()) {
            auto [a, b] = q.front();
            q.pop();

            if (a == target || b == target || a + b == target) {
                return true;
            }

            if (visited.count({a, b})) {
                continue;
            }
            visited.insert({a, b});

            q.push({x, b});
            q.push({a, y});
            if (a > 0 && visited.find({0, b}) == visited.end()) q.push({0, b});
            if (b > 0 && visited.find({a, 0}) == visited.end()) q.push({0, b});

            pair<int, int> a_to_b = {a - min(a, y - b), b + min(a, y - b)};
            pair <int, int> b_to_a = {a + min(b, x - a), b - min(b, x - a)};
            if (visited.find(a_to_b) == visited.end()) q.push(a_to_b);
            if (visited.find(b_to_a) == visited.end()) q.push(b_to_a);
        }

        return false;
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
	EXPECT_EQ(this->s.canMeasureWater(3, 5, 4), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canMeasureWater(2, 6, 5), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	EXPECT_EQ(this->s.canMeasureWater(1, 2, 3), true);
    // Explanation: Fill both jugs. The total amount of water in both jugs is equal to 3 now.
    // 두 개의 주전자를 채웁니다. 이제 두 주전자의 물의 총 양은 3개가 됩니다.
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}