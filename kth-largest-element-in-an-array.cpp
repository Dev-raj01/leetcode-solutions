//https://leetcode.com/problems/kth-largest-element-in-an-array/

//can be optimised by using quick sort


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> minheap;
        for(int n:nums){
            minheap.push(n);
                if(minheap.size()>k) minheap.pop();
        }
        return minheap.top();
    }
};
