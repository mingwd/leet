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
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return 0;

        int count = 0;

        dfs(root, targetSum, 0, count);  // from root

        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }

    void dfs(TreeNode *root, int &targetSum, long long currSum, int &count) {
        if (root == nullptr) return;  // 一直到底

        currSum += root->val;

        if (currSum == targetSum) {
            count++;
        }

        dfs(root->left, targetSum, currSum, count);
        dfs(root->right, targetSum, currSum, count);
    }
};