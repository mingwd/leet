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
    string minRemoveToMakeValid(string s) {
        string firstPass;
        // Left-to-right pass

        int open = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == ')') {
                open += (s[i] == '(' ? 1 : -1);
            }

            if (open >= 0) {
                firstPass += s[i];
            } else {
                open++;
            }
        }

        string secondPass;
        // Right-to-left pass
        open = 0;
        for (int i = firstPass.size() - 1; i >= 0; --i) {
            if (firstPass[i] == '(' || firstPass[i] == ')') {
                open += (firstPass[i] == ')' ? 1 : -1);
            }

            if (open >= 0) {
                secondPass += firstPass[i];
            } else {
                open++;
            }
        }

        string answer;

        // reverse
        for (int i = secondPass.size() - 1; i >= 0; i--) {
            answer += secondPass[i];
        }
        // If both passes succeed, the string can be made valid
        return answer;
    }
};