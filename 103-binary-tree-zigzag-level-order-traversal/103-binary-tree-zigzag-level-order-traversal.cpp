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
        if(!root)return {};
        vector<vector<int>>ans;
        
        queue<TreeNode* >q;
        
        q.push(root);
        int flag=1;
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;
            
            while(sz--){
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
    
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                
              
            }
            if(flag)
            ans.push_back(temp);
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            if(flag==0)flag=1;
            else flag=0;
        }
        
        return ans;
    }
};