//https://leetcode.com/problems/find-if-array-can-be-sorted/submissions/1444882079/?envType=daily-question&envId=2024-11-06

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int prevmax =INT_MIN;
        int curmax = nums[0];
        int curmin =nums[0];
        int setbits= countBits(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(setbits== countBits(nums[i])){
                curmax=max(curmax,nums[i]);
                curmin= min(curmin,nums[i]);
            }
            else{
                if(curmin<prevmax)
                    return false;
                
                prevmax=curmax;
                setbits=countBits(nums[i]);
                curmax=nums[i];
                curmin=nums[i];
            }
        }
        return curmin>prevmax;
    }
    int countBits(int num){
        return bitset<32>(num).count();
    }
};