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

class MountainArray {
   public:
    int get(int index);
    int length();
};

class Solution {
   public:
    // Helper function to perform binary search
    int binarySearch(MountainArray& arr, int target, int left, int right,
                     bool ascending) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = arr.get(mid);

            if (midValue == target) {
                return mid;
            }

            if (ascending) {  // Ascending order
                if (midValue < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {  // Descending order
                if (midValue > target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;  // Target not found
    }

    // Helper function to find the peak index
    int findPeakIndex(MountainArray& arr) {
        int left = 0, right = arr.length() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr.get(mid) < arr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;  // Peak index
    }

    // Main function
    int findInMountainArray(int target, MountainArray& mountainArr) {
        // Step 1: Find the peak index
        int peak = findPeakIndex(mountainArr);

        // Step 2: Search in the ascending part
        int result = binarySearch(mountainArr, target, 0, peak, true);
        if (result != -1) {
            return result;
        }

        // Step 3: Search in the descending part
        return binarySearch(mountainArr, target, peak + 1,
                            mountainArr.length() - 1, false);
    }
};
