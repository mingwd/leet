#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;  // An empty tree satisfies the conditions.

        // BFS queue: pair<TreeNode*, int> (node, level index)
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int levelSize = q.size();
            int prevValue = (q.front().second % 2 == 0)
                                ? INT_MIN
                                : INT_MAX;  // Min/Max depending on level index
            bool isEvenLevel = (q.front().second % 2 == 0);  // Check level type

            // Process all nodes in the current level
            for (int i = 0; i < levelSize; ++i) {
                auto [node, level] = q.front();
                // pair<TreeNode*, int> a = q.front();
                q.pop();

                // Check value constraints
                if (isEvenLevel) {
                    // Even-indexed level: values must be odd and strictly
                    // increasing
                    if (node->val % 2 == 0 || node->val <= prevValue) {
                        return false;
                    }
                } else {
                    // Odd-indexed level: values must be even and strictly
                    // decreasing
                    if (node->val % 2 != 0 || node->val >= prevValue) {
                        return false;
                    }
                }
                prevValue = node->val;

                // Add child nodes to the queue with their level
                if (node->left) q.push({node->left, level + 1});
                if (node->right) q.push({node->right, level + 1});
            }
        }

        return true;  // All levels meet the criteria
    }
};
