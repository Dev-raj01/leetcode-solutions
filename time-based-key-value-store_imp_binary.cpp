//https://leetcode.com/problems/time-based-key-value-store/submissions/1553400926/?envType=daily-question&envId=2025-02-24

//use of upper bound and its struct like linked list

//important
//medium

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int left = 0, right = values.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp) {
                result = values[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

//by upper bound

class TimeMap {
public:
    unordered_map<string, map<int, string>> m;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
};