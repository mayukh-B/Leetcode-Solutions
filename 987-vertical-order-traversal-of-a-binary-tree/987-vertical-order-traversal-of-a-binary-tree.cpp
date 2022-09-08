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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // first i need to store the elements in such a way that they are stored vertically and if there exists elements in same vertical order as well as in same level.. then we need to store them in a sorted manner
        
        // so i will take a map of int(which denotes the current vertical), map of int(denotes the level) , multiset which stores the nodes in sorted manner
        
        map<int, map<int, multiset<int>>> nodes;
        
        //so now i need a data structure which will hold my node, the vertical position and the current level of the node.
        
        queue<pair<TreeNode*, pair<int,int>>>q;
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            TreeNode* currNode = q.front().first;
            int vert = q.front().second.first;
            int lvl = q.front().second.second;
            
            q.pop();
            nodes[vert][lvl].insert(currNode->val);
            if(currNode -> left){
                q.push({currNode->left,{vert-1,lvl+1}});
            }
            if(currNode -> right){
                q.push({currNode -> right,{vert+1,lvl+1}});
            }
        }
        vector<vector<int>>ans;
        
        for(auto vertLayer : nodes){
            vector<int>temp;
            for(auto levelLayer : vertLayer.second){
                for(auto node : levelLayer.second){
                    temp.push_back(node);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
    
};