//https://leetcode.com/problems/sliding-window-maximum/submissions/1551684349/?source=submission-ac

//done by deque
//can be done by many ways look into it 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int l=0,r=0;
        vector<int> ans(nums.size() - k + 1);
        while(r<nums.size()){
            //pop smaller value from q
            while(!q.empty() && nums[q.back()]<nums[r])
                q.pop_back();
            q.push_back(r);

            //remove left value if oversize
            if (l > q.front())
                q.pop_front();

            //condition for the window to grow till size k before operations
            if((r+1)>=k){
                ans[l]=(nums[q.front()]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
