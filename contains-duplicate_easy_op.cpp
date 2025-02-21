//https://leetcode.com/problems/contains-duplicate/submissions/1550285664/

//easy optimised

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return unordered_set<int>(nums.begin(),nums.end()).size()<nums.size();
    }
};