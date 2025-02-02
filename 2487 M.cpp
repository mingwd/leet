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
    ListNode* removeNodes(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }
        // reverse node
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;

        // remove nodes with smaller value
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int maxSoFar = INT_MIN;

        curr = head;
        while (curr) {
            if (curr->val >= maxSoFar) {
                maxSoFar = curr->val;
                tail->next = curr;
                tail = curr;
            }
            curr = curr->next;
        }
        tail->next = nullptr;

        // print out nodes

        ListNode* test = dummy;
        while (test) {
            cout << test->val << " ";
            test = test->next;
        }

        // delete the first node before reversing
        ListNode* dummyTemp = dummy;
        dummy = dummy->next;
        delete dummyTemp;

        // reverse again
        prev = nullptr;
        curr = dummy;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

// Helper function to process nodes from right to left
ListNode* removeNodesHelper(ListNode* node, int& maxSoFar) {
    if (!node) return nullptr;  // Base case

    // Recursive call to process the next node
    node->next = removeNodesHelper(node->next, maxSoFar);

    // Check if the current node's value is less than the max seen so far
    if (node->val < maxSoFar) {
        return node->next;  // Remove the current node
    } else {
        maxSoFar = node->val;  // Update maxSoFar
        return node;           // Keep the current node
    }
}

class Solution {
   public:
    ListNode* removeNodes(ListNode* head) {
        int maxSoFar = INT_MIN;
        return removeNodesHelper(head,
                                 maxSoFar);  // Start with the helper function
    }
};