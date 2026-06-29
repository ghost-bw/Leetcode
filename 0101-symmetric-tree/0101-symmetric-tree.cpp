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
    bool isSame(TreeNode* p,TreeNode* q){
        if (p==nullptr && q==nullptr) return true;
        if (p==nullptr || q==nullptr) return false;
        if(p->val!=q->val) return false;
        bool l= isSame(p->left,q->right);
        bool r= isSame(p->right,q->left);
        return (l&&r)?true:false;
    }
    bool isSymmetric(TreeNode* root) {
        
        return isSame(root->left,root->right);

    }
};