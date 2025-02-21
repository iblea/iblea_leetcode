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



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/?envType=daily-question&envId=2025-02-21
 * @lc app=leetcode id=1261 lang=cpp
 * [1261] Find Elements in a Contaminated Binary Tree

Given a binary tree with the following rules:
1. root.val == 0
2. For any treeNode:
    - If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
    - If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
Implement the FindElements class:
- FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
- bool find(int target) Returns true if the target value exists in the recovered binary tree.

다음과 같은 규칙을 가진 이진 트리가 주어집니다:
1. root.val == 0
2. 모든 treeNode에 대해:
    - treeNode.val이 x 값을 가지고 treeNode.left != null인 경우, treeNode.left.val == 2 * x + 1
    - treeNode.val이 x 값을 가지고 treeNode.right != null인 경우, treeNode.right.val == 2 * x + 2
현재 이진 트리는 오염되어 있어서, 모든 treeNode.val이 -1로 변경되었습니다.
FindElements 클래스를 구현하세요:
- FindElements(TreeNode* root) 오염된 이진 트리로 객체를 초기화하고 복구합니다.
- bool find(int target) 복구된 이진 트리에 target 값이 존재하면 true를 반환합니다.


Example 1:
Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]);
findElements.find(1); // return False
findElements.find(2); // return True

Example 2:
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False

Example 3:
Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True


Constraints:
TreeNode.val == -1
The height of the binary tree is less than or equal to 20
The total number of nodes is between [1, 10**4]
Total calls of find() is between [1, 10**4]
0 <= target <= 10**6
 */
class FindElements {
    TreeNode* tree;
    set<int> values;
public:
    FindElements(TreeNode* root) {
        if (!root) {
            this->tree = nullptr;
            this->values = set<int>();
            return;
        }
        this->tree = root;
        this->tree->val = 0;
        this->values.insert(0);
        stack<TreeNode*> st;
        st.push(this->tree);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node->left) {
                node->left->val = 2 * node->val + 1;
                this->values.insert(node->left->val);
                st.push(node->left);
            }
            if (node->right) {
                node->right->val = 2 * node->val + 2;
                this->values.insert(node->right->val);
                st.push(node->right);
            }
        }

    }

    bool find(int target) {
        return this->values.find(target) != this->values.end();
    }
};
/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
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
	EXPECT_EQ(this->s.solution(), "template_function");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
