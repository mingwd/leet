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
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;  // Count of valid subarrays
        int n = nums.size();
        int start = 0;  // Start of the sliding window
        unordered_map<int, int>
            freq;  // Frequency map for elements in the window

        for (int end = 0; end < n; ++end) {
            // Add nums[end] to the window
            freq[nums[end]]++;

            // Shrink the window if the max element's frequency falls below k
            while (freq[nums[end]] < k) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) {
                    freq.erase(nums[start]);
                }
                ++start;
            }

            // Count all valid subarrays ending at `end`
            result += end - start + 1;
        }

        return result;
    }
};