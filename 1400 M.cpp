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
    bool canConstruct(string s, int k) {
        if (k > s.length())
            return false;  // Not enough characters to form k palindromes

        vector<int> freq(26, 0);  // Frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0;  // Count characters with odd frequencies
        for (int f : freq) {
            if (f % 2 != 0) {
                oddCount++;
            }
        }

        // Check if k is at least the number of odd frequencies
        return k >= oddCount;
    }
};