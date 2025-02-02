class Solution {
   public:
    int largestAltitude(vector<int> &gain) {
        int currPosition = 0;
        int currHeight = 0;
        int maxHeight = 0;
        int maxHeightAt = 0;

        helper(gain, currHeight, currPosition, maxHeightAt, maxHeight);

        return maxHeight;
    }

    void helper(vector<int> &gain, int &currHeight, int &currPosition,
                int &maxHeightAt, int &maxHeight) {
        if (currPosition == gain.size()) {
            return;
        }

        currHeight += gain.at(currPosition);

        if (maxHeight < currHeight) {
            maxHeightAt = currPosition + 1;
            maxHeight = currHeight;
        }

        currPosition += 1;

        helper(gain, currHeight, currPosition, maxHeightAt, maxHeight);
    }
};