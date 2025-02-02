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
    int maxSubArray(vector<int>& nums) {
        int max;
        max = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int localsum = 0;
            for (int j = i; j < nums.size(); j++) {
                localsum += nums[j];
                if (localsum > max) {
                    max = localsum;
                }
            }
        }

        return max;
    }
};

// so much better
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];  // Global maximum sum
        int currentSum = 0;    // Current subarray sum
        int start = 0;         // Start of the sliding window

        for (int end = 0; end < nums.size(); ++end) {
            // Expand the window
            currentSum += nums[end];

            // If the current subarray sum is smaller than nums[end], reset the
            // window
            if (currentSum < nums[end]) {
                currentSum = nums[end];
                start = end;  // Reset the start of the window
            }

            // Update the global maximum
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};