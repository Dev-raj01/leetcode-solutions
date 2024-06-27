    //https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/1300960691/

    class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])
                count++;
        }
        if(nums[n-1]>nums[0])
            count++;
        if(count<=1)
            return(true);
        else
            return(false);

    }
};

//better 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int total,sum;
       sum=total=0;
        for(int i=0;i<=n;i++)
            total+=i;
        for(int n:nums)
            sum+=n;
    return (total-sum);
    }
};