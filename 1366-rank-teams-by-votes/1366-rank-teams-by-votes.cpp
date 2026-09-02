class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int m = votes[0].length();
        // rank_count[team - 'A'][rank] = frequency
        vector<vector<int>> rank_count(26, vector<int>(m, 0));
        
        // 1. Count the votes for each position
        for (const string& vote : votes) {
            for (int rank = 0; rank < m; rank++) {
                rank_count[vote[rank] - 'A'][rank]++;
            }
        }
        
        // 2. Initialize the result string with all teams present
        string result = votes[0];
        
        // 3. Sort the teams using a custom greedy lambda comparator
        sort(result.begin(), result.end(), [&](char a, char b) {
            for (int rank = 0; rank < m; rank++) {
                if (rank_count[a - 'A'][rank] != rank_count[b - 'A'][rank]) {
                    // Team with more votes at this position comes first
                    return rank_count[a - 'A'][rank] > rank_count[b - 'A'][rank];
                }
            }
            // Tie-breaker: Alphabetical order
            return a < b;
        });
        
        return result;
    }
};
