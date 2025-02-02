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
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;  // Tracks the maximum diameter
        calculateHeight(root, maxDiameter);
        return maxDiameter;
    }

   private:
    int calculateHeight(TreeNode* root, int& maxDiameter) {
        if (root == nullptr) {
            return 0;  // Base case: height of an empty tree is 0
        }

        int leftHeight = calculateHeight(root->left, maxDiameter);
        int rightHeight = calculateHeight(root->right, maxDiameter);

        // Update the maximum diameter if the current path is longer
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current node
        return 1 + max(leftHeight, rightHeight);
    }
};
