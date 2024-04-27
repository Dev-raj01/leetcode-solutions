//https://leetcode.com/problems/3sum-closest/description/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2],sum=0;
        int r=0,l=0;
        for(int i=0;i<nums.size();i++){
            r=nums.size()-1;
            l=i+1;
            while(l<r){
            sum=nums[i]+nums[l]+nums[r];
            if(abs(sum-target)<=abs(ans-target))
            ans=sum;
            if(sum>target)
                r--;
            else if(sum<target)
                l++;
            else 
                return sum;
        }
        }
        return ans;
    }

};