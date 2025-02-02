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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;  // Base case: tree is empty

        // Search for the node to remove
        if (key < root->val) {
            root->left = deleteNode(root->left, key);  // Go to the left subtree
        } else if (key > root->val) {
            root->right =
                deleteNode(root->right, key);  // Go to the right subtree
        } else {                               // Node with key is found
            // Case 1: Node has no children or only one child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 2: Node has two children
            TreeNode* successor = findSuccessor(root->right);
            root->val = successor->val;  // Copy successor's value to root
            root->right = deleteNode(root->right,
                                     successor->val);  // Delete successor node
        }

        return root;
    }

   private:
    TreeNode* findSuccessor(TreeNode* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
};