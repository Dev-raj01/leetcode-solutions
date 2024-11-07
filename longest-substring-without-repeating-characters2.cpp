//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//sliding window and hashing

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength=0;
        int left=0;
        unordered_map<char,int> count;
        for( int right=0;right<s.length();right++){
            char c=s[right];
            count[c]++;
            while (count[left]>1)
            {
                count[s[left]]--;
                left++;
            }
            maxlength=max(maxlength,right - left + 1);
        }
    return maxlength;
    }