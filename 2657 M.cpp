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

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        unordered_map<int, int> frequency;
        vector<int> result;

        for (int i = 0; i < A.size(); i++) {
            int numA = A[i];
            int numB = B[i];

            if (frequency.find(numA) != frequency.end()) {
                frequency[numA]++;
                if (frequency[numA] == 2) {
                    count++;
                }
            }

            if (frequency.find(numB) != frequency.end()) {
                frequency[numB]++;
                if (frequency[numB] == 2) {
                    count++;
                }
            }

            result.push_back(count);
        }
        return result;
    }
};