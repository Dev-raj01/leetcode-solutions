//https://leetcode.com/problems/trapping-rain-water/submissions/1551368588/?source=submission-ac

//hard question imp
//2 pointer

class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1;
        int ans=0,leftmax=h[l],rightmax=h[r];
        while(l<r){
            if(leftmax<rightmax){
                l++;
                leftmax=max(leftmax,h[l]);
                ans+=leftmax-h[l];
            }
            else{
                r--;
                rightmax=max(rightmax,h[r]);
                ans+=rightmax-h[r];
            }
        }
        return ans;
    }
};
