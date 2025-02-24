/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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