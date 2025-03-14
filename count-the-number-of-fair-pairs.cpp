//https://leetcode.com/problems/count-the-number-of-fair-pairs/?envType=daily-question&envId=2024-11-13
//better
//https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/6040090/binary-search-on-range-cpp-solution
class Solution {
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) {
        long long ans = 0;
        sort(v.begin(), v.end());

        for (int i = 0; i < v.size() - 1; i++) {
            auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);
            auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);
            ans += (up - low);
        }
        return ans;
    }
};

