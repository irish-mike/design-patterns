// InterviewExercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include<cmath> 
#include <set>

void FizzBuzz(int num) {

    for (int i = 1; i <= num; i++) {
        
        if (!(i % 15)) {
            std::cout << "Fizz Buzz!\n";
        }
        else if (!(i % 5)) {
            std::cout << "Fizz!\n";
        }
        else if (!(i % 3)) {
            std::cout << "Buzz!\n";
        }
        else {
            std::cout << i << "!\n";
        }
    }
}

// array must be sorted
int BinarySearchIterative(std::vector<int> &v, int target) {
    
    // set left and right
    int left = 0;
    int right = v.size() - 1;
    

    while (left <= right) {
        // calculate mid point
        int mid = left + (right - left) / 2;

        // if found
        if (v[mid] == target) {
            return mid;
        }

        // if it is less we want to bring the bound up from the left
        else if (v[mid] < target) {
            left = mid + 1;
        }

        // if it is greater we want to bring the bound from the right
        else{
            right = mid - 1;
        }
    }

    return -1;
}

int BinarySearchRecursive(std::vector<int>& v, int target, int left, int right) {

    if (left >= right) return -1;

    int mid = left + (right - left) / 2;

    // if found
    if (v[mid] == target) {
        return mid;
    }

    // if it is less we want to bring the bound up from the left
    else if (v[mid] < target) {
        BinarySearchRecursive(v, target, (mid + 1), right);
    }

    // if it is greater we want to bring the bound from the right
    else {
        BinarySearchRecursive(v, target, left, (mid - 1));
    }

}

int BinarySearchRecursive(std::vector<int>& v, int target) {
    return BinarySearchRecursive(v, target, 0, v.size() - 1);
}

void reverseStringStack(std::string& str) {

    std::stack<char> stack;

    for (size_t i = 0; i < str.length(); i++)
    {
        stack.push(str[i]);
    }

    for (size_t i = 0; i < str.length(); i++)
    {
        str[i] = stack.top();
        stack.pop();
    }

}

void reverseString(std::string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        std::swap(s[i], s[n - i - 1]);
    }
}

bool isPalenmdrome(const std::string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

int missingNumber(const std::vector<int>& nums) {
    int expectedSum = nums.size() * (nums.size() + 1) / 2;
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    return expectedSum - actualSum;
}

void mergeSortedArrays(std::vector<int>& firstArray, int firstArraySize, std::vector<int>& secondArray, int secondArraySize) {
    // Initialize pointers for the current index of interest in firstArray, secondArray, and the merge position in firstArray
    int currentIndexFirstArray = firstArraySize - 1; // Last element index of the populated portion of firstArray
    int currentIndexSecondArray = secondArraySize - 1; // Last element index of secondArray
    int mergePosition = firstArraySize + secondArraySize - 1; // Last position in firstArray after merge

    // Iterate backwards through arrays and merge
    while (currentIndexSecondArray >= 0) {
        // If firstArray is exhausted, or secondArray's current element is greater, use secondArray's element
        if (currentIndexFirstArray < 0 || secondArray[currentIndexSecondArray] > firstArray[currentIndexFirstArray]) {
            firstArray[mergePosition] = secondArray[currentIndexSecondArray];
            currentIndexSecondArray--; // Move to the next element in secondArray
        }
        else {
            // Use firstArray's element since it is greater or equal
            firstArray[mergePosition] = firstArray[currentIndexFirstArray];
            currentIndexFirstArray--; // Move to the next element in firstArray
        }
        mergePosition--; // Move to the next merge position
    }
}


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head, * fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}


class Stack {
    std::vector<int> stack;
public:
    void push(int x) { stack.push_back(x); }
    int pop() {
        if (stack.empty()) return -1;
        int top = stack.back();
        stack.pop_back();
        return top;
    }
    int top() {
        if (stack.empty()) return -1;
        return stack.back();
    }
};

int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// bitnets formula
int fib(int n) {
    double phi = (1 + sqrt(5)) / 2;
    return round(pow(phi, n) / sqrt(5));
}


int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i;
}

int removeDuplicates(int arr[], int n) {
    if (n <= 1)
        return n;

    std::set<int> uniqueElements;

    for (int i = 0; i < n; ++i) {
        uniqueElements.insert(arr[i]);
    }

    int index = 0;

    for (int element : uniqueElements) {
        arr[index++] = element;
    }

    return uniqueElements.size();
}




int main()
{
    int f = fibonacci(9);

    std::cout << f << std::endl;


    f = fib(9);

    std::cout << f << std::endl;
}