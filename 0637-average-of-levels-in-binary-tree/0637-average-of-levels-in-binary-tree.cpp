/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL) return {};
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int ls=q.size();
            vector<int> temp;
            while(ls--){
                TreeNode* t=q.front();
                temp.push_back(t->val);
                q.pop();
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
            }
            double avgsum=0;
            double avg;
            for(auto i: temp){
                avgsum+=i;
                 avg=avgsum/temp.size();
            }
            ans.push_back(avg);
        }
        return ans;
    }
};
