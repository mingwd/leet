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

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);  // Initialize result array with 1s

        // Step 1: Calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = prefix;  // Store the prefix product
            prefix *= nums[i];   // Update the prefix product
        }

        // Step 2: Calculate suffix products and multiply with prefix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= suffix;  // Multiply by the suffix product
            suffix *= nums[i];    // Update the suffix product
        }

        return result;
    }
};