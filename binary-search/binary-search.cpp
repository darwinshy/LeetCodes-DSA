// Basic Implementation of Binary Search
// This algorithm run in O(logn)
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int middle;
        int start = 0, last = nums.size() - 1;

        while (start <= last)
        {
            // Finds the Middle Index
            middle = start + (last - start) / 2;
            // If the found equality in the first attempt return the index
            if (target == nums[middle])
                return middle;
            // If the target is less the array[middle] then,
            //  shift the right pointer one less than middle index
            if (target < nums[middle])
                last = middle - 1;
            // If the target is more the array[middle] then,
            //  shift the left pointer one more than middle index
            if (target > nums[middle])
                start = middle + 1;
        }
        return -1;
    }
};
