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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(
            26, 0);  // Maximum frequency of each character in words2

        // Step 1: Compute the combined character frequency for words2
        for (const string& b : words2) {
            vector<int> freq = getFrequency(b);
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        // Step 2: Check each word in words1
        vector<string> result;
        for (const string& a : words1) {
            vector<int> freq = getFrequency(a);
            if (isUniversal(freq, maxFreq)) {
                result.push_back(a);
            }
        }

        return result;
    }

   private:
    // Helper function to calculate frequency of characters in a word
    vector<int> getFrequency(const string& word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        return freq;
    }

    // Check if a word satisfies the universal condition
    bool isUniversal(const vector<int>& freq, const vector<int>& maxFreq) {
        for (int i = 0; i < 26; ++i) {
            if (freq[i] < maxFreq[i]) {
                return false;
            }
        }
        return true;
    }
};

// 这个code把顺序也算了，不单单是包不包含
// class Solution {
//    public:
//     vector<string> wordSubsets(vector<string>& words1,
//     vector<string>& words2) {
//         vector<string> result;

//         for (int i = 0; i < words1.size(); i++) {  // pick words from
//         words1
//             int count = 0;
//             string w1 = words1[i];
//             for (int j = 0; j < words2.size(); j++) {
//                 string w2 = words2[j];
//                 if (isUni(w1, w2)) {
//                     count++;
//                 };
//                 // cout << isUniversal << "-" << w1 << "-" << w2 <<
//                 endl;
//             }
//             if (count == words2.size()) {
//                 result.push_back(words1[i]);
//             }
//         }
//         return result;
//     }

//     bool isUni(string& w1, string& w2) {
//         if (w1.length() < w2.length()) {
//             return false;
//         }

//         for (int i = 0; i < w1.length(); i++) {
//             if (w1.at(i) == w2.at(0)) {
//                 if (w2.length() > w1.length() - i) {
//                     return false;
//                 } else {
//                     int w1Position = i;
//                     int w2Position = 0;
//                     while (w2Position < w2.length()) {
//                         if (w1.at(w1Position) != w2.at(w2Position)) {
//                             return false;
//                         }
//                         w1Position++;
//                         w2Position++;
//                     }
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };
