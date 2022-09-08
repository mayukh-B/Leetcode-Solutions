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
    int dfs(TreeNode* root, int currSum){
        
        if(!root)return 0;
        
        currSum = currSum*10 + root->val;
        
        if(!root->left and !root->right)return currSum;
        
        return(dfs(root->left,currSum)+dfs(root->right,currSum));
    }
    
    int sumNumbers(TreeNode* root) {
        return  dfs(root,0);
    }
};