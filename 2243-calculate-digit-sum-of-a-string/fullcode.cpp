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


/* https://leetcode.com/problems/calculate-digit-sum-of-a-string/
                                                          
2243 | Easy | Calculate Digit Sum of a String

You are given a string s consisting of digits and an integer k.
A round can be completed if the length of s is greater than k. In one round, do the following:
	1. Divide s into consecutive groups of size k such that the first k characters are in the first group, the next k characters are in the second group, and so on. Note that the size of the last group can be smaller than k.
	2. Replace each group of s with a string representing the sum of all its digits. For example, "346" is replaced with "13" because 3 + 4 + 6 = 13.
	3. Merge consecutive groups together to form a new string. If the length of the string is greater than k, repeat from step 1.
Return s after all rounds have been completed.

󰛨 Example 1:
	Input: s = "11111222223", k = 3
	Output: "135"
	Explanation: 
	- For the first round, we divide s into groups of size 3: "111", "112", "222", and "23".
	  Then we calculate the digit sum of each group: 1 + 1 + 1 = 3, 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, and 2 + 3 = 5. 
	  So, s becomes "3" + "4" + "6" + "5" = "3465" after the first round.
	- For the second round, we divide s into "346" and "5".
	  Then we calculate the digit sum of each group: 3 + 4 + 6 = 13, 5 = 5. 
	  So, s becomes "13" + "5" = "135" after second round. 
	Now, s.length <= k, so we return "135" as the answer.

󰛨 Example 2:
	Input: s = "00000000", k = 3
	Output: "000"
	Explanation: 
	We divide s into "000", "000", and "00".
	Then we calculate the digit sum of each group: 0 + 0 + 0 = 0, 0 + 0 + 0 = 0, and 0 + 0 = 0. 
	s becomes "0" + "0" + "0" = "000", whose length is equal to k, so we return "000".

 Constraints:
	* 1 <= s.length <= 100
	* 2 <= k <= 100
	* s consists of digits only.


숫자로 구성된 문자열 s와 정수 k가 주어집니다.
s의 길이가 k보다 크면 한 라운드를 진행할 수 있습니다. 한 라운드에서는 다음을 수행합니다:
	1. 처음 k개의 문자는 첫 번째 그룹에, 그다음 k개의 문자는 두 번째 그룹에 속하는 식으로 s를 크기 k의 연속된 그룹들로 나눕니다. 마지막 그룹의 크기는 k보다 작을 수 있다는 점에 유의하십시오.
	2. s의 각 그룹을 해당 그룹의 모든 숫자의 합을 나타내는 문자열로 바꿉니다. 예를 들어, 3 + 4 + 6 = 13이므로 "346"은 "13"으로 바뀝니다.
	3. 연속된 그룹들을 합쳐 새로운 문자열을 만듭니다. 이 문자열의 길이가 k보다 크면 1단계부터 반복합니다.
모든 라운드를 마친 후의 s를 반환하십시오.

󰛨 예제 1:
	입력: s = "11111222223", k = 3
	출력: "135"
	설명: 
	- 첫 번째 라운드에서는 s를 크기 3의 그룹들로 나눕니다: "111", "112", "222", "23".
	  그다음 각 그룹의 숫자 합을 계산합니다: 1 + 1 + 1 = 3, 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, 2 + 3 = 5. 
	  따라서 첫 번째 라운드가 끝나면 s는 "3" + "4" + "6" + "5" = "3465"가 됩니다.
	- 두 번째 라운드에서는 s를 "346"과 "5"로 나눕니다.
	  그다음 각 그룹의 숫자 합을 계산합니다: 3 + 4 + 6 = 13, 5 = 5. 
	  따라서 두 번째 라운드가 끝나면 s는 "13" + "5" = "135"가 됩니다. 
	이제 s.length <= k이므로 "135"를 답으로 반환합니다.

󰛨 예제 2:
	입력: s = "00000000", k = 3
	출력: "000"
	설명: 
	s를 "000", "000", "00"으로 나눕니다.
	그다음 각 그룹의 숫자 합을 계산합니다: 0 + 0 + 0 = 0, 0 + 0 + 0 = 0, 0 + 0 = 0. 
	s는 "0" + "0" + "0" = "000"이 되고, 그 길이가 k와 같으므로 "000"을 반환합니다.

 제약 조건:
	* 1 <= s.length <= 100
	* 2 <= k <= 100
	* s는 숫자로만 구성됩니다.
 */

// @leet start
class Solution {
public:
    string digitSum(string s, int k) {
        string result = s;

        while (result.length() > k) {
            string newResult = "";
            for (int i = 0; i < result.length(); i += k) {
                int sum = 0;
                int end = min(i + k, (int)result.length());
                for (int j = i; j < end; ++j) {
                    sum += result[j] - '0';
                }
                newResult += to_string(sum);
            }
            result = newResult;
        }
        
        return result;
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
    EXPECT_EQ(this->s.digitSum("11111222223", 3), "135");
}

TEST_F(CLASS_NAME, __LINE__)
{
    EXPECT_EQ(this->s.digitSum("00000000", 3), "000");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
