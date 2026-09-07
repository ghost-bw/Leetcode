class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        int i=0;
        while(i<chars.size()){
            char curr=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==curr){
                i++;
                count++;
            }
            chars[idx++]=curr;
            if(count>1){
                string cnt=to_string(count);
                for(char ch:cnt){
                    chars[idx++]=ch;
                }
            }
        }
        chars.resize(idx);
        return idx;
    }
};