class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;
        int n=secret.length();
        for(int i=0;i<n;i++){
            freq1[secret[i]]++;
            freq2[guess[i]]++;
        }
        
        int match=0;
        for(auto &it : freq1){
            char ch=it.first;
            if(freq2.count(ch)){
                match += min(freq1[ch], freq2[ch]);
            }
        }
        int bulls=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
        }
        string ans=to_string(bulls)+"A"+to_string(match-bulls)+"B";
        return ans;
    }
};