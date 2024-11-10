//https://leetcode.com/problems/minimum-array-end/?envType=daily-question&envId=2024-11-09

//2 ways of doing this problem 1st one is easy 2nd is optimised

class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        vector<int> xbit(64,0);
        vector<int> ubit(64,0);
        for(int i=0;i<32;i++){
            xbit[i]=(x>>i)&1;
            ubit[i]=(n>>i)&1;
        }
        int j=0;
        int i=0;
        while(i<64){
            if(xbit[i]==1){
                i++;
                continue;
            }
                xbit[i++]=ubit[j++];
        }
    long long ans=0;
    for(i=0;i<64;i++){
        ans+= xbit[i]*(1ll<<i);
    }
    return ans;
    }
};


//Optimised solution
class Solution {
public:
    long long minEnd(int n, int x) {
        long result =x;
        long remaining =n-1;
        long position=1;
        while(remaining){
            if(!(x&position)){
                result|=(remaining&1)*position;
                remaining>>=1;
            }
            position<<=1;
        }
        return result;
    }
};