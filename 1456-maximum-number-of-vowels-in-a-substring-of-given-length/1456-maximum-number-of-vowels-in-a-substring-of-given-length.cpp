class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int l=0;
        int n=s.length();
        int maxcount=0;
        int count=0;
        for(int r=0;r<n;r++){
            int len=r-l+1;
            if(len>k){
                if(isVowel(s[l])){
                    count--;
                    l++;
                }else{
                    l++;
                }
            }
            if(isVowel(s[r]))count++;
            maxcount=max(maxcount,count);

        }
        return maxcount;
    }
};