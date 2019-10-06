/** Vanessa Truong **/
/** Search Insert Position
    
Given a sorted array and a target value, return the index if the target is found. If not, return
the index where it would be if it were inserted in order. You may assume no duplicates in the array. 

Solution: Implemented a helper function modelled after binary search to reduce time complexity to O(log(n)). 
*/ 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        return binarySearch(nums, target, 0, nums.size()-1);
    }
    
    // BinarySearch helper function
    int binarySearch(vector<int>& nums, int target, int low, int high)
    {
        int index = 0;
        
        // Check if arrived at final index search
        if (low == high)
        {
            // If index at this position is greater than/equal to target then return index
            if (target <= nums[low])
            {
                return low;
            }
            // Otherwise target is greater than current index so return index+1;
            else 
            {
                return low+1;
            }
        }

        // Calculate next midpoint of search
        int mid = low + (high - low) / 2;
        
        
        if (nums[mid] == target)
        {   
            // Found target; return index back to caller
            return mid;
        }
        else if (nums[mid] < target)
        {
            index = binarySearch(nums, target, mid+1, high);
        }
        else if (nums[mid] > target)
        {
            index = binarySearch(nums, target, low, mid);
        }
        
        return index;
    }   
};