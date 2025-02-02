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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Map to store prefix sums and their corresponding nodes
        unordered_map<int, ListNode*> prefixMap;

        // Prefix sum variable
        int prefixSum = 0;

        // First pass: Build the prefix sum map
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            prefixMap[prefixSum] = curr;
        }

        // Second pass: Modify the list to skip zero-sum sequences
        prefixSum = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            curr->next = prefixMap[prefixSum]->next;
        }

        // Return the modified list starting from the dummy's next node
        ListNode* newHead = dummy->next;
        delete dummy;  // Clean up the dummy node
        return newHead;
    }
};