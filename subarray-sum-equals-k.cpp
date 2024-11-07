//https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int arr[nums.size()];
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            arr[i]=sum;
        }
        unordered_map<int,int> mp;
        sum=0;
        for(int i=0;i<nums.size();i++){
            if(arr[i]==k)sum++;
            int diff=arr[i]-k;
            if(mp.find(diff) != mp.end())
                sum+=mp[diff];
            mp[arr[i]]++;
        }
        return sum;
    }
};