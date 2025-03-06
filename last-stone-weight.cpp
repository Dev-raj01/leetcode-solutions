//https://leetcode.com/problems/last-stone-weight/submissions/1564546842/
//easy

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(auto s:stones)
            q.push(s);
        while(q.size()>1){
            int n1=q.top();
            q.pop();
            int n2=q.top();
            q.pop();
            if(abs(n1-n2)!=0)
                q.push(abs(n1-n2));
        }
        if(q.size()!=0)
            return q.top();
        return 0;
    }
};
