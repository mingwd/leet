#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        stack<string> words;
        string word;
        int position = 0;
        for (char c : s) {
            if (c != ' ') {
                word += c;
            } else if (c == ' ') {
                if (word.length() != 0) {
                    words.push(word);
                    word.clear();
                }
            }

            if (position == s.length() - 1 && word.length() != 0) {
                words.push(word);
            }
            position++;
        }

        string result = words.top();
        words.pop();
        while (!words.empty()) {
            result += ' ';
            result += words.top();
            words.pop();
        }
        return result;
    }
};