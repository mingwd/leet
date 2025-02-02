class Solution {  // 非常慢
   public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            int leftSum = 0, rightSum = 0;

            if (i != 0) {
                for (int j = 0; j < i; j++) {
                    leftSum += nums.at(j);
                }
            }
            if (i != nums.size() - 1) {
                for (int k = i + 1; k < nums.size(); k++) {
                    rightSum += nums.at(k);
                }
            }

            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};

// Time Complexity : O(n)
class Solution {
   public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums.at(i);
        }
        int leftSum = 0, rightSum = 0, checkedSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            leftSum = checkedSum;
            rightSum = total - checkedSum - nums[i];
            checkedSum += nums[i];

            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};