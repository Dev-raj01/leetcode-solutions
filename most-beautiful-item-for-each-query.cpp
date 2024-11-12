//https://leetcode.com/problems/most-beautiful-item-for-each-query/submissions/1450468531/
//can be more optimised pls look up when revising by binary search
//https://leetcode.com/problems/most-beautiful-item-for-each-query/submissions/1450468531



class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int m=INT_MAX;
        vector<vector<int>> maxbeauty={{0,0,m}};
        sort(items.begin(),items.end());
        for(const auto& item: items){
            int price=item[0];
            int beauty=item[1];
            if(beauty> maxbeauty.back()[1]){
                maxbeauty.back()[2]=price;
                maxbeauty.push_back({price,beauty,m});
            }
        }
        vector<int> ans;

        for (int x : queries) {
            for (int i = maxbeauty.size() - 1; i >= 0; i--) {
                if (maxbeauty[i][0] <= x) {
                    ans.push_back(maxbeauty[i][1]);
                    break;
                }
            }
        }
        return ans;
    }
};