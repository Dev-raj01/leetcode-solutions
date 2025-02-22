//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
       int ans=0;

       for(int i=0;i<height.size();i++){
        if(ans< height[i]* max(i,((int)height.size()-i-1))){
            for(int j=0;j<i;j++){
            int area=min(height[i],height[j])*(i-j);
            ans=max(ans,area);
        }
        }
       }
       return(ans);
    }
}

//better with 2pointer
//O(n) time and O(1) space

class Solution {
public:
    int maxArea(vector<int>& h) {
        int l=0,r=h.size()-1;
        int ans=min(h[l],h[r])*(r-l);
        while(l<r){
            if(h[l]<h[r])
                l++;
            else 
                r--;
            ans=max(ans,(min(h[l],h[r])*(r-l)));
        }
        return ans;
    }
};
