//https://leetcode.com/problems/move-zeroes/submissions/1301317242/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num=0,zero=0;
        while(num<nums.size() && zero<nums.size()){
            if(nums[zero]!=0){
                zero++;
                num++;
            }
            else if(nums[num]==0){
                num++;
            }
            else{
                if(nums[zero]==0){
                    swap(nums[zero++],nums[num++]);
                }
            }
        }
    }
};