//https://leetcode.com/problems/max-consecutive-ones/submissions/1302090231/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,ans=0;
        for(int i=0;i<nums.size();i++){
            count=0;
            while(i<nums.size() && nums[i]==1){
                count++;
                i++;
            }
            if(count>ans)
                ans=count;
        }
        return ans;
    }  
};