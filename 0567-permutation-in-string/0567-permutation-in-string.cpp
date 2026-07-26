class Solution {
public:
    bool equal(vector<int> &freq1,vector<int> &freq2){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        for(int i=0;i<s2.length()-s1.length();i++){
            if(equal(freq1,freq2))return true;
            
            freq2[s2[i+s1.length()]-'a']++;
            freq2[s2[i]-'a']--;
        }
        return equal(freq1,freq2);
    }
};