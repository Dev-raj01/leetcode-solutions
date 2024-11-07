//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//sliding window and hashing
//fastest one last position
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength=0;
        int left=0;
        unordered_map<char,int> lastseen;
        for(int right =0;right<s.length();right++){
            char c=s[right];
            if(lastseen.find(c)!=lastseen.end() && lastseen[c]>=left){
                left=lastseen[c]+1;
            }
            maxlength=max(maxlength,right - left + 1);
                lastseen[c] = right;
        }
        return maxlength;
    }
};