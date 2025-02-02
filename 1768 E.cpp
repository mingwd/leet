#include <string>
using namespace std;

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        string result;
        if (word1.length() <= word2.length()) {
            for (int i = 0; i < word1.length(); i++) {
                result += word1[i];
                result += word2[i];
            }
            result +=
                word2.substr(word1.length(), word2.length() - word1.length());
        } else {
            for (int i = 0; i < word2.length(); i++) {
                result += word1[i];
                result += word2[i];
            }
            result +=
                word1.substr(word2.length(), word1.length() - word2.length());
        }
        return result;
    }
};

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int size = max(word1.length(), word2.length());
        string output = "";

        for (int i = 0; i < size; i++) {
            if (i < word1.length()) output += word1[i];
            if (i < word2.length()) output += word2[i];
        }

        return output;
    }
};