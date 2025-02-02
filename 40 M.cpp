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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        sort(candidates.begin(),
             candidates.end());  // Sort to handle duplicates
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }

   private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& currentCombination,
                   vector<vector<int>>& result) {
        if (target == 0) {
            // Add the valid combination to the result
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // If the current candidate exceeds the target, break (since the
            // array is sorted)
            if (candidates[i] > target) break;

            // Choose the current candidate
            currentCombination.push_back(candidates[i]);

            // Recurse with the next index (i + 1) since each number can only be
            // used once
            backtrack(candidates, target - candidates[i], i + 1,
                      currentCombination, result);

            // Backtrack (undo the choice)
            currentCombination.pop_back();
        }
    }
};