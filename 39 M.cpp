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

#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }

   private:
    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& currentCombination,
                   vector<vector<int>>& result) {
        if (target == 0) {
            // If the target is reached, add the current combination to the
            // result
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                // Choose the current candidate
                currentCombination.push_back(candidates[i]);

                // Explore further with the updated target
                backtrack(candidates, target - candidates[i], i,
                          currentCombination, result);

                // Undo the choice (backtrack)
                currentCombination.pop_back();
            }
        }
    }
};
