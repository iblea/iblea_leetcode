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



/* https://leetcode.com/problems/most-profitable-path-in-a-tree/?envType=daily-question&envId=2025-02-24
 * @lc app=leetcode id=2467 lang=cpp
 * [2467] Most Profitable Path in a Tree

There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:

the price needed to open the gate at node i, if amount[i] is negative, or,
the cash reward obtained on opening the gate at node i, otherwise.
The game goes on as follows:

Initially, Alice is at node 0 and Bob is at node bob.
At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
If the gate is already open, no price will be required, nor will there be any cash reward.
If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
Return the maximum net income Alice can have if she travels towards the optimal leaf node.

0번 노드를 루트로 하는 n개의 노드로 구성된 무방향 트리가 있습니다. 노드들은 0부터 n-1까지 번호가 매겨져 있습니다. edges[i] = [ai, bi]로 표현되는 길이 n-1의 2차원 정수 배열 edges가 주어지며, 이는 트리에서 노드 ai와 bi 사이에 간선이 있음을 나타냅니다.
각 노드 i에는 게이트가 있습니다. 짝수 정수로 구성된 배열 amount도 주어지며, amount[i]는 다음을 나타냅니다:

amount[i]가 음수인 경우, 노드 i의 게이트를 여는 데 필요한 비용
그 외의 경우, 노드 i의 게이트를 열 때 얻는 현금 보상
게임은 다음과 같이 진행됩니다:

처음에 Alice는 노드 0에 있고 Bob은 노드 bob에 있습니다.
매 초마다 Alice와 Bob은 각각 인접한 노드로 이동합니다. Alice는 어떤 리프 노드를 향해 이동하고, Bob은 노드 0을 향해 이동합니다.
경로상의 각 노드에서 Alice와 Bob은 해당 노드의 게이트를 열기 위해 돈을 지불하거나 보상을 받습니다. 다음 사항에 주의하세요:
게이트가 이미 열려있다면, 비용이 들지 않고 보상도 없습니다.
Alice와 Bob이 동시에 노드에 도착하면, 게이트를 여는 비용/보상을 공유합니다. 즉, 게이트를 여는 비용이 c라면 Alice와 Bob은 각각 c/2를 지불합니다. 마찬가지로 게이트의 보상이 c라면 각각 c/2를 받습니다.
Alice가 리프 노드에 도달하면 이동을 멈춥니다. 마찬가지로 Bob이 노드 0에 도달하면 이동을 멈춥니다. 이 두 사건은 서로 독립적입니다.
Alice가 최적의 리프 노드로 이동할 때 얻을 수 있는 최대 순수입을 반환하세요.

Constraints:
2 <= n <= 10**5
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
1 <= bob < n
amount.length == n
amount[i] is an even integer in the range [-10**4, 10**4].
 */

// @lc code=start
class Solution {
private:
    int n;
    vector<vector<int>> edges;
    int bob;
    vector<int> amount;
    vector<int> bob_path;

    bool bob_dfs(int node, int parent, vector<bool>* visited, int time = 0) {
        // 0번 노드에 도달하면 경로 찾기 완료
        if (node == 0) {
            this->bob_path[node] = time;
            return true;
        }

        (*visited)[node] = true;
        vector<int> edge = edges[node];
        for (int next : edge) {
            if (next == parent || (*visited)[next]) {
                continue;
            }
            if (this->bob_dfs(next, node, visited, time + 1)) {
                this->bob_path[node] = time;
                return true;
            }
        }
        return false;
    }

    void alice_dfs(int node, int parent, int time, int curr_profit, int* maxProfit) {

        int profit = curr_profit;
        if (time < this->bob_path[node]) {
            profit += this->amount[node];
        } else if (time == this->bob_path[node]) {
            profit += this->amount[node] / 2;
        }

        vector<int> edge = this->edges[node];
        bool is_leaf = true;
        for (int next : edge) {
            if (next == parent) {
                continue;
            }
            is_leaf = false;
            this->alice_dfs(next, node, time + 1, profit, maxProfit);
        }
        if (is_leaf) {
            *maxProfit = max(*maxProfit, profit);
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        this->n = amount.size();
        this->edges = vector<vector<int>>(n);
        this->bob = bob;
        this->amount = amount;
        this->bob_path = vector<int>(this->n, INT_MAX);

        for (auto& edge : edges) {
            this->edges[edge[0]].push_back(edge[1]);
            this->edges[edge[1]].push_back(edge[0]);
        }

        // bob의 경로 찾기
        vector<bool> visited(n, false);
        this->bob_dfs(bob, -1, &visited);

        int maxval = INT_MIN;
        this->alice_dfs(0, -1, 0, 0, &maxval);
        return maxval;
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
    // Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
    // Output: 6
    // Explanation:
   // The above diagram represents the given tree. The game goes as follows:
    // - Alice is initially on node 0, Bob on node 3. They open the gates of their respective nodes.
    //   Alice's net income is now -2.
    // - Both Alice and Bob move to node 1.
    //   Since they reach here simultaneously, they open the gate together and share the reward.
    //   Alice's net income becomes -2 + (4 / 2) = 0.
    // - Alice moves on to node 3. Since Bob already opened its gate, Alice's income remains unchanged.
    //   Bob moves on to node 0, and stops moving.
    // - Alice moves on to node 4 and opens the gate there. Her net income becomes 0 + 6 = 6.
    // Now, neither Alice nor Bob can make any further moves, and the game ends.
    // It is not possible for Alice to get a higher net income.
    // 위의 다이어그램은 주어진 트리를 나타냅니다. 게임은 다음과 같이 진행됩니다:
    // - Alice는 처음에 노드 0에, Bob은 노드 3에 있습니다. 각자의 노드에서 문을 엽니다.
    //   Alice의 순수입은 현재 -2입니다.
    // - Alice와 Bob 모두 노드 1로 이동합니다.
    //   동시에 도착했기 때문에, 함께 문을 열고 보상을 나눕니다.
    //   Alice의 순수입은 -2 + (4 / 2) = 0이 됩니다.
    // - Alice는 노드 3으로 이동합니다. Bob이 이미 문을 열었기 때문에 Alice의 수입은 변하지 않습니다.
    //   Bob은 노드 0으로 이동하고 멈춥니다.
    // - Alice는 노드 4로 이동하여 그곳의 문을 엽니다. 그녀의 순수입은 0 + 6 = 6이 됩니다.
    // 이제 Alice와 Bob 모두 더 이상 이동할 수 없고, 게임이 끝납니다.
    // Alice가 더 높은 순수입을 얻는 것은 불가능합니다.

    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};
    int bob = 3;
    vector<int> amount = {-2,4,2,-4,6};
    EXPECT_EQ(this->s.mostProfitablePath(edges, bob, amount), 6);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
    // Output: -7280
    // Explanation:
    // Alice follows the path 0->1 whereas Bob follows the path 1->0.
    // Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280.

    vector<vector<int>> edges = {{0,1}};
    int bob = 1;
    vector<int> amount = {-7280,2350};
    EXPECT_EQ(this->s.mostProfitablePath(edges, bob, amount), -7280);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
