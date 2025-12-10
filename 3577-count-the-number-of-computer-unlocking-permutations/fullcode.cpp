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



/* https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations
 * @lc app=leetcode id=3577 lang=cpp
 * [3577] Count the Number of Computer Unlocking Permutations

You are given an array complexity of length n.
There are n locked computers in a room with labels from 0 to n - 1, each with its own unique password. The password of the computer i has a complexity complexity[i].
The password for the computer labeled 0 is already decrypted and serves as the root. All other computers must be unlocked using it or another previously unlocked computer, following this information:

- You can decrypt the password for the computer i using the password for computer j, where j is any integer less than i with a lower complexity. (i.e. j < i and complexity[j] < complexity[i])
- To decrypt the password for computer i, you must have already unlocked a computer j such that j < i and complexity[j] < complexity[i].

Find the number of permutations of [0, 1, 2, ..., (n - 1)] that represent a valid order in which the computers can be unlocked, starting from computer 0 as the only initially unlocked one.
Since the answer may be large, return it modulo (10**9) + 7.
Note that the password for the computer with label 0 is decrypted, and not the computer with the first position in the permutation.

길이가 n인 배열 complexity가 주어집니다.
방에는 0부터 n - 1까지 레이블이 붙은 n개의 잠긴 컴퓨터가 있으며, 각각 고유한 비밀번호를 가지고 있습니다. 컴퓨터 i의 비밀번호는 복잡도 complexity[i]를 가집니다.
레이블이 0인 컴퓨터의 비밀번호는 이미 해독되어 있으며 루트 역할을 합니다. 다른 모든 컴퓨터는 이 컴퓨터 또는 이전에 잠금 해제된 다른 컴퓨터를 사용하여 다음 정보에 따라 잠금 해제되어야 합니다:

- 더 낮은 복잡도를 가진 i보다 작은 정수 j인 컴퓨터 j의 비밀번호를 사용하여 컴퓨터 i의 비밀번호를 해독할 수 있습니다. (즉, j < i이고 complexity[j] < complexity[i])
- 컴퓨터 i의 비밀번호를 해독하려면 j < i이고 complexity[j] < complexity[i]인 컴퓨터 j의 잠금을 이미 해제했어야 합니다.

컴퓨터 0만 초기에 잠금 해제된 상태에서 시작하여 컴퓨터를 잠금 해제할 수 있는 유효한 순서를 나타내는 [0, 1, 2, ..., (n - 1)]의 순열 개수를 구하세요.
답이 클 수 있으므로 (10**9) + 7로 나눈 나머지를 반환하세요.
레이블이 0인 컴퓨터의 비밀번호가 해독되는 것이지, 순열의 첫 번째 위치에 있는 컴퓨터가 해독되는 것이 아님에 유의하세요.

Constraints:
2 <= complexity.length <= (1e5)
1 <= complexity[i] <= (1e9)
*/
// @lc code=start
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        const int MOD = 1e9 + 7;

        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        long long result = 1;
        for (int i = 2; i < n; i++) {
            result = (result * i) % MOD;
        }
        return (int)result;
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
    // Input: complexity = [1,2,3]
    // Output: 2
    // Explanation:
    // The valid permutations are:
    // [0, 1, 2]
    // Unlock computer 0 first with root password.
    // Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].
    // Unlock computer 2 with password of computer 1 since complexity[1] < complexity[2].
    // [0, 2, 1]
    // Unlock computer 0 first with root password.
    // Unlock computer 2 with password of computer 0 since complexity[0] < complexity[2].
    // Unlock computer 1 with password of computer 0 since complexity[0] < complexity[1].

    vector<int> complexity = {1,2,3};
    EXPECT_EQ(this->s.countPermutations(complexity), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: complexity = [3,3,3,4,4,4]
    // Output: 0
    // Explanation:
    // There are no possible permutations which can unlock all computers.

    vector<int> complexity = {3,3,3,4,4,4};
    EXPECT_EQ(this->s.countPermutations(complexity), 0);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
