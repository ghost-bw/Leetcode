class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        unordered_map<char,int> mp;
        for(char ch: word){
            mp[ch]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());

        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;   // sort by frequency
        });
        int count=0;
        for(int i=0;i<vec.size();i++){
            if(i<8){
                count+=vec[i].second;
            }else if(i>=8 && i<16){
                count+=vec[i].second *2;
            }else if(i>=16 && i<24){
                count+=vec[i].second*3;
            }else{
                count+=vec[i].second*4;
            }
        }
        return count;
    }
};