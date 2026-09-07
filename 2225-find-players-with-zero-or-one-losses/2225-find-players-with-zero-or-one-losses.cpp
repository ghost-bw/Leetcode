class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> loss_count;
        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];
            if (loss_count.find(winner) == loss_count.end()) {
                loss_count[winner] = 0;
            }
            loss_count[loser]++;
        }
        vector<int>zeroes;
        vector<int>ones;
        for(const auto& [player,losses]:loss_count){
            if(losses==0){
                zeroes.push_back(player);
            }
            if(losses==1){
                ones.push_back(player);
            }
        }
        sort(zeroes.begin(),zeroes.end());
        sort(ones.begin(),ones.end());
        
        return {zeroes,ones};
    }
};