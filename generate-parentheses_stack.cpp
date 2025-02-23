//https://leetcode.com/problems/generate-parentheses/submissions/1552433820/?source=submission-ac

//medium question used backtracking

class Solution {
public:
    void backtrack(int open,int close,int n,vector<string>& res,string& stacks){
            if(open<n){
                stacks+="(";
                backtrack(open+1,close,n,res,stacks);
                stacks.pop_back();
            }
            if(close<open){
                stacks+=")";
                backtrack(open,close+1,n,res,stacks);
                stacks.pop_back();
            }
            if(open==n && close==n){
                res.push_back(stacks);
                return;
            }
        }
        
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string>res;
        backtrack(0,0,n,res,s);
        return res;
    }
};
