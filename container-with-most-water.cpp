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