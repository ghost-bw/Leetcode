class Solution {
public:
    bool sumGame(string nums) {
        int n=nums.length();
        int suml=0,sumr=0;
        int leftq=0,rightq=0;
        for(int i=0;i<n/2;i++){
            if(nums[i]=='?'){
                leftq++;
            }else{
                suml+=nums[i]-'0';
            }
        }
        for(int i=n/2;i<n;i++){
             if(nums[i]=='?'){
                rightq++;
            }else{
                sumr+=nums[i]-'0';
            }
        }
        int totalq=leftq+rightq;
        if(totalq%2==1)return true;
        return !((2*suml+9*leftq)==(2*sumr+9*rightq));
    }
};