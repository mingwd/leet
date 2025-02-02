#include <vector>
using namespace std;

#include <iostream>
#include <vector>

// Function to partition the array
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;        // Index for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);  // Place pivot in correct position
    return i + 1;
}

// QuickSort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
