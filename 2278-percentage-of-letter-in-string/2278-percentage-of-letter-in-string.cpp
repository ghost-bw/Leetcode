class Solution {
public:
    int percentageLetter(string s, char letter) {
        double count=0;
        for(int i =0;i<s.length();i++){
            if(s[i]==letter){
                count++;
            }
        }
        double sum=(count/s.length());
        double percentage=sum *100;
        return (int)percentage;
    }
};