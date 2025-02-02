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
    string tree2str(TreeNode* root) {
        if (!root) return "";

        // Convert the root value to a string
        string result = to_string(root->val);

        // Handle the left child
        if (root->left) {
            result += "(" + tree2str(root->left) + ")";
        } else if (root->right) {
            // Include empty parentheses if there's a right child but no left
            // child
            result += "()";
        }

        // Handle the right child
        if (root->right) {
            result += "(" + tree2str(root->right) + ")";
        }

        return result;
    }
};