//https://leetcode.com/problems/daily-temperatures/submissions/1552466737/?source=submission-ac

//medium question used stack
//can be optimised my dp do look into it 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
        s.push(0);
        vector<int> ans(temperatures.size(),0);
        for(int t=1;t<temperatures.size();t++){
                while(!s.empty() && temperatures[s.top()]<temperatures[t]){
                    ans[s.top()]=t-s.top();
                    s.pop();
                }
                s.push(t);
        }
        return ans;
    }
};
