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

#include <vector>
class Solution {
   public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> result1;
        vector<int> result2;

        findLeaf(root1, result1);
        findLeaf(root2, result2);

        if (result1.size() == result2.size()) {
            for (int i = 0; i < result1.size(); i++) {
                if (result1[i] != result2[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    void findLeaf(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;  // Base case: null node
        }
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(root->val);
            return;
        }

        findLeaf(root->left, result);
        findLeaf(root->right, result);
    }
};