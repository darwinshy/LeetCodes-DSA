#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    if (nums.size() == 0)
      return -1;
    int low = 0, high = nums.size() - 1;
    int mid;
    while (low < high)
    {
      //find pivot element
      mid = low + (high - low) / 2;
      if (nums[mid] > nums[high])
        low = mid + 1;
      else
        high = mid;
    }
    int start = low;
    low = 0, high = nums.size() - 1;
    mid = 0;
    // check target lies in which of the 2 sorted parts
    if (target >= nums[start] && target <= nums[high])
      low = start;
    else
      high = start;
    while (low <= high)
    { //normal bs
      mid = low + (high - low) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] < target)
        low = mid + 1;
      else if (nums[mid] > target)
        high = mid - 1;
    }
    return -1;
  }
};