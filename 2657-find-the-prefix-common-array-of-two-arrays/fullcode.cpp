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


/* https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 * 2657. Find the Prefix Common Array of Two Arrays | Medium

You are given two 0-indexed integer permutations A and B of length n.
A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.
Return the prefix common array of A and B.
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

길이가 n인 0-인덱스 정수 순열(permutation) A와 B가 주어집니다.
A와 B의 접두사 공통 배열(prefix common array)은 인덱스 i에서 또는 그 이전에 A와 B 양쪽 모두에 존재하는 숫자들의 개수가 C[i]와 같은 배열 C입니다.
A와 B의 접두사 공통 배열을 반환하세요.
n개의 정수 수열은 1부터 n까지의 모든 정수를 정확히 한 번씩 포함할 때 순열(permutation)이라고 불립니다.

 Constraints:
    * 1 <= A.length == B.length == n <= 50
    * 1 <= A[i], B[i] <= n
    * It is guaranteed that A and B are both a permutation of n integers.
 */

// @leet start
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n+1,-1);
        vector<int> C(n);

        int target;
        for (int i = 0 ; i < n; i++) {
            target = A[i];
            count[target] = i;
        }
        for (int i = 0; i < n; i++) {
            target = B[i];
            if (count[target] < i) {
                count[target] = i;
            }
        }

        int common = 0;
        for (int i = 0; i < n; i++) {
            if (count[A[i]] <= i) {
                common++;
            }
            if (A[i] != B[i] && count[B[i]] <= i) {
                common++;
            }
            C[i] = common;
        }

        return C;
        
    }

    vector<int> findThePrefixCommonArray2(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> count(n + 1, 0);
        vector<int> C(n);
        int common = 0;

        for (int i = 0; i < n; i++) {
            if (++count[A[i]] == 2) common++;  // A[i] 등장 → 2면 공통
            if (++count[B[i]] == 2) common++;  // B[i] 등장 → 2면 공통
            C[i] = common;
        }
        return C;
    }

};
// @leet end



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
    // 󰛨 Example 1:
    //     Input: A = [1,3,2,4], B = [3,1,2,4]
    //     Output: [0,2,3,4]
    //     Explanation: At i = 0: no number is common, so C[0] = 0.
    //     At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
    //     At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
    //     At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.

    //     설명: i = 0일 때: 공통된 숫자가 없으므로 C[0] = 0입니다.
    //     i = 1일 때: 1과 3이 A와 B에서 공통이므로 C[1] = 2입니다.
    //     i = 2일 때: 1, 2, 3이 A와 B에서 공통이므로 C[2] = 3입니다.
    //     i = 3일 때: 1, 2, 3, 4가 A와 B에서 공통이므로 C[3] = 4입니다.

    vector<int> A = {1,3,2,4};
    vector<int> B = {3,1,2,4};
    vector<int> expected = {0,2,3,4};
    EXPECT_EQ(this->s.findThePrefixCommonArray(A, B), expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // 󰛨 Example 2:
    //     Input: A = [2,3,1], B = [3,1,2]
    //     Output: [0,1,3]
    //     Explanation: At i = 0: no number is common, so C[0] = 0.
    //     At i = 1: only 3 is common in A and B, so C[1] = 1.
    //     At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.

    vector<int> A = {2,3,1};
    vector<int> B = {3,1,2};
    vector<int> expected = {0,1,3};
    EXPECT_EQ(this->s.findThePrefixCommonArray(A, B), expected);
}

// TEST_F(CLASS_NAME, __LINE__)
// {
//     vector<int> A = {1,3,5,4};
//     vector<int> B = {3,5,1,6};
//     vector<int> expected = {0,1,3,3};
//     EXPECT_EQ(this->s.findThePrefixCommonArray(A, B), expected);
// 
// }


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
