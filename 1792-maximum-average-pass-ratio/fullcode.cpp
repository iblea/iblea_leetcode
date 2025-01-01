#include <gtest/gtest.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;


/*
https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15
1792. Maximum Average Pass Ratio

There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.
The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

학생들이 있는 학교가 있으며 각 반은 기말 시험을 치르게 됩니다. 2D 정수 배열 classes가 주어지며, 여기서 classes[i] = [passi, totali]입니다. 당신은 i번째 반에 totali명의 총 학생이 있지만, 오직 passi명의 학생만이 시험에 합격할 것임을 미리 알고 있습니다.
또한 정수 extraStudents가 주어집니다. extraStudents명의 뛰어난 학생들이 추가로 있으며, 이들은 할당된 어떤 반에서도 시험에 합격할 것이 보장됩니다. 당신은 모든 반의 평균 합격 비율을 최대화하는 방식으로 각 extraStudents 학생을 반에 할당하고자 합니다.
반의 합격 비율은 그 반의 시험에 합격할 학생 수를 그 반의 총 학생 수로 나눈 값입니다. 평균 합격 비율은 모든 반의 합격 비율의 합을 반의 수로 나눈 값입니다.
extraStudents 학생들을 할당한 후 가능한 최대 평균 합격 비율을 반환하세요. 실제 답변의 10-5 이내의 답변은 허용됩니다.


Example 1:
Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
Output: 0.78333
Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.

Example 2:
Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
Output: 0.53485

2/4, 3/9, 4/5, 2/10 = 0.5 + 0.33333 + 0.8 + 0.2 = 1.83333 / 4 = 0.45833

3/5, 3/9, 4/5, 2/10 = 0.6 + 0.33333 + 0.8 + 0.2 = 1.93333 / 4 = 0.48333

0.06, 0.06666, 0.03333, 0.07272..

3/5, 3/9, 4/5, 3/11 = 0.6 + 0.33333 + 0.8 + 0.27272 = 2.00605 / 4 = 0.5015125

0.333333
0.272727
0.06


Constraints:
1 <= classes.length <= 10**5
classes[i].length == 2
1 <= passi <= totali <= 10**5
1 <= extraStudents <= 10**5

합격비가 제일 낮은 반에다가 학생을 투입해야 하는 것인가?
 */

struct ClassInfo {
    int pass;
    int total;
    double agoRatio;
    double newRatio;
    double diffRatio;

    bool operator<(const ClassInfo& other) const {
        return diffRatio < other.diffRatio;
    }
    bool operator>(const ClassInfo& other) const {
        return diffRatio > other.diffRatio;
    }
};

struct cmp {
    // priority queue 를통해 가장 큰 값을 우선으로 리턴하도록 하기 위해
    bool operator()(const ClassInfo& a, const ClassInfo& b) const {
        return a.diffRatio < b.diffRatio;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        int pass = 0;
        int total = 0;
        double agoRatio = 0;
        double newRatio = 0;
        double diffRatio = 0;

        // diff ratio 기준으로 가장 큰 값부터 리턴하는 우선순위 큐
        // priority_queue<ClassInfo, vector<ClassInfo>, cmp> pq;
        priority_queue<ClassInfo> pq;
        for (auto& c : classes) {
            pass = c[0];
            total = c[1];
            agoRatio = (double)(pass) / (double)(total);
            newRatio = (double)(pass + 1) / (double)(total + 1);
            diffRatio = newRatio - agoRatio;
            pq.push({pass, total, agoRatio, newRatio, diffRatio});
        }

        for (int i = 0; i < extraStudents; i++) {
            ClassInfo c = pq.top();
            pq.pop();
            pass = c.pass + 1;
            total = c.total + 1;
            agoRatio = c.newRatio;
            newRatio = (double)(pass + 1) / (double)(total + 1);
            diffRatio = newRatio - agoRatio;
            pq.push({pass, total, agoRatio, newRatio, diffRatio});
        }

        double sumRatio = 0;
        while (!pq.empty()) {
            ClassInfo c = pq.top();
            pq.pop();
            sumRatio += c.agoRatio;
        }
        return sumRatio / classes.size();
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
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;
    double result = this->s.maxAverageRatio(classes, extraStudents);
    cout << result << endl;
	EXPECT_DOUBLE_EQ(result, 0.78333);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> classes = {{2,4},{3,9},{4,5},{2,10}};
    // 2,4 (0.5) -> 3,5(0.6)
    // 3,9 (0.33333) -> 4,10(0.4)
    // 4,5 (0.8) -> 5,6(0.83333)
    // 2,10 (0.2) -> 3,11(0.27272)
    int extraStudents = 4;
    double result = this->s.maxAverageRatio(classes, extraStudents);
    cout << result << endl;
	EXPECT_DOUBLE_EQ(result, 0.53485);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}