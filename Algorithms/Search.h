#pragma once
#include <vector>

class Search
{
public:
	static int binarySearchIteration(std::vector<int>& arr, int val);
	static int binarySearchRecursive(std::vector<int>& arr, int val);
	static int binarySearchRecursive(std::vector<int>& arr, int val, int low, int high);
};

