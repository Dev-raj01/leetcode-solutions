//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0,n=nums.size();
        for(int i=0;i<n;i++){
            k++;
            while(i!=n-1 && nums[i]==nums[i+1]) {
            nums.erase(nums.begin()+i+1);
            n--;
            }
        }
        return k;
    }
};


// better approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};