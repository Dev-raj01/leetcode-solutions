//https://leetcode.com/problems/minimum-window-substring/submissions/1551657711/?source=submission-ac

//hard question
//can be optimised 

class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="")
            return "";
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        pair<int,int> res = {-1,-1};
        int reslen = INT_MAX;
        
        for (auto i:t){
            mpt[i]++;
        }

        int match = 0, need = mpt.size(),l=0;
        for(int r=0;r<s.size();r++){
            char c=s[r];
            mps[c]++;
            if(mpt.count(c) && mpt[c]==mps[c]){
                match++;
            }
            while(match==need){
                if((r-l+1)<reslen){
                    reslen=r-l+1;
                    res={l,r};
                }
                mps[s[l]]--;
                if(mpt.count(s[l]) && mps[s[l]]<mpt[s[l]])
                    match--;
                l++;
            }
        }
        return reslen==INT_MAX?"":s.substr(res.first,reslen);
    }
};
