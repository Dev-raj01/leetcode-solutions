//https://leetcode.com/problems/longest-repeating-character-replacement/?source=submission-ac
//done by sliding window and map
//try by sliding window and vector for optimized results 

//medium 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,maxf=0;
        unordered_map<char,int>count;
        int ans=0;
        for(int r=0;r<s.size();r++){
            count[s[r]]++;
            maxf=max(maxf,count[s[r]]);
            while(r-l+1-maxf>k){
                count[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
