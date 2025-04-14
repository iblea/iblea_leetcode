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



/* https://leetcode.com/problems/count-good-triplets/?envType=daily-question&envId=2025-04-14
 * @lc app=leetcode id=1534 lang=cpp
 * [1534] Count Good Triplets

Given an array of integers arr, and three integers a, b and c. You need to find the number of good triplets.
A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

정수 배열 arr와 세 개의 정수 a, b, c가 주어집니다. 좋은 삼중항의 개수를 찾아야 합니다.
삼중항 (arr[i], arr[j], arr[k])은 다음 조건이 참일 때 좋은 삼중항입니다:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.
Return the number of good triplets.

여기서 |x|는 x의 절댓값을 나타냅니다.
좋은 삼중항의 개수를 반환하세요.

Constraints:
3 <= arr.length <= 100
0 <= arr[i] <= 1000
0 <= a, b, c <= 1000
 */

// @lc code=start
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int N = arr.size();
        int Na = N - 2;
        int Nb = N - 1;

        int Ai, Aj;
        for (int i = 0; i < Na; i++) {
            Ai = arr[i];
            for (int j = i + 1; j < Nb; j++) {
                Aj = arr[j];
                if (abs(Ai - Aj) > a) continue;
                for (int k = j + 1; k < N; k++) {
                    if (abs(Ai - arr[k]) > c) continue;
                    if (abs(Aj - arr[k]) > b) continue;
                    count++;
                }
            }
        }
        return count;
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
    // Input: arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3
    // Output: 4
    // Explanation: There are 4 good triplets: [(3,0,1), (3,0,1), (3,1,1), (0,1,1)].
    vector<int> arr = {3,0,1,1,9,7};
    int a = 7;
    int b = 2;
    int c = 3;
    int expected = 4;
    EXPECT_EQ(this->s.countGoodTriplets(arr, a, b, c), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: arr = [1,1,2,2,3], a = 0, b = 0, c = 1
    // Output: 0
    // Explanation: No triplet satisfies all conditions.

    vector<int> arr = {1,1,2,2,3};
    int a = 0;
    int b = 0;
    int c = 1;
    int expected = 0;
    EXPECT_EQ(this->s.countGoodTriplets(arr, a, b, c), expected);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
