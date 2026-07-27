class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int i=s.length()-1;
        while(i>=0){
            if(s[i]==' ' && count>0){
                return count;
            }else if(s[i]!=' '){
                count++;
            }
            i--;
        }
        return count;
    }
};