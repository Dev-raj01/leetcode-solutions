//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//sliding window and set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int left =0;
       int maxl=0;
       unordered_set<char> Set;
       for(int right=0;right<s.length();right++){
        while(Set.find(s[right]) != Set.end()){
            Set.erase(s[left]);
            left++;
        }
        Set.insert(s[right]);
       maxl=max(maxl,right - left + 1);
       } 
        return maxl;
    }
};