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

using namespace std;



/* https://leetcode.com/problems/design-a-number-container-system/?envType=daily-question&envId=2025-02-08
 * @lc app=leetcode id=2349 lang=cpp
 * [2349] Design a Number Container System


Design a number container system that can do the following:
Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:
NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.

다음과 같은 기능을 하는 숫자 컨테이너 시스템을 설계하세요:
시스템의 주어진 인덱스에 숫자를 삽입하거나 교체합니다.
시스템에서 주어진 숫자에 대한 가장 작은 인덱스를 반환합니다.
NumberContainers 클래스를 구현하세요:
NumberContainers() 숫자 컨테이너 시스템을 초기화합니다.
void change(int index, int number) 인덱스의 컨테이너에 숫자를 채웁니다. 해당 인덱스에 이미 숫자가 있는 경우 교체합니다.
int find(int number) 주어진 숫자에 대한 가장 작은 인덱스를 반환하거나, 시스템에 해당 숫자로 채워진 인덱스가 없는 경우 -1을 반환합니다.

Example 1:
Input
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
Output
[null, -1, null, null, null, null, 1, null, 2]

Explanation
NumberContainers nc = new NumberContainers();
nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
nc.change(2, 10); // Your container at index 2 will be filled with number 10.
nc.change(1, 10); // Your container at index 1 will be filled with number 10.
nc.change(3, 10); // Your container at index 3 will be filled with number 10.
nc.change(5, 10); // Your container at index 5 will be filled with number 10.
nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20.
nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.


Constraints:

1 <= index, number <= 10**9
At most 10**5 calls will be made in total to change and find.
 */

// @lc code=start

#define ERROR_INDEX 0
class NumberContainers {
private:
    map<int, vector<int>> m;
    map<int, int> index_to_number;

    void sorted_insert(vector<int> *v, int value) {
        auto it = lower_bound(v->begin(), v->end(), value);
        v->insert(it, value);
    }
    void sorted_erase(vector<int> *v, int value) {
        auto it = lower_bound(v->begin(), v->end(), value);
        if (it != v->end() && *it == value) {
            v->erase(it);
        }
    }
public:
    NumberContainers() {
        this->m = map<int, vector<int>>();
        this->index_to_number = map<int, int>();
    }

    void change(int index, int number) {
        int ago_value = ERROR_INDEX;
        if (this->index_to_number.find(index) != this->index_to_number.end()) {
            ago_value = this->index_to_number[index];
        }
        std::cout << ago_value << std::endl;
        this->index_to_number[index] = number;
        if (ago_value == ERROR_INDEX) {
            this->sorted_insert(&this->m[number], index);
        } else {
            this->sorted_erase(&this->m[ago_value], index);
            this->sorted_insert(&this->m[number], index);

        }
    }

    int find(int number) {
        if (this->m.find(number) == this->m.end()) {
            return -1;
        }
        if (this->m[number].size() == 0) {
            return -1;
        }
        return this->m[number][0];
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end




#define CLASS_NAME gtest_template

class CLASS_NAME: public ::testing::Test {
private:
	clock_t t0;
	clock_t t1;
public:
	NumberContainers s;
protected:
	CLASS_NAME() { this->s = NumberContainers(); }
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
    EXPECT_EQ(this->s.find(10), -1);
    this->s.change(2, 10);
    this->s.change(1, 10);
    this->s.change(3, 10);
    this->s.change(5, 10);
	EXPECT_EQ(this->s.find(10), 1);
    this->s.change(1, 20);
	EXPECT_EQ(this->s.find(10), 2);
}

TEST_F(CLASS_NAME, __LINE__)
{
    this->s.change(1, 10);
	EXPECT_EQ(this->s.find(10), 1);
    this->s.change(1, 20);
	EXPECT_EQ(this->s.find(10), -1);
    this->s.change(3, 10);
	EXPECT_EQ(this->s.find(20), 1);
	EXPECT_EQ(this->s.find(30), -1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}