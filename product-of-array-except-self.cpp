//https://leetcode.com/problems/product-of-array-except-self/
//3 approaches done here neetcode array mid

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ans=1;
        int zero=0;
        for(auto n:nums){
            if(n==0)
                zero++;
            else{
                ans*=n;
            }
        }
        if(zero>1)
            return vector<int>(nums.size(),0);
        vector<int> res(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            if (zero > 0) {
                res[i] = (nums[i] == 0) ? ans : 0;
            } else {
                res[i] = ans / nums[i];
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};