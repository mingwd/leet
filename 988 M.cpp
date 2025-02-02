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
    string smallestFromLeaf(TreeNode* root) {
        string smallest =
            "~";  // A placeholder string larger than any possible result.
        dfs(root, "", smallest);
        return smallest;
    }

   private:
    void dfs(TreeNode* node, string current, string& smallest) {
        if (!node) return;

        // Prepend the current character to the path string
        current = char('a' + node->val) + current;

        // If it's a leaf, update the smallest string
        if (!node->left && !node->right) {
            if (current < smallest) {
                smallest = current;
            }
            return;
        }

        // Recursively traverse left and right subtrees
        dfs(node->left, current, smallest);
        dfs(node->right, current, smallest);
    }
};