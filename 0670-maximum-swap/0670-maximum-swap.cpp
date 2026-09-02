class Solution {
public:
    int maximumSwap(int num) {
        // string str=to_string(num);
        // int l=0;
        // int ans=num;
        // for(int i=0;i<str.length();i++){
        //     for(int j=i+1;j<str.length();j++){
        //         if(str[i]<str[j]){
        //             swap(str[i],str[j]);
        //             ans=max(ans,stoi(str));
        //             swap(str[i],str[j]);
        //         }
        //     }
        // }
        // return ans;
        string str = to_string(num);
        int n = str.length();
        
        // Record the last occurrence index of each digit (0-9)
        vector<int> last_pos(10, -1);
        for (int i = 0; i < n; i++) {
            last_pos[str[i] - '0'] = i;
        }
        
        // Scan from left to right to find the first digit we can improve
        for (int i = 0; i < n; i++) {
            // Check if there is a larger digit (9 down to current digit + 1)
            // that appears later in the string
            for (int d = 9; d > str[i] - '0'; d--) {
                if (last_pos[d] > i) {
                    // Swap them, and we are done! (Greedy choice)
                    swap(str[i], str[last_pos[d]]);
                    return stoi(str); 
                }
            }
        }

        return num;

    }
};