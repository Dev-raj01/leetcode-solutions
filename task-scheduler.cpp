//https://leetcode.com/problems/task-scheduler/

//done by math can be done by greedy and maxheap

//math bettter


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;
        }

        int maxf = *max_element(count.begin(), count.end());
        int maxCount = 0;
        for (int i : count) {
            if (i == maxf) {
                maxCount++;
            }
        }

        int time = (maxf - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), time);
    }
};