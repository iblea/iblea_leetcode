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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 각 노드의 인덱스를 저장할 해시 맵입니다.
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        // 후위 순회 배열의 마지막 인덱스를 저장합니다.
        int postEnd = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, map, 0, inorder.size() - 1, postEnd);
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& map, int inStart, int inEnd, int& postEnd) {
        // 중위 순회 배열의 범위가 잘못된 경우 nullptr을 반환합니다.
        if (inStart > inEnd) {
            return nullptr;
        }
        // 후위 순회 배열에서 현재 노드의 값을 가져옵니다.
        int val = postorder[postEnd];
        // 현재 노드를 생성합니다.
        TreeNode* node = new TreeNode(val);
        // 후위 순회 배열에서 다음 노드의 인덱스를 찾습니다.
        postEnd--;
        // 현재 노드를 기준으로 중위 순회 배열을 두 개의 서브 배열로 분할합니다.
        int index = map[val];
        node->right = buildTreeHelper(inorder, postorder, map, index + 1, inEnd, postEnd);
        node->left = buildTreeHelper(inorder, postorder, map, inStart, index - 1, postEnd);
        // 생성된 노드를 반환합니다.
        return node;
    }
};
