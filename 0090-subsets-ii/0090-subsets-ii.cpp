class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans) {
        // Add the currently formed subset to our answer list
        ans.push_back(current);
        
        for (int j = index; j < nums.size(); j++) {
            // If the current element is a duplicate of the previous element 
            // in the same recursive layer, skip it to avoid duplicate subsets
            if (j > index && nums[j] == nums[j - 1]) continue;
            
            current.push_back(nums[j]);
            backtrack(j + 1, nums, current, ans); // Move to the next element
            current.pop_back(); // Undo choice (backtrack)
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        
        // 1. Crucial step: Sort the array to bring duplicates together
        sort(nums.begin(), nums.end());
        
        // 2. Start generating subsets recursively
        backtrack(0, nums, current, ans);
        
        return ans;
    }
};
