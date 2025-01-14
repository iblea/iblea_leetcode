#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;



/*
https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14
 * @lc app=leetcode id=2657 lang=cpp
 * [2657] Find the Prefix Common Array of Two Arrays

You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

두 개의 0-인덱스 정수 순열 A와 B가 주어집니다.
A와 B의 접두사 공통 배열은 C라는 배열로, C[i]는 A와 B의 인덱스 i 이전 또는 i에 존재하는 숫자의 개수와 같습니다.
A와 B의 접두사 공통 배열을 반환합니다.
n개의 정수 시퀀스는 1부터 n까지의 모든 정수를 정확히 한 번 포함하는 경우 순열이라고 합니다.


Constraints:
- 1 <= A.length == B.length == n <= 50
- 1 <= A[i], B[i] <= n
- It is guaranteed that A and B are both a permutation of n integers.
- A와 B는 n개의 정수 순열임이 보장됩니다.
 */

// @lc code=start
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        size_t n = A.size();
        set<int> seta;
        vector<int> result(n, 0);

        seta.insert(A[0]);
        if (seta.find(B[0]) != seta.end()) {
            result[0]++;
        } else {
            seta.insert(B[0]);
        }

        for (int i = 1; i < n; i++) {
            result[i] = result[i-1];
            if (seta.find(B[i]) != seta.end()) {
                result[i]++;
            } else {
                seta.insert(B[i]);
            }
            if (seta.find(A[i]) != seta.end()) {
                result[i]++;
            } else {
                seta.insert(A[i]);
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
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    vector<int> result = {0, 2, 3, 4};
	EXPECT_EQ(this->s.findThePrefixCommonArray(A, B), result);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> A = {2, 3, 1};
    vector<int> B = {3, 1, 2};
    vector<int> result = {0, 1, 3};
	EXPECT_EQ(this->s.findThePrefixCommonArray(A, B), result);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}