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



/* https://leetcode.com/problems/minimum-time-to-repair-cars/?envType=daily-question&envId=2025-03-16
 * @lc app=leetcode id=2594 lang=cpp
 * [2594] Minimum Time to Repair Cars

You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n^2 minutes.
You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.
Return the minimum time taken to repair all the cars.
Note: All the mechanics can repair the cars simultaneously.

정수 배열 ranks가 주어지며, 이는 몇몇 정비공들의 등급을 나타냅니다. ranks[i]는 i번째 정비공의 등급입니다. 등급이 r인 정비공은 n대의 차를 r * n^2 분 안에 수리할 수 있습니다.
또한 정수 cars가 주어지며, 이는 차고에서 수리를 기다리는 총 차량 수를 나타냅니다.
모든 차를 수리하는 데 걸리는 최소 시간을 반환하세요.
참고: 모든 정비공은 동시에 차를 수리할 수 있습니다.


Constraints:
1 <= ranks.length <= 10^5
1 <= ranks[i] <= 100
1 <= cars <= 10^6
 */

// @lc code=start
class Solution {

private:
    // 0 - Time, 1 - Rank, 2 - Repair Count
    long long getTime(vector<long long> &data) {
        // 정비공이 다음 차를 수리하는 데 걸리는 시간.
        long long return_value = data[0];
        data[2]++;
        data[0] = data[1] * data[2] * data[2];
        return return_value;
    }
public:
    long long repairCars_TimeLimitExcced(vector<int>& ranks, int cars) {

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        for (int rank : ranks) {
            pq.push({rank, rank, 1});
        }

        long long time = 0;
        for (int cnt = 0; cnt < cars; ++cnt) {
            vector<long long> data = pq.top();
            pq.pop();
            time = max(time, getTime(data));
            pq.push(data);
        }
        return time;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());

        long long left = 0;
        long long right = ranks[ranks.size() - 1] * cars * cars;

        while (left < right) {
            long long mid = (left + right) / 2;

            long long count = 0;
            for (int rank : ranks) {
                count += sqrt(mid / rank);
            }

            if (count < cars) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
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
    // Input: ranks = [4,2,3,1], cars = 10
    // Output: 16
    // Explanation:
    // - The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
    // - The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
    // - The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
    // - The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
    // It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    EXPECT_EQ(this->s.repairCars(ranks, cars), 16);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: ranks = [5,1,8], cars = 6
    // Output: 16
    // Explanation:
    // - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
    // - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
    // - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
    // It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

    vector<int> ranks = {5,1,8};
    int cars = 6;
    EXPECT_EQ(this->s.repairCars(ranks, cars), 16);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: ranks = [5,1,8], cars = 6
    // Output: 16
    // Explanation:
    // - The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
    // - The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
    // - The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
    // It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​

    vector<int> ranks = {1,7,10};
    int cars = 2;
    EXPECT_EQ(this->s.repairCars(ranks, cars), 4);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
