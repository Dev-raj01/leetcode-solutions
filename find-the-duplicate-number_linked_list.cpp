//https://leetcode.com/problems/find-the-duplicate-number/submissions/1561040804/


//done by faster pointer and slow pointer approach
//fFloyd’s Tortoise

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(fast==slow)
                break;
        }
        int slow2=0;
        while(true){
            slow=nums[slow];
            slow2=nums[slow2];
            if(slow==slow2)
                return slow ;
        }
    }
};
