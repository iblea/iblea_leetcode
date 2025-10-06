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


/* https://leetcode.com/problems/swim-in-rising-water/
 * @lc app=leetcode id=778 lang=cpp
 * [778] Swim in Rising Water

You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.
You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

n x n 정수 행렬 grid가 주어지며, 각 값 grid[i][j]는 해당 지점 (i, j)의 고도를 나타냅니다.
비가 내리기 시작하고, 시간이 지남에 따라 물이 점차 상승합니다. 시간 t에서 수위는 t이며, 이는 고도가 t 이하인 모든 셀이 물에 잠기거나 도달 가능함을 의미합니다.
두 사각형의 고도가 모두 최대 t 이하인 경우에만 한 사각형에서 4방향으로 인접한 다른 사각형으로 수영할 수 있습니다. 0의 시간에 무한한 거리를 수영할 수 있습니다. 물론, 수영하는 동안 grid의 경계 내에 머물러야 합니다.
왼쪽 상단 사각형 (0, 0)에서 시작하여 오른쪽 하단 사각형 (n - 1, n - 1)에 도달할 수 있는 최소 시간을 반환합니다.

Example 1:
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

시간 0에서, 당신은 격자 위치 (0, 0)에 있습니다.
4방향으로 인접한 이웃들이 t = 0보다 높은 고도를 가지고 있기 때문에 다른 곳으로 갈 수 없습니다.
시간 3이 될 때까지 점 (1, 1)에 도달할 수 없습니다.
물의 깊이가 3일 때, 우리는 격자 내부의 어느 곳이든 수영할 수 있습니다.

Example 2:
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

시간 16까지 기다려야 (0, 0)과 (4, 4)가 연결됩니다.

Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.
 */

// @lc code=start
class Solution {
private:
    pair<int, int> directions[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int x = grid[0].size();
        int y = grid.size();
        const int targetX = x - 1;
        const int targetY = y - 1;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap; // {height, x, y}
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int ans = 0;

        while (!minHeap.empty()) {
            auto [height, curX, curY] = minHeap.top();
            minHeap.pop();
            ans = max(ans, height);
            if (curX == targetX && curY == targetY) break;

            for (auto& dir : directions) {
                int nextX = curX + dir.first;
                int nextY = curY + dir.second;
                if (nextX < 0 || nextX >= x || nextY < 0 || nextY >= y) continue;
                if (visited[nextY][nextX]) continue;
                visited[nextY][nextX] = true;
                minHeap.push({grid[nextY][nextX], nextX, nextY});
            }
        }

        return ans;
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
    vector<vector<int>> grid = {
        {0,2},
        {1,3}
    };
    EXPECT_EQ(this->s.swimInWater(grid), 3);
}

TEST_F(CLASS_NAME, __LINE__)
{
    vector<vector<int>> grid = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };
    EXPECT_EQ(this->s.swimInWater(grid), 16);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


/*
Swim in Rising Water - 문제 접근법 가이드

📌 문제를 다시 이해해보자

먼저 문제 상황을 머릿속으로 그려보자:
- n×n 그리드가 있고, 각 칸마다 높이(elevation)가 있어
- 시간 t가 흐르면 물의 높이도 t가 돼
- 물의 높이보다 낮거나 같은 칸으로만 이동할 수 있어
- (0,0)에서 시작해서 (n-1, n-1)까지 가는 최소 시간을 찾는 게 목표야

핵심은 뭘까? "언제부터 길이 열릴까?" 를 찾는 거야!

---
🎯 핵심 인사이트 3가지

1️⃣ 이건 "최단 경로" 문제가 아니야!

일반적인 최단 경로는 "몇 칸을 거쳐갈까?"를 찾지만, 이 문제는 **"언제 도착할 수 있을까?"**를 찾는 거야. 시간이 지나면서 경로가 점점 열리는 상황이지.

2️⃣ 병목 지점(Bottleneck)이 답이야

경로 상에서 가장 높은 지점이 전체 경로의 시간을 결정해. 예를 들어:
- 경로: 1 → 2 → 5 → 3
- 이 경로로 가려면 시간 5가 되어야 해 (5가 가장 높으니까)

3️⃣ 그래프 탐색 + 최적화 문제의 조합

이 문제는 두 가지 관점으로 볼 수 있어:
- 그래프 관점: (0,0)에서 (n-1,n-1)까지의 경로 찾기
- 최적화 관점: 모든 가능한 경로 중 병목이 최소인 경로 찾기

---
🔧 주요 접근법 3가지

📍 방법 1: Dijkstra's Algorithm + Priority Queue (가장 직관적!)

핵심 아이디어:
- "현재까지 경험한 최대 높이"를 최소화하면서 목표까지 가자!
- 항상 가장 낮은 높이로 갈 수 있는 칸부터 방문해

어떻게 동작하나?
1. Priority Queue(최소 힙)를 준비해
2. 시작점 (0,0)을 큐에 넣어 (높이: grid[0][0])
3. 큐에서 가장 낮은 높이의 칸을 꺼내
4. 그 칸의 인접한 칸들을 확인해:
   - 방문 안 했으면 큐에 추가
   - 지금까지의 최대 높이와 새 칸의 높이 중 큰 값을 저장
5. 목표 지점 (n-1,n-1)에 도착하면 끝!

왜 이게 동작할까?
- 항상 "지금까지 경험한 최대 높이"가 가장 작은 경로를 우선 탐색해
- Greedy하게 선택하지만, Priority Queue 덕분에 최적해를 보장해

시간 복잡도: O(n² log n)

---
📍 방법 2: Binary Search + DFS/BFS

핵심 아이디어:
- "시간 t에 목표까지 갈 수 있나?"를 Yes/No로 판단
- 이진 탐색으로 "가능한 최소 시간"을 찾자!

어떻게 동작하나?
1. 가능한 시간 범위 설정: left = grid[0][0], right = n²-1
2. 중간값 mid를 선택
3. "시간 mid에 도달 가능한가?" 체크 (DFS/BFS 사용)
   - grid[i][j] ≤ mid인 칸만 지나갈 수 있다고 가정
   - (0,0)에서 (n-1,n-1)까지 갈 수 있나?
4. 가능하면 right = mid (더 작은 시간도 시도)
   불가능하면 left = mid + 1 (더 큰 시간 필요)
5. left == right가 될 때까지 반복

왜 이게 동작할까?
- 단조성(Monotonicity): 시간 t에 갈 수 있으면, t+1에도 갈 수 있지
- 이진 탐색으로 "가능한 최소값"을 효율적으로 찾을 수 있어

시간 복잡도: O(n² log n)

---
📍 방법 3: Union-Find

핵심 아이디어:
- 시간이 흐르면서 칸들이 하나씩 "활성화"돼
- 시작점과 끝점이 같은 그룹에 속하는 순간이 답!

어떻게 동작하나?
1. 모든 칸을 높이 순서로 정렬
2. 낮은 높이부터 하나씩 처리:
   - 그 칸을 "활성화"
   - 인접한 활성화된 칸들과 Union (그룹 합치기)
   - 시작점(0,0)과 끝점(n-1,n-1)이 연결됐나? → 답!

시간 복잡도: O(n² log n)

---
🤔 어떤 방법을 선택해야 할까?

초보자라면:
- Dijkstra + Priority Queue 추천! 가장 직관적이고 이해하기 쉬워

이미 이진 탐색에 익숙하다면:
- Binary Search + DFS 시도해봐. 패턴 인식 능력이 향상돼

알고리즘 최적화에 관심 있다면:
- Union-Find 도전해봐. 효율적이지만 약간 트리키해

---
💡 핵심 자료구조 & 개념

1. Priority Queue (Min-Heap)

- 항상 최소값을 O(log n)에 꺼낼 수 있어
- C++: priority_queue (기본은 max-heap이니 주의!)

2. Visited 배열

- bool[n][n] 형태
- 같은 칸을 여러 번 방문하지 않도록

3. 방향 벡터

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

---
🎓 문제 풀이 사고 과정

1. "이게 무슨 종류의 문제지?"
  - 그래프 탐색 + 최적화 문제
2. "어떤 알고리즘이 적합할까?"
  - 최단 경로 변형 → Dijkstra 떠올리기
  - 이진 탐색 가능성 체크 (단조성 있나?)
3. "시간/공간 복잡도는?"
  - n ≤ 50이면 O(n² log n)도 충분해
4. "엣지 케이스는?"
  - n = 1일 때? (바로 도착)
  - 시작점 높이가 이미 높을 때?

---
📚 참고 자료

1. LeetCode Official Solution - Union-Find와 Dijkstra 방법 설명
2. GeeksforGeeks - Binary Search + DFS 접근법
3. DEV Community - 단계별 구현 가이드

---
✨ 마무리 조언

이 문제는 **"전형적인 Dijkstra를 살짝 변형"**한 거야. 핵심은:

1. 거리가 아니라 "최대 높이"를 추적한다는 점
2. 경로 상의 병목(bottleneck)을 최소화하는 게 목표
3. Priority Queue로 항상 최소 높이부터 탐색

먼저 Dijkstra 방법으로 구현해보고, 잘 이해했다면 다른 방법들도 시도해봐! 각 접근법의 장단점을 비교하면서 알고리즘 사고력이 더 성장할 거야 💪
*/