//https://neetcode.io/problems/string-encode-and-decode
//basic array question did encoding and decoding of a list of string

class Solution {
public:

    string encode(vector<string>& strs) {
            string ans;
            for(const auto& s:strs){
                ans+=to_string(s.size())+"#"+s;
            }
            return ans;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.size()){
             int j=i;
             while(s[j]!='#')
                j++;
            int length = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+length;
            res.push_back(s.substr(i,length));
            i=j;
            }
        return res;
    }
};
