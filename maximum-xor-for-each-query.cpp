//https://leetcode.com/problems/maximum-xor-for-each-query/submissions/1446501061/?envType=daily-question&envId=2024-11-08
//learned new methods

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int maxXor = pow(2,maximumBit)-1;  // This is the maximum value of k, with all bits set to 1 up to maximumBit
        vector<int> result(n);
        
        // Calculate the initial XOR of all elements in nums
        int x_total = 0;
        for (int num : nums) {
            x_total ^= num;
        }
        
        // Generate each answer by XORing x_total with maxXor and adjusting x_total in reverse order
        for (int i = 0; i < n; ++i) {
            result[i] = x_total ^ maxXor;  // Find the optimal k for the current x_total
            x_total ^= nums[n - 1 - i];    // Remove the last element's effect on x_total
        }
        
        return result;
    }
};