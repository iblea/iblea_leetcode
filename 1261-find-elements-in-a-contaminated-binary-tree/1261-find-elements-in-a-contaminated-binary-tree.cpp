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