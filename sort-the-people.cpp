//https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22
//lesrned decending loops and pairs revision

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        const int n=names.size();
        vector<pair<int, string>> hn(n);
        for(int i=0; i<n; i++) 
            hn[i]={heights[i], names[i]};
        sort(hn.begin(), hn.end(), greater<>());
        for(int i=0; i<n; i++) 
            names[i]=hn[i].second;
        return names;    
    }
};
