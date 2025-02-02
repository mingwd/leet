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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;  // Store the sizes of all perfect binary subtrees
        isPerfect(root, sizes);

        // Sort the sizes in descending order
        sort(sizes.rbegin(), sizes.rend());

        // Return the k-th largest size if it exists, otherwise -1
        return (k <= sizes.size()) ? sizes[k - 1] : -1;
    }

   private:
    // Helper function to determine if a subtree is perfect and collect its size
    pair<bool, int> isPerfect(TreeNode* root, vector<int>& sizes) {
        if (!root)
            return {true,
                    0};  // Base case: an empty tree is perfect with size 0

        auto left = isPerfect(root->left, sizes);
        auto right = isPerfect(root->right, sizes);

        // Check if the current subtree is perfect
        if (left.first && right.first && left.second == right.second) {
            int size =
                (1 << (left.second + 1)) - 1;  // Size of a perfect binary tree
            sizes.push_back(
                size);  // Add this size to the list of perfect subtree sizes
            return {true, left.second + 1};
        }

        return {false, 0};  // Not a perfect subtree
    }
};