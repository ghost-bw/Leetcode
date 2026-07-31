class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt1(26,0);
         int l=0;
         int count=0;
         int n=s.length();
         int unique_chars=0;
         for(int r=0;r<s.length();r++){
            
            if (cnt1[s[r] - 'a'] == 0) {
                unique_chars++;
            }
            cnt1[s[r]-'a']++;
            while(unique_chars==3){
                count+=n-r;
                cnt1[s[l]-'a']--;
                if (cnt1[s[l] - 'a'] == 0) {
                    unique_chars--;
                }
                
                l++;
            }
         }
         return count;


    }
};