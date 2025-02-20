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



/* https://leetcode.com/problems/find-unique-binary-string/?envType=daily-question&envId=2025-02-20
 * @lc app=leetcode id=1980 lang=cpp
 * [1980] Find Unique Binary String

Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

길이가 n인 고유한 이진 문자열 n개를 포함하는 문자열 배열 nums가 주어졌을 때, nums에 나타나지 않는 길이 n의 이진 문자열을 반환합니다. 여러 답이 있는 경우 그 중 아무거나 반환해도 됩니다.

Constraints:
n == nums.length
1 <= n <= 16
nums[i].length == n
nums[i] is either '0' or '1'.
All the strings of nums are unique.
 */

// @lc code=start
class Solution {
private:
    std::string intToBinary(int n, int len) {
        if (n == 0) {
            return std::string(len, '0');
        }
        std::string result;
        while (n > 0) {
            result = (n % 2 ? '1' : '0') + result;
            n /= 2;
        }
        if (result.length() < len) {
            result = std::string(len - result.length(), '0') + result;
        }
        return result;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;

        int nlen = nums.size();
        int generated_limit = 17;
        if (nlen <= 4) {
            generated_limit = 1 << nlen;
        }
        std::cout << "generated_limit : " << generated_limit << std::endl;
        for (int i = 0; i < generated_limit; i++) {
            string str = intToBinary(i, nlen);
            std::cout << str << std::endl;
            s.insert(str);
        }
        for (auto& str : nums) {
            if (s.find(str) != s.end()) {
                s.erase(str);
            }
        }
        return *s.begin();
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
    // Input: nums = ["01","10"]
    // Output: "11"
    // Explanation: "11" does not appear in nums. "00" would also be correct.

    vector<string> nums = {"01","10"};
    vector<string> answer = {"11", "00"};
    bool is_found = false;
    string result = this->s.findDifferentBinaryString(nums);
    std::cout << "result : " << result << std::endl;
    for (auto& ans : answer) {
        if (result == ans) {
            is_found = true;
            break;
        }
    }
    EXPECT_TRUE(is_found);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: nums = ["00","01"]
    // Output: "11"
    // Explanation: "11" does not appear in nums. "10" would also be correct.

    vector<string> nums = {"00","01"};
    vector<string> answer = {"11", "10"};
    bool is_found = false;
    string result = this->s.findDifferentBinaryString(nums);
    std::cout << "result : " << result << std::endl;
    for (auto& ans : answer) {
        if (result == ans) {
            is_found = true;
            break;
        }
    }
    EXPECT_TRUE(is_found);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 3:
    // Input: nums = ["111","011","001"]
    // Output: "101"
    // Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

    vector<string> nums = {"111","011","001"};
    vector<string> answer = {"101", "000", "010", "100", "110"};
    bool is_found = false;
    string result = this->s.findDifferentBinaryString(nums);
    std::cout << "result : " << result << std::endl;
    for (auto& ans : answer) {
        if (result == ans) {
            is_found = true;
            break;
        }
    }
    EXPECT_TRUE(is_found);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
