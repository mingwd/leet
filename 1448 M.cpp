
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right)
//         : val(x), left(left), right(right) {}
// };

class Solution {
   public:
    int goodNodes(TreeNode *root) {
        return dfs(root, root->val);  // 初始数值
    }

    int dfs(TreeNode *root, int currMax) {
        if (root == nullptr) {
            return 0;
        }

        int count = 0;

        if (root->val >= currMax) {
            count = 1;
            currMax = root->val;
        }

        count += dfs(root->left, currMax);
        count += dfs(root->right, currMax);

        return count;
    }
};