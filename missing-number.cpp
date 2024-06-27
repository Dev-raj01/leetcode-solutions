//https://leetcode.com/problems/missing-number/submissions/1302066624/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        if(nums[0]!=0)
            return 0;
        while(i < nums.size()){
            int s=i+nums[0];
            if(nums[i]!=s)
                return(s);
            i++;
        }
        return nums[nums.size()-1]+1;
    }
};