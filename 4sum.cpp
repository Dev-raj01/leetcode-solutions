//https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        for(int i=1;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++){
                int c=j+1,d=nums.size()-1;
                while(c<d){
                int sum = nums[i]+nums[j]+nums[c]+nums[d];
                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[c],nums[d]});
                    while(c<d && nums[c]==nums[c+1])c++;
                    while(d>c && nums[d]==nums[d-1])d--;
                    c++;
                    d--;
                }
                else if(sum>target) d--;
                else    c++;
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }        
            return ans;
    }
};