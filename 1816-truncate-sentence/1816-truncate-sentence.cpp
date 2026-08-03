class Solution {
public:
    string truncateSentence(string s, int k) {
        int space=0;
        int index=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                space++;
            }
            if(space==k){
                index=i;
                break;
            }
        }
        return (index==-1)?s:s.substr(0,index);
    }
};