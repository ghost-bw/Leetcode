class Solution {
public:
    int balancedStringSplit(string s) {
        int cR=0,cL=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                cR++;
            }else{
                cL++;
            }
            if(cL==cR){
                count++;
                cL=0;
                cR=0;
            }
        }
        return count;
    }
};