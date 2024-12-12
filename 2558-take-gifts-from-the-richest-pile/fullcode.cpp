#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/take-gifts-from-the-richest-pile

You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation:
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.

Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation:
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile.
That is, you can't take any pile with you.
So, the total gifts remaining are 4.

여러 개의 선물 더미를 나타내는 정수 배열 gifts가 주어집니다. 매초마다 다음을 수행합니다.

최대 개수의 선물이 있는 더미를 선택합니다. 최대 개수의 선물이 있는 더미가 여러 개 있을 경우, 임의의 더미를 선택합니다. 선물의 개수의 제곱근을 내림한 값을 더미에 남겨둡니다. 나머지 선물은 가져갑니다. k초 후 남은 선물의 개수를 반환합니다.

입력: gifts = [25,64,9,4,100], k = 4 출력: 29 설명: 선물은 다음과 같은 방식으로 가져옵니다.

- 첫 번째 초에 마지막 더미가 선택되고 10개의 선물이 남겨집니다.
- 그런 다음 두 번째 더미가 선택되고 8개의 선물이 남겨집니다.
- 이후 첫 번째 더미가 선택되고 5개의 선물이 남겨집니다.
- 마지막으로 마지막 더미가 다시 선택되고 3개의 선물이 남겨집니다. 최종 남은 선물은 [5,8,9,4,3]이므로 남은 선물의 총 개수는 29입니다.

입력: gifts = [1,1,1,1], k = 4 출력: 4
설명: 이 경우, 어떤 더미를 선택하더라도 각 더미에 1개의 선물을 남겨야 합니다. 즉, 어떤 더미도 가져갈 수 없습니다. 따라서 남은 선물의 총 개수는 4입니다.



Constraints:
1 <= gifts.length <= 10**3
1 <= gifts[i] <= 10**9
1 <= k <= 10**3
 */

#include <queue>
#include <cmath>
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {

        priority_queue<int, vector<int>, less<void>> que;
        for (int i = 0; i < gifts.size(); i++) {
            que.push(gifts[i]);
        }

        for (int i = 0; i < k; i++) {
            int top = que.top();
            if (top == 1) {
                break;
            }
            // 제곱근 구해서 내림
            que.pop();
            double squareRoot = sqrt(top);
            int flooredSquareRoot = floor(squareRoot);
            que.push(flooredSquareRoot);
        }

        long long answer = 0;
        while (!que.empty()) {
            answer += que.top();
            que.pop();
        }
        return answer;
    }
};



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
    vector<int> gifts = {25,64,9,4,100};
	EXPECT_EQ(this->s.pickGifts(gifts, 4), 29);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<int> gifts = {1,1,1,1};
	EXPECT_EQ(this->s.pickGifts(gifts, 4), 4);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}