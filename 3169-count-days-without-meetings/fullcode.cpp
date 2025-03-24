#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <any>

using namespace std;



/* https://leetcode.com/problems/count-days-without-meetings/?envType=daily-question&envId=2025-03-24
 * @lc app=leetcode id=3169 lang=cpp
 * [3169] Count Days Without Meetings

You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
Return the count of days when the employee is available for work but no meetings are scheduled.
Note: The meetings may overlap.

직원이 일할 수 있는 총 일수를 나타내는 양의 정수 days가 주어집니다(1일부터 시작). 또한 크기가 n인 2D 배열 meetings가 주어지는데, meetings[i] = [start_i, end_i]는 i번째 회의의 시작일과 종료일을 나타냅니다(포함).
직원이 일할 수 있지만 회의가 예약되지 않은 날의 수를 반환하세요.
참고: 회의는 겹칠 수 있습니다.

Constraints:
1 <= days <= 10**9
1 <= meetings.length <= 10**5
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
 */

// @lc code=start
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });

        vector<vector<int>> merged_meetings;
        for (int i = 0; i < meetings.size(); i++) {
            if (merged_meetings.empty() || merged_meetings.back()[1] < meetings[i][0]) {
                merged_meetings.push_back(meetings[i]);
            } else {
                merged_meetings.back()[1] = max(merged_meetings.back()[1], meetings[i][1]);
            }
        }

        int count = 0;
        for (int i = 0; i < merged_meetings.size(); i++) {
            count += merged_meetings[i][1] - merged_meetings[i][0] + 1;
        }
        if (count >= days) {
            return 0;
        }
        return days - count;
    }
};
// @lc code=end




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
    // Example 1:
    // Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
    // Output: 2
    // Explanation:
    // There is no meeting scheduled on the 4th and 8th days.

    vector<vector<int>> meetings1 = {{5,7},{1,3},{9,10}};
    int days1 = 10;
    EXPECT_EQ(this->s.countDays(days1, meetings1), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: days = 5, meetings = [[2,4],[1,3]]
    // Output: 1
    // Explanation:
    // There is no meeting scheduled on the 5th day.

    vector<vector<int>> meetings2 = {{2,4},{1,3}};
    int days2 = 5;
    EXPECT_EQ(this->s.countDays(days2, meetings2), 1);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: days = 6, meetings = [[1,6]]
    // Output: 0
    // Explanation:
    // Meetings are scheduled for all working days.

    vector<vector<int>> meetings3 = {{1,6}};
    int days3 = 6;
    EXPECT_EQ(this->s.countDays(days3, meetings3), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: days = 6, meetings = [[1,6]]
    // Output: 0
    // Explanation:
    // Meetings are scheduled for all working days.

    vector<vector<int>> meetings3 = {{1,6}, {2, 3}};
    int days3 = 10;
    EXPECT_EQ(this->s.countDays(days3, meetings3), 4);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
