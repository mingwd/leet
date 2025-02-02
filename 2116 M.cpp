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
    bool canBeValid(string s, string locked) {
        int n = s.size();

        // A valid parentheses string must have an even number of characters.
        if (n % 2 != 0) return false;

        // Left-to-right pass
        int open = 0, flexible = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                // Fixed character: update balance based on whether it's '(' or
                // ')'
                open += (s[i] == '(' ? 1 : -1);
            } else {
                // Flexible character: can act as '(' or ')'
                ++flexible;
            }

            // If balance + flexible positions is negative, we can't fix it
            if (open + flexible < 0) return false;
        }

        // Right-to-left pass
        open = 0;
        flexible = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                // Fixed character: update balance based on whether it's ')' or
                // '('
                open += (s[i] == ')' ? 1 : -1);
            } else {
                // Flexible character: can act as '(' or ')'
                ++flexible;
            }

            // If balance + flexible positions is negative, we can't fix it
            if (open + flexible < 0) return false;
        }

        // If both passes succeed, the string can be made valid
        return true;
    }
};
