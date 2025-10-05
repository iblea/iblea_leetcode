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



/* https://leetcode.com/problems/pacific-atlantic-water-flow/
 * @lc app=leetcode id=417 lang=cpp
 * [417] Pacific Atlantic Water Flow

There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

태평양과 대서양 모두에 접해 있는 m x n 크기의 직사각형 섬이 있습니다. 태평양은 섬의 왼쪽과 위쪽 가장자리에 접해 있으며, 대서양은 섬의 오른쪽과 아래쪽 가장자리에 접해 있습니다.
섬은 정사각형 셀들의 격자로 분할되어 있습니다. m x n 크기의 정수 행렬 heights가 주어지며, heights[r][c]는 좌표 (r, c)에 있는 셀의 해수면 위 높이를 나타냅니다.
섬에는 많은 비가 내리며, 빗물은 이웃한 셀의 높이가 현재 셀의 높이보다 작거나 같을 경우 북쪽, 남쪽, 동쪽, 서쪽으로 직접 이웃한 셀로 흐를 수 있습니다. 물은 해양에 인접한 모든 셀에서 해양으로 흐를 수 있습니다.
빗물이 셀 (ri, ci)에서 태평양과 대서양 모두로 흐를 수 있음을 나타내는 격자 좌표의 2차원 리스트 result를 반환하십시오. 여기서 result[i] = [ri, ci]입니다.


Example 1:
Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:
Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

Constraints:

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 10**5

*/

// @lc code=start
class Solution {
private:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0, 1}, {0,-1}};

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& heights, vector<vector<bool>>& reachable) {
        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
        int m = heights.size();
        int n = heights[0].size();

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (visited[x][y]) continue;
            visited[x][y] = true;

            for (const auto& dir : directions) {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    !reachable[newX][newY] && heights[newX][newY] >= heights[x][y]) {
                    reachable[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int x = heights[0].size();
        int y = heights.size();

        vector<vector<bool>> pacific_reachable(y, vector<bool>(x, false));
        vector<vector<bool>> atlantic_reachable(y, vector<bool>(x, false));
        vector<vector<int>> result;

        queue<pair<int, int>> pacific_queue;
        queue<pair<int, int>> atlantic_queue;

        for (int i = 0; i < y; ++i) {
            pacific_queue.push({i, 0});
            atlantic_queue.push({i, x - 1});
            pacific_reachable[i][0] = true;
            atlantic_reachable[i][x - 1] = true;
        }

        for (int j = 0; j < x; ++j) {
            pacific_queue.push({0, j});
            atlantic_queue.push({y - 1, j});
            pacific_reachable[0][j] = true;
            atlantic_reachable[y - 1][j] = true;
        }

        bfs(pacific_queue, heights, pacific_reachable);
        bfs(atlantic_queue, heights, atlantic_reachable);

        for (int i = 0; i < y; ++i) {
            for (int j = 0; j < x; ++j) {
                if (pacific_reachable[i][j] && atlantic_reachable[i][j]) {
                    result.push_back({i, j});
                }
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
    vector<vector<int>> heights = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    vector<vector<int>> expected = {
        {0,4},{1,3},{1,4},{2,2},{3,0},{3,1},{4,0}
    };
    vector<vector<int>> result = s.pacificAtlantic(heights);
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());
    EXPECT_EQ(result, expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> heights = {
        {1}
    };
    vector<vector<int>> expected = {
        {0,0}
    };
    vector<vector<int>> result = s.pacificAtlantic(heights);
    sort(result.begin(), result.end());
    sort(expected.begin(), expected.end());
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/*
LeetCode 417: Pacific Atlantic Water Flow - 문제 접근 방법

🎯 문제 이해하기

문제가 뭐냐면

m x n 크기의 격자(grid)가 있고, 각 칸에는 높이 값이 적혀있어. 물은 현재 칸에서 인접한 칸(상하좌우)으로 흘러갈 수 있는데, 같거나 낮은 높이의 칸으로만 흐를 수 있어.

- 태평양(Pacific): 격자의 왼쪽 끝과 위쪽 끝에 닿아있음
- 대서양(Atlantic): 격자의 오른쪽 끝과 아래쪽 끝에 닿아있음

너가 찾아야 하는 건: 양쪽 바다 모두에 물을 흘려보낼 수 있는 칸들이야.

왜 이 문제가 어려운가?

1. 직관적 접근의 함정: "각 칸에서 시작해서 두 바다에 다 도달하는지 확인하자!"라고 생각하면... 시간복잡도가 엄청나게 커져 버려.
2. 방향성 혼란: 물이 흐르는 방향이랑 우리가 탐색해야 하는 방향이 반대라는 게 핵심이야.

---
💡 핵심 인사이트 (Key Insights)

1. 사고의 전환: 거꾸로 생각하기

보통 물이 높은 곳 → 낮은 곳으로 흐른다고 생각하잖아? 근데 이 문제는 거꾸로 생각해야 해!

🔑 핵심 아이디어:
"각 칸에서 바다로 갈 수 있나?"가 아니라"바다에서 거슬러 올라가서 도달할 수 있는 칸들은 어디인가?"

왜냐면:
- 만약 어떤 칸 A에서 태평양으로 물이 흐를 수 있다면
- 반대로 태평양에서 시작해서 A까지 거슬러 올라갈 수 있어 (같거나 높은 곳으로!)

2. 왜 이 접근이 효율적인가?

- 각 칸마다 탐색하면: O(m × n × m × n) → 너무 느림!
- 바다에서 시작하면: O(m × n) → 각 칸을 최대 2번만 방문! (태평양에서 1번, 대서양에서 1번)

---
🧭 문제 해결 전략

전체 접근 방식

1. 태평양에서 도달 가능한 모든 칸 찾기 (DFS/BFS 사용)
2. 대서양에서 도달 가능한 모든 칸 찾기 (DFS/BFS 사용)
3. 두 집합의 교집합 = 정답!

구체적인 단계

Step 1: 초기화

- 두 개의 boolean 배열(또는 set) 만들기
  - pacific_reachable: 태평양에서 도달 가능한 칸들
  - atlantic_reachable: 대서양에서 도달 가능한 칸들

Step 2: 태평양에서 탐색 시작

시작 지점:
- 맨 윗줄 전체 (첫 번째 행)
- 맨 왼쪽 열 전체 (첫 번째 열)

탐색 조건:
- 현재 칸의 높이 ≤ 다음 칸의 높이 (거슬러 올라가니까!)
- 아직 방문 안 한 칸만

Step 3: 대서양에서 탐색 시작

시작 지점:
- 맨 아랫줄 전체 (마지막 행)
- 맨 오른쪽 열 전체 (마지막 열)

탐색 조건: Step 2와 동일

Step 4: 교집합 찾기

두 배열에서 모두 true인 칸들이 정답!

---
🔍 알고리즘 선택: DFS vs BFS?

DFS (깊이 우선 탐색)

- 장점: 구현이 간단함 (재귀로 쉽게 구현 가능)
- 단점: 스택 오버플로우 가능성 (매우 큰 격자에서)

BFS (너비 우선 탐색)

- 장점: 스택 오버플로우 걱정 없음
- 단점: 큐를 명시적으로 관리해야 함

둘 다 괜찮아! 시간복잡도는 똑같으니까 네가 편한 걸로 선택하면 돼.

---
⏱️ 복잡도 분석

시간 복잡도: O(m × n)

- 각 칸을 최대 2번 방문 (태평양 탐색 1번 + 대서양 탐색 1번)
- m × n 칸이니까 전체적으로 O(m × n)

공간 복잡도: O(m × n)

- pacific_reachable 배열: O(m × n)
- atlantic_reachable 배열: O(m × n)
- DFS의 경우 재귀 스택: 최악의 경우 O(m × n)
- 총합: O(m × n)

---
🚨 흔한 실수들 (Common Pitfalls)

1. 탐색 방향 헷갈리기

❌ 잘못된 생각: "높이가 낮은 쪽으로 가야지!"
✅ 올바른 생각: "바다에서 시작하니까 높이가 같거나 높은 쪽으로!"

2. 경계 조건 실수

- 배열 인덱스 범위 체크 안 하면 → IndexError!
- 특히 4방향 탐색할 때 조심해야 해

3. 중복 방문 체크 안 하기

- 방문 체크 안 하면 → 무한 루프 또는 시간 초과!
- 반드시 visited 체크해야 해

4. 초기화 실수

❌ 잘못: 하나의 visited 배열로 두 바다 탐색
✅ 올바름: 태평양용, 대서양용 따로 따로!

5. 각 칸에서 시작하는 brute force 접근

❌ 시간복잡도: O((m×n)²) → 시간 초과!
✅ 바다에서 시작: O(m×n) → 통과!

---
🎓 학습 포인트 정리

핵심 개념

1. 역방향 탐색(Reverse Thinking): 문제를 거꾸로 생각하면 훨씬 쉬워질 수 있어
2. 그래프 탐색: 2D 격자를 그래프로 보는 관점
3. 집합의 교집합: 두 조건을 모두 만족하는 원소 찾기

이 문제에서 배울 수 있는 것

- 최적화 사고: 같은 문제를 다르게 접근하면 시간복잡도가 확 줄어들 수 있어
- DFS/BFS 활용: 단순 탐색이 아니라 조건부 탐색에도 활용 가능
- 문제 변환: "A에서 B로 갈 수 있나?" ↔ "B에서 A로 거슬러 올라갈 수 있나?"

---
📚 참고 자료 (Sources)

1. LeetCode 공식 문제 페이지https://leetcode.com/problems/pacific-atlantic-water-flow/
2. AlgoMonster - 상세 설명https://algo.monster/liteproblems/417
3. SparkCodeHub - 단계별 가이드https://www.sparkcodehub.com/leetcode/417/pacific-atlantic-water-flow

---
💪 네가 직접 해볼 것

이제 이해했으면:
1. 먼저 손으로 작은 예제 그려보면서 태평양/대서양에서 거슬러 올라가는 과정 시뮬레이션해봐
2. DFS 또는 BFS 중 하나 선택해서 pseudocode(의사코드)부터 작성해봐
3. 경계 조건, 방문 체크를 꼼꼼히 신경 쓰면서 구현해봐

핵심은 "거꾸로 생각하기"야! 이게 이 문제의 가장 중요한 인사이트니까 이것만 확실히 이해하면 나머지는 표준적인 DFS/BFS 구현이야.

*/