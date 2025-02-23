//https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1552393345/?source=submission-ac

//medium question used stack
//O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(const auto& c:tokens){
            if(c=="+"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(a+b);
            }else if(c=="-"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(b-a);

            }else if(c=="*"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(b*a);

            }else if(c=="/"){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                s.push(b/a);

            }else{
                s.push(stoi(c));
            }   
        }
        return s.top();
    }
};
