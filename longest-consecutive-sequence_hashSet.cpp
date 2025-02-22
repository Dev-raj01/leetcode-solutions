//https://leetcode.com/problems/longest-consecutive-sequence/submissions/1551290146/

//done by hash set 
//can be optimised ny hash map 
//look for better solution next time
//medium question

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
           unordered_set<int> hash(nums.begin(),nums.end());
        int ans=0;
        for(auto n:hash){
            if(hash.find(n-1)==hash.end()){
                int length=1;
                while(hash.find(n+length)!=hash.end()){
                    length++;
                }
                ans=max(length,ans);
            }
        }
    return ans;
    }
};