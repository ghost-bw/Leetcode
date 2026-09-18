class Solution {
public:
    int maxScore(string s) {
        int ones=0;
        for(char ch:s){
            if(ch=='1')ones++;
        }
        int ans=INT_MIN;
        int zeroes=0;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0'){
                zeroes++;
            }else {
                ones--;
            }
            ans=max(ans,zeroes+ones);
        }
        return ans;
    }
};