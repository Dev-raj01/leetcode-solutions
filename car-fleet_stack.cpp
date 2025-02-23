//https://leetcode.com/problems/car-fleet/submissions/1552498504/?source=submission-ac
//medium question used stack
//can be done using basic itteration using by current time and previous time
//to better optimisation

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        vector<double> stack;
        for (auto& p : pair) {
            stack.push_back((double)(target - p.first) / p.second);
            if (stack.size() >= 2 && 
                stack.back() <= stack[stack.size() - 2]) 
            {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        
        int fleets = 1;
        double prevTime = (double)(target - pair[0].first) / pair[0].second;
        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - pair[i].first) / pair[i].second;
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};