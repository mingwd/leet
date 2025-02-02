/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    int longestZigZag(TreeNode* root) {
        int longestCount = 0;
        helper(root, 0, 0, );
    }

    void helper(TreeNode* root, int currPath, int leftOrRight,
                int longestCount) {
        if ((leftOrRight == 0 && root->right == nullptr) ||
            (leftOrRight == 1 && root->left == nullptr) ||
            (root->left == nullptr && root->right == nullptr)) {
            return;
        }

        longestCount++;
    }
};