class Solution {
public:
    int colored[101];
    bool solve(vector<vector<int>> graph, int color, int node, vector<int>&colored){
        
        colored[node]=color;
        
        for(auto it : graph[node]){
            if(colored[it]==-1){
                if(solve(graph,!color,it,colored))return true;
            }else if(colored[it]==color)return true;
        }
        
        return false;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
       vector<int>colored(graph.size(),-1);
            
        for(int i =0 ;i<graph.size(); i++){
            if(colored[i]== -1 and solve(graph, 0, i,colored)){
                return false;

            }
        }
        return true;
    }
};