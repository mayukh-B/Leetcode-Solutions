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
    
private:
    int depth(TreeNode* root){
        if(!root)return 0;
        
        int lh = depth(root->left);
        int rh = depth(root->right);
        
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
         if(!root)return true;
        int height  = depth(root);
       
        int lh = depth(root->left);
        int rh = depth(root->right);
        
        if(abs(lh-rh)>1)return false;
        
        bool lt = isBalanced(root->left);
        bool rt = isBalanced(root->right);
        
        if(!lt or !rt)return false;
        
        return true;
    }
};