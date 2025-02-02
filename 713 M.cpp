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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;  // If k <= 1, no product can be less than k

        int start = 0;    // Start of the sliding window
        int product = 1;  // Product of the current window
        int count = 0;    // Number of valid subarrays

        for (int end = 0; end < nums.size(); ++end) {  // Iterate over the array
            product *= nums[end];  // Expand the window by multiplying nums[end]

            // Shrink the window until the product is < k
            while (product >= k && start <= end) {
                product /= nums[start];  // Shrink the window from the left
                ++start;                 // Move start forward
            }

            // Count all subarrays ending at index `end`
            count += end - start + 1;  // Add the number of subarrays
        }

        return count;  // Total number of valid subarrays
    }
};