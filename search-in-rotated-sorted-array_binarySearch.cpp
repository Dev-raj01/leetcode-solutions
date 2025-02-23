//https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1552762787/?source=submission-ac
//medium 
//vvvimportant question

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;  // Calculate mid safely

            if (nums[m] == target) return m;  // 🎯 Found target
            
            // Check which half is sorted
            if (nums[l] <= nums[m]) {  // 🔍 Left half is sorted
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;  // Target is in the left half
                } else {
                    l = m + 1;  // Target is in the right half
                }
            } else {  // 🔍 Right half is sorted
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;  // Target is in the right half
                } else {
                    r = m - 1;  // Target is in the left half
                }
            }
        }
        
        return -1;  // ❌ Target not found
    }
};