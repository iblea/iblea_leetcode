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



/* https://leetcode.com/problems/maximum-candies-allocated-to-k-children/?envType=daily-question&envId=2025-03-14
 * @lc app=leetcode id=2226 lang=cpp
 * [2226] Maximum Candies Allocated to K Children

You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. You can divide each pile into any number of sub piles, but you cannot merge two piles together.
You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.
Return the maximum number of candies each child can get.

0-인덱스 정수 배열 candies가 주어집니다. 배열의 각 요소는 candies[i] 크기의 사탕 더미를 나타냅니다. 각 더미를 여러 개의 하위 더미로 나눌 수 있지만, 두 더미를 합칠 수는 없습니다.
또한 정수 k가 주어집니다. k명의 아이들에게 사탕 더미를 할당해야 하며, 각 아이는 동일한 수의 사탕을 받아야 합니다. 각 아이는 오직 하나의 사탕 더미에서만 사탕을 할당받을 수 있으며, 일부 사탕 더미는 사용되지 않을 수 있습니다.
각 아이가 받을 수 있는 최대 사탕 개수를 반환하세요.


Constraints:
1 <= candies.length <= 10**5
1 <= candies[i] <= 10**7
1 <= k <= 10**12
 */

// @lc code=start
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end());
        int n = candies.size();

        int min_candies = 0;
        int max_candies = candies[n - 1];

        int result = 0;
        while (min_candies <= max_candies) {
            int mid_candies = (max_candies + min_candies) / 2;
            if (mid_candies == 0) {
                if (min_candies != 0) {
                    break;
                }
                min_candies = 1;
                continue;
            }
            long long count = 0;
            for (int i = 0; i < n; i++) {
                count += candies[i] / mid_candies;
                if (count >= k) {
                    break;
                }
            }
            if (count >= k) {
                result = mid_candies;
                min_candies = mid_candies + 1;
            } else {
                max_candies = mid_candies - 1;
            }
        }
        return result;
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
    // Input: candies = [5,8,6], k = 3
    // Output: 5
    // Explanation: We can divide candies[1] into 2 piles of size 5 and 3, and candies[2] into 2 piles of size 5 and 1. We now have five piles of candies of sizes 5, 5, 3, 5, and 1. We can allocate the 3 piles of size 5 to 3 children. It can be proven that each child cannot receive more than 5 candies.
    // 설명: candies[1]을 크기가 5와 3인 2개의 더미로 나누고, candies[2]를 크기가 5와 1인 2개의 더미로 나눌 수 있습니다. 이제 크기가 5, 5, 3, 5, 1인 5개의 사탕 더미가 있습니다. 크기가 5인 3개의 더미를 3명의 아이들에게 할당할 수 있습니다. 각 아이가 5개 이상의 사탕을 받을 수 없다는 것을 증명할 수 있습니다.

    vector<int> candies = {5, 8, 6};
    long long k = 3;
	EXPECT_EQ(this->s.maximumCandies(candies, k), 5);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: candies = [2,5], k = 11
    // Output: 0
    // Explanation: There are 11 children but only 7 candies in total, so it is impossible to ensure each child receives at least one candy. Thus, each child gets no candy and the answer is 0.

    vector<int> candies = {2, 5};
    long long k = 11;
	EXPECT_EQ(this->s.maximumCandies(candies, k), 0);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> candies = {1};
    long long k = 1;
	EXPECT_EQ(this->s.maximumCandies(candies, k), 1);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
