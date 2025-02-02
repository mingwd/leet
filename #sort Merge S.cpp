#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(vector<int> &arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> tempLeft(leftSize);
    vector<int> tempRight(rightSize);

    for (int i = 0; i < leftSize; i++) {
        tempLeft[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        tempRight[i] = arr[mid + i + 1];
    }

    int l = 0, r = 0, k = left;
    while (l < leftSize && r < rightSize) {
        if (tempLeft[l] <= tempRight[r]) {
            arr[k] = tempLeft[l];
            l++;
        } else {
            arr[k] = tempRight[r];
            r++;
        }
        k++;
    }

    while (l < leftSize) {
        arr[k] = tempLeft[l];
        l++;
        k++;
    }

    while (r < rightSize) {
        arr[k] = tempRight[r];
        r++;
        k++;
    }
}