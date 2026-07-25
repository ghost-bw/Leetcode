class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
       unordered_set<int> st;
       for(int i: nums){
            st.insert(i);
       }

       int longest=1;
        for(int x:st){
            if(!st.contains(x-1)){
                int no=x;
                int currl=1;
                while(st.contains(no+1)){
                    currl++;
                    no++;
                }
                longest=max(longest,currl);
            }
        }
        return longest;
    }
};