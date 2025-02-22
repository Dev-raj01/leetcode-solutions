//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?source=submission-ac

//easy
//by 2 pointer and dp

//dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minbuy=prices[0];
       int pro=0;
       for(auto& p:prices){
        pro=max(pro,p-minbuy);
        minbuy=min(minbuy,p);
       }
       return pro;
    }
};
