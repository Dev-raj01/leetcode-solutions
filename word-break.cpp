//https://leetcode.com/problems/word-break/description/
//buyhatke interview 
// can be more optimised by bottom ups and trie should look up when reviesing

class Solution {
public:
    unordered_map<int ,bool>memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.length()]=true;
        return dfs(s,wordDict,0);
    }
    bool dfs(const string& s,const vector<string>& w,int i){
        if(memo.find(i)!=memo.end())
            return memo[i];
        for(const string& f :w){
            if(i+ f.length()<=s.length() && s.substr(i,f.length())==f)
                if(dfs(s,w,i+f.length())){
                    memo[i]=true;
                    return true;
                }
        }
        memo[i]=false;
        return false;
    }
};
