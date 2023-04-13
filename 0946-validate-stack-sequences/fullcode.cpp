#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <stack>
using namespace std;


/*
1 <= pushed.length <= 1000
0 <= pushed[i] <= 1000
All the elements of pushed are unique.
popped.length == pushed.length
popped is a permutation of pushed.
 */
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() == 1) {
			if (pushed[0] == popped[0]) return true;
			return false;
		}

		stack<int> st;
		st.push(pushed[0]);
		size_t i = 0, j = 1;

		while (i < popped.size()) {
			if (j >= pushed.size()) {
				return false;
			}

			if (st.empty()) {
				st.push(pushed[j]);
				j++;
			}

			while (st.top() != popped[i]) {
				if (j >= pushed.size()) {
					break;
				}
				st.push(pushed[j]);
				j++;
			}
			while (st.top() == popped[i]) {
				st.pop();
				i++;
				if (st.empty()) {
					break;
				}
			}
		}
		if (st.empty() == false) {
			return false;
		}
		return true;
	}
};
/*
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; // Create a stack

        int j = 0; // Intialise one pointer pointing on popped array

        for(auto val : pushed){
            st.push(val); // insert the values in stack
            while(st.size() > 0 && st.top() == popped[j]){ // if st.peek() values equal to popped[j];
                st.pop(); // then pop out
                j++; // increment j
            }
        }
        return st.size() == 0; // check if stack is empty return true else false
    }
*/


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
	vector<int> pushed = {1,2,3,4,5};
	vector<int> popped = {4,5,3,2,1};
	EXPECT_EQ(this->s.validateStackSequences(pushed, popped), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	vector<int> pushed = {1,2,3,4,5};
	vector<int> popped = {4,3,5,1,2};
	EXPECT_EQ(this->s.validateStackSequences(pushed, popped), false);
}

TEST_F(CLASS_NAME, __LINE__)
{
	vector<int> pushed = {0};
	vector<int> popped = {0};
	EXPECT_EQ(this->s.validateStackSequences(pushed, popped), true);
}


TEST_F(CLASS_NAME, __LINE__)
{
	vector<int> pushed = {2,1,0};
	vector<int> popped = {2,1,0};
	EXPECT_EQ(this->s.validateStackSequences(pushed, popped), true);
}

TEST_F(CLASS_NAME, __LINE__)
{
	vector<int> pushed = {2,1,3,0};
	vector<int> popped = {1,3,0,2};
	EXPECT_EQ(this->s.validateStackSequences(pushed, popped), true);

}
