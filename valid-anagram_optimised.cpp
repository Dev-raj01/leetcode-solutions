//https://leetcode.com/problems/valid-anagram/description/

//done with hash

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(auto val:count){
            if(val!=0)
                return false;
        }
        return true;
    }
};
