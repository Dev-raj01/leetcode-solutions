//https://leetcode.com/problems/single-number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         for(int i=0;i<nums.size()-1;i++){
            if(nums[i]!=nums[i+1])
            {
                return nums[i];
            }
            if(nums[i]==nums[i+1]){
                i++;
            }
         }
         return nums[nums.size()-1];
    }
};

// better with bitwise operator

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            x=x^nums[i];
        }
        return x;
        
    }
};