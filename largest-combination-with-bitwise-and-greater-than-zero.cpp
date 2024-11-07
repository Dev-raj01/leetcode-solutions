//https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/?envType=daily-question&envId=2024-11-07
//bit manipulations and counting 
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0;i<24;i++){
            int count =0;
            for(int j=0;j<candidates.size();j++){
                int mask = (1<<i);
                if(candidates[j] & mask){
                    count++;
                }
            }
            ans=max(count,ans);
        }
        return ans;
    }
};