class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n==1){
            res.push_back(0);
            return res;
        }
        vector<int> deg(n);
        vector<vector<int>>gd(n);
        for(auto e: edges){
            deg[e[0]]++;
            deg[e[1]]++;
            gd[e[0]].push_back(e[1]);
            gd[e[1]].push_back(e[0]);
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }
        while(n>2){
            int sz=q.size();
            n-=sz;
            while(sz>0){
                int el=q.front();
                q.pop();
                
                    for(auto i: gd[el]){
                        deg[i]--;
                        if(deg[i]==1)q.push(i);
                    }
                
                sz--;
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
            res.push_back(front);
        }
    return res;
    }
};