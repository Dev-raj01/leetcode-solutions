//https://leetcode.com/problems/binary-search/submissions/1552660115/?source=submission-ac

class Solution {
public:
    

    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
                if(nums[m]>target){
                    r=m-1;
                }else if(nums[m]<target){
                    l=m+1;
                }else
                    return m;
        }
        return -1;
    }
};
