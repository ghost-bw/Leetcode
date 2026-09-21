class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<pair<int, int>> buckets[26];
        
        for (int i = 0; i < words.size(); ++i) {
            buckets[words[i][0] - 'a'].push_back({i, 0});
        }
        
        int matchingCount = 0;
        
        for (char c : s) {
            int bucketIdx = c - 'a';
            vector<pair<int, int>> currentBucket = move(buckets[bucketIdx]);
            buckets[bucketIdx].clear();
            
            for (auto& p : currentBucket) {
                int wordIdx = p.first;
                int charIdx = p.second + 1; 
                if (charIdx == words[wordIdx].length()) {
                    matchingCount++;
                } else {
                    char nextChar = words[wordIdx][charIdx];
                    buckets[nextChar - 'a'].push_back({wordIdx, charIdx});
                }
            }
        }
        
        return matchingCount;
    }
};
