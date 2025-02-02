#include <vector>
using namespace std;
class Solution {
   public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = findMax(candies);
        vector<bool> result(candies.size());
        for (int i = 0; i < candies.size(); i++) {
            if (candies.at(i) + extraCandies >= maxCandy) {
                result.at(i) = true;
            } else {
                result.at(i) = false;
            }
        }
        return result;
    }

   private:
    int findMax(vector<int>& v) {
        int currMax = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v.at(i) > currMax) {
                currMax = v.at(i);
            }
        }
        return currMax;
    }
};