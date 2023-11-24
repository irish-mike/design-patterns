#include "Exercises.h"

#include <iostream>
#include <unordered_map>
#include <unordered_set>


// HASHMAPS
void Excercises::findFirstNonRepeatingChar(std::string &s)
{
	std::unordered_map<char, int> map;
	
	for (char c: s)
	{
		auto result = map.emplace(c, 1);
		if (!result.second) {
			result.first->second++;
		}
	}

	for (char c : s)
	{
		if (map[c] == 1) {
			std::cout << "The First non repeating char is " << c << std::endl;
			return;
		}
	}

	std::cout << "No non repeating chars have been found" << std::endl;
}

// Set
void Excercises::findFirstRepeatingChar(std::string& s)
{
	std::unordered_set<char> set;

	for (char c : s)
	{
		if (set.find(c) != set.end()) {
			std::cout << "The First repeating char is " << c << std::endl;
			return;
		}
		else {
			set.insert(c);
		}
	}

}