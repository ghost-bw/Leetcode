class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> freq;
        vector<string>ans;
        for (int i=0;i<s.length();i++){
            string curr=s.substr(i,10);
            if(freq[curr]==1){
                ans.push_back(curr);
            }
            freq[curr]++;
            
        }
        return ans;
    }
};