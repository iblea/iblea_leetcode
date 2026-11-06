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


/*

https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
1385 | Easy |  Find the Distance Value Between Two Arrays

Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.
The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.

󰛨 Example 1:
	│ Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
	│ Output: 2
	│ Explanation: 
	│ For arr1[0]=4 we have: 
	│ |4-10|=6 > d=2 
	│ |4-9|=5 > d=2 
	│ |4-1|=3 > d=2 
	│ |4-8|=4 > d=2 
	│ For arr1[1]=5 we have: 
	│ |5-10|=5 > d=2 
	│ |5-9|=4 > d=2 
	│ |5-1|=4 > d=2 
	│ |5-8|=3 > d=2
	│ For arr1[2]=8 we have:
	│ |8-10|=2 <= d=2
	│ |8-9|=1 <= d=2
	│ |8-1|=7 > d=2
	│ |8-8|=0 <= d=2

󰛨 Example 2:
	│ Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
	│ Output: 2
󰛨 Example 3:
	│ Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
	│ Output: 1

 Constraints:
	* 1 <= arr1.length, arr2.length <= 500
	* -1000 <= arr1[i], arr2[j] <= 1000
	* 0 <= d <= 100


두 정수 배열 arr1과 arr2, 그리고 정수 d가 주어지면 두 배열 사이의 거리 값을 반환합니다.
거리 값은 |arr1[i]-arr2[j]| <= d를 만족하는 원소 arr2[j]가 하나도 존재하지 않는 원소 arr1[i]의 개수로 정의됩니다.

󰛨 예제 1:
	│ 입력: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
	│ 출력: 2
	│ 설명:
	│ arr1[0]=4인 경우:
	│ |4-10|=6 > d=2
	│ |4-9|=5 > d=2
	│ |4-1|=3 > d=2
	│ |4-8|=4 > d=2
	│ arr1[1]=5인 경우:
	│ |5-10|=5 > d=2
	│ |5-9|=4 > d=2
	│ |5-1|=4 > d=2
	│ |5-8|=3 > d=2
	│ arr1[2]=8인 경우:
	│ |8-10|=2 <= d=2
	│ |8-9|=1 <= d=2
	│ |8-1|=7 > d=2
	│ |8-8|=0 <= d=2

󰛨 예제 2:
	│ 입력: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
	│ 출력: 2
󰛨 예제 3:
	│ 입력: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
	│ 출력: 1

 제약 조건:
	* 1 <= arr1.length, arr2.length <= 500
	* -1000 <= arr1[i], arr2[j] <= 1000
	* 0 <= d <= 100

 */

// @leet start
class Solution {
private:
    // 인덱스 반환
    int lowerBound(const vector<int>& arr, int target) {
        int lo = 0;
        int hi = arr.size();
        while (lo <hi) {
            int mi = lo + (hi - lo) / 2;
            if (arr[mi] >= target) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        // lowerbound: arr1[n] - d <= arr2[i] <= upperbound: arr1[n] + d

        int result = 0;
        for (int i = 0; i < arr1.size(); ++i) {
            int lower_idx = lowerBound(arr2, arr1[i] - d);
            if (lower_idx == arr2.size() || arr2[lower_idx] > arr1[i] + d) {
                result++;
            }
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
    vector<int> arr1 = {4,5,8};
    vector<int> arr2 = {10,9,1,8};
    int d = 2;
    EXPECT_EQ(this->s.findTheDistanceValue(arr1, arr2, d), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> arr1 = {1,4,2,3};
    vector<int> arr2 = {-4,-3,6,10,20,30};
    int d = 3;
    EXPECT_EQ(this->s.findTheDistanceValue(arr1, arr2, d), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> arr1 = {2,1,100,3};
    vector<int> arr2 = {-5,-2,10,-3,7};
    int d = 6;
    EXPECT_EQ(this->s.findTheDistanceValue(arr1, arr2, d), 1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
