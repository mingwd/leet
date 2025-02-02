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
    int minimizeXor(int num1, int num2) {
        // Count the number of set bits in num2
        int setBitsCount = __builtin_popcount(num2);

        int x = 0;

        // Step 1: Align bits with num1 to minimize XOR
        for (int i = 31; i >= 0 && setBitsCount > 0; --i) {
            if (num1 & (1 << i)) {
                x |= (1 << i);   // Set the bit in x
                --setBitsCount;  // Decrease the required set bits count
            }
        }

        // Step 2: If more bits are needed, set them from the lowest available
        // position
        for (int i = 0; i < 32 && setBitsCount > 0; ++i) {
            if (!(x & (1 << i))) {
                x |= (1 << i);   // Set the bit in x
                --setBitsCount;  // Decrease the required set bits count
            }
        }

        return x;
    }
};