//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  ans;
        vector<vector<int>> z;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                break;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[k]<0)
                    break;
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k]==nums[k-1])k--;
                    j++;
                    k--;
                    }
                else if(sum>0) k--;
                else j++;
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
           return ans;
    }
};