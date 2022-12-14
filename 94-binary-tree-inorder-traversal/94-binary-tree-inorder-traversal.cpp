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
//     private:
//     void solve(TreeNode* root, vector<int>&ans){
//         if(root == NULL)return;
        
       
//         solve(root->left,ans);
//         ans.push_back(root->val);
//         solve(root->right,ans);
//     }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty())break;
                node= st.top();
                res.push_back(node->val);
                st.pop();
                node= node->right;
            }
        }
        return res;
    }
};