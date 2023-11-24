#include "Search.h"

int Search::binarySearchIteration(std::vector<int>& arr, int val)
{
    int index = arr.size() / 2;
    int found_index = -1;
    int count = arr.size();


    while (count > 0)  {

        if (arr[index] == val) {
            found_index = index;
            break;
        }

        if (arr[index] > val) {
            index /= 2;
        }

        else {
            index += (index / 2);
        }

        count >>= 1;
    }

    return found_index;
}

int Search::binarySearchRecursive(std::vector<int>& arr, int val)
{
    return binarySearchRecursive(arr, val, 0, arr.size() - 1);
}

int Search::binarySearchRecursive(std::vector<int>& arr, int val, int low, int high) {
    // Base case: if the search space is empty, the target is not found
    if (low > high) {
        return -1;
    }

    // Calculate the middle index of the current search space
    int mid = low + (high - low) / 2;

    // Check if the middle element is the target
    if (arr[mid] == val) {
        return mid;
    }

    // If the target is smaller than the middle element, search in the left half
    else if (arr[mid] > val) {
        return binarySearchRecursive(arr, val, low, mid - 1);
    }

    // If the target is larger than the middle element, search in the right half
    else {
        return binarySearchRecursive(arr, val, mid + 1, high);
    }
}