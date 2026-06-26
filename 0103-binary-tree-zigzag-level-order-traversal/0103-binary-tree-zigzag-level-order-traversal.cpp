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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool odd=1;
        while(!q.empty()){
            int ls=q.size();
            vector<int> temp(ls);
            for(int i=0;i<ls;i++){
                TreeNode* t=q.front();
                 int idx = odd ? i : ls - 1 - i;
                 temp[idx] = t->val;
                
                q.pop();
                
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
            }
            
            ans.push_back(temp);
            odd=1-odd;
        }
        return ans;
    }
};