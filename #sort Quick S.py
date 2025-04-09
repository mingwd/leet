def quicksort(arr, low, high):
    """Sorts arr[low..high] in-place using the Quicksort algorithm."""
    if low < high:
        # Partition the array and get the pivot index
        pivot_index = partition(arr, low, high)

        # Recursively sort elements before and after partition
        quicksort(arr, low, pivot_index - 1)
        quicksort(arr, pivot_index + 1, high)


def partition(arr, low, high):
    """Partitions arr[low..high] and returns the index of the pivot."""
    pivot = arr[high]  # Usually choose the last element as the pivot
    i = low - 1        # i will track the pivot's position

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    # After all elements are compared, place the pivot (arr[high]) at the correct position
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


# Example usage:
data = [10, 7, 8, 9, 1, 5]
quicksort(data, 0, len(data) - 1)
print("Sorted array:", data)
