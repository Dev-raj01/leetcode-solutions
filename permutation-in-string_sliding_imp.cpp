//https://leetcode.com/problems/permutation-in-string/submissions/1551559305/?source=submission-ac

//medium important
//using sliding window with array(26,0)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length())
            return false;
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(int s=0;s<s1.length();s++){
            mp1[s1[s]-'a']++;
            mp2[s2[s]-'a']++;
        }
        int matches=0;
        for(int r=0;r<26;r++){
            if(mp1[r]==mp2[r])
                matches++;
        }
        int l=0;
        for(int r=s1.length();r<s2.length();r++){
            if(matches==26)
                return true;
            int index=s2[r]-'a';
            mp2[index]++;
            if(mp1[index]==mp2[index])
                matches++;
            else if(mp1[index]+1==mp2[index])
                matches--;
            

             index=s2[l]-'a';
             mp2[index]--;
            if(mp1[index]==mp2[index])
                matches++;
            else if(mp1[index]-1==mp2[index])
                matches--;
            l++;
        }
        return matches==26;
    }
};
