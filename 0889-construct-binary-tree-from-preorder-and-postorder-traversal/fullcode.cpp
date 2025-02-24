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
    ~TreeNode() {
        delete left;
        delete right;
    }

    bool operator==(const TreeNode& other) const {
        // // 둘 다 nullptr인 경우
        // if (this == nullptr && &other == nullptr) return true;
        // // 둘 중 하나만 nullptr인 경우
        // if (this == nullptr || &other == nullptr) return false;

        // 현재 노드의 값 비교
        if (this->val != other.val) return false;
        stack<pair<TreeNode*, TreeNode*>> stack;
        stack.push(make_pair(this->left, other.left));
        stack.push(make_pair(this->right, other.right));
        while (!stack.empty()) {
            auto [node1, node2] = stack.top();
            stack.pop();
            if (node1 == nullptr) {
                if (node2 == nullptr)   continue;
                else                    return false;
            } else {
                if (node2 == nullptr)   return false;
            }
            if (node1->val != node2->val) return false;
            stack.push(make_pair(node1->left, node2->left));
            stack.push(make_pair(node1->right, node2->right));
        }
        return true;
    }

};
/*
 * @lc app=leetcode id=889 lang=cpp
 * [889] Construct Binary Tree from Preorder and Postorder Traversal

Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
If there exist multiple answers, you can return any of them.

Constraints:
1 <= preorder.length <= 30
1 <= preorder[i] <= preorder.length
All the values of preorder are unique.
postorder.length == preorder.length
1 <= postorder[i] <= postorder.length
All the values of postorder are unique.
It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
 */

// @lc code=start

class Solution {
private:
    vector<int> *preorder = nullptr;
    vector<int> *postorder = nullptr;
public:
    Solution() {
        this->preorder = nullptr;
        this->postorder = nullptr;
    }

    TreeNode* travel(int pre_start, int pre_end, int post_start, int post_end) {
        if (pre_start > pre_end) return nullptr;

        TreeNode *node = new TreeNode(preorder->at(pre_start));
        if (pre_start == pre_end) return node;

        int post_root_idx;
        int left_root = preorder->at(pre_start + 1); // preorder[pre_start + 1]은 왼쪽 서브트리의 루트
        for (post_root_idx = post_start; post_root_idx <= post_end; post_root_idx++) {
            if (postorder->at(post_root_idx) == left_root) break;
        }

        int left_size = post_root_idx - post_start + 1;
        node->left = this->travel(pre_start + 1, pre_start + left_size, post_start, post_root_idx);
        node->right = this->travel(pre_start + left_size + 1, pre_end, post_root_idx + 1, post_end - 1);
        return node;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {

        this->preorder = &preorder;
        this->postorder = &postorder;

        TreeNode *root = this->travel(0, preorder.size() - 1, 0, postorder.size() - 1);

        // preorder -> 루트, 왼, 오
        // postorder -> 왼, 오, 루트
        // 따라서 preorder의 루트는 0번째, postorder의 루트는 마지막(postorder.size() - 1)번째
        // 따라서 루트를 찾으면 왼쪽 서브트리와 오른쪽 서브트리를 찾을 수 있음
        // 또한 서브트리의 루트 또한 찾을 수 있음.
        // ex ) preorder = 1,2,3,4,5,6,7, postorder = 4,5,2,6,7,3,1
        // 1이 루트고, 2는 왼쪽 서브트리의 루트임.
        // 이걸 이용해 postorder에서 2를 찾으면 왼쪽 서브트리와 오른쪽 서브트리를 찾을 수 있음.
        // 따라서 4 5 2는 왼쪽 서브트리고, 6 7 3은 오른쪽 서브트리임.
        return root;
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
    // Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
    // Output: [1,2,3,4,5,6,7]

    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    TreeNode* root = this->s.constructFromPrePost(preorder, postorder);
    if (root == nullptr) {
        EXPECT_TRUE(false);
        return;
    }
    TreeNode* expected = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), new TreeNode(7)));
    EXPECT_TRUE(*root == *expected);
}

TEST_F(CLASS_NAME, __LINE__)
{
    // Example 2:
    // Input: preorder = [1], postorder = [1]
    // Output: [1]

    vector<int> preorder = {1};
    vector<int> postorder = {1};
    TreeNode* root = this->s.constructFromPrePost(preorder, postorder);
    if (root == nullptr) {
        EXPECT_TRUE(false);
        return;
    }
    TreeNode* expected = new TreeNode(1);
    EXPECT_TRUE(*root == *expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
