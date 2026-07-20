class Solution {
public:
    int hammingWeight(int n) {
        if(n==0) return 0;
        string res="";
        int count=0;
        while(n){
            if(n&1)count++;
            res+=(n&1)+'0';
            n=n>>1;
        }
        
        
        return count;
    }
};