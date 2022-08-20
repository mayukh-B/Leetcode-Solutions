class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
       
        vector<pair<int,int>>adj[n+1];
        
        for(auto it  : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>time(n+1, INT_MAX);
        time[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            
            int node = pq.top().second;
            // int t = pq.top().first;
            
            pq.pop();
            
            for(auto it : adj[node]){
                
                int nd = it.first;
                int wt = it.second;
                
                if(wt+time[node] < time[nd]){
                    time[nd]=wt+time[node];
                    pq.push({time[nd],nd});
                }
            } 
            
        }
        
      
        
       int ans=*max_element(time.begin()+1, time.end());     //to get max time taken
        //if it is impossible for all nodes to receive signal, i.e we still have INT_MAX in res 
        //array, so return -1. Else return ans
        return ans==INT_MAX?-1:ans;       
    }
};