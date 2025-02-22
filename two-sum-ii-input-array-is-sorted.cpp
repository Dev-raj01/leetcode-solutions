//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/submissions/1551305765/
//medium question

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            if(numbers[l]+numbers[r]==target)
                return {l+1,r+1};
            if(numbers[l]+numbers[r]>target)
                r--;
            else
                l++;
        }
        return {};
    }
};
