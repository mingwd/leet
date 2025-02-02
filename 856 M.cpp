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
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int top = st.top();
                st.pop();
                int prev = st.top();
                st.pop();
                if (top == 0) {
                    st.push(prev + 1);
                } else {
                    st.push(prev + top * 2);
                }
            }
        }
        return st.top();
    }
};