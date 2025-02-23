//https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/1552558461/?source=submission-ac
//hard question
//can be optimised
//important question

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>h;
        int maxarea=0;
        for(int i=0;i<heights.size();i++){
           int start=i;
            while(!h.empty() && h.top().second > heights[i]){
                pair<int,int> top=h.top();
                int index=top.first;
                int height=top.second;
                maxarea=max(maxarea,height*(i-index));
                start=index;
                h.pop();
            }
            h.push({start,heights[i]});
        }
        while(!h.empty()){
            int index=h.top().first;
            int height=h.top().second;
            int s=heights.size();
            maxarea=max(maxarea,height*(s-index));
            h.pop();
        }
        return maxarea;
    }
};
