#include <vector>
using namespace std;

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;  // 别搞忘了
                n--;
            }
            if (n <= 0) {  // if n = 0
                return true;
            }
        }
        return false;
    }
};