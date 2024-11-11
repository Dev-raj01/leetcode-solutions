//https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/submissions/1449344372/?envType=daily-question&envId=2024-11-10

//learned adn worked on bit masking and sliding window poroblem
//when going thorught this problem check this link also
//https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/solutions/6028302/bitset-freq-sliding-window-4ms-beats-100

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int currentor=0;
        vector<int>count(32,0);
        int n=nums.size();
        int left=0;
        int minlength=INT_MAX;
        for(int right =0;right<n;right++){
            currentor|=nums[right];
            for(int bit=0;bit<32;bit++){
                if(nums[right]&(1<<bit))
                    count[bit]++;
            }
            while(left<= right && currentor>=k){
                minlength=min(minlength,right-left+1);
                int updatedor=0;
                for(int bit=0;bit<32;bit++){
                    if(nums[left]&(1<<bit)){
                        count[bit]--;
                    }
                    if(count[bit]>0)
                        updatedor|=(1<<bit);
                }
                left++;
                currentor=updatedor;
            }
        }
        return minlength== INT_MAX?-1:minlength;
    }
};