//https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/?envType=daily-question&envId=2024-11-05

class Solution {
public:
    int minChanges(string s) {
        int c=0;
       for(int i=0;i<s.length();i+=2){
        if(s[i]!=s[i+1])
            c++;
       }
       return c;
    }
};