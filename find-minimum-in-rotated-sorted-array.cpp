//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1552742730/?source=submission-ac
//medium

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r){
           if (nums[m] == target) return m; 
            int m=l+(r-l)/2;
            if(nums[m]<nums[r])
                r=m;
            else
                l=m+1;
        }
        return nums[l];
    }
};