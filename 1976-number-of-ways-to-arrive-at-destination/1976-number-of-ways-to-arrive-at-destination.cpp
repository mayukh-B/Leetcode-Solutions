class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
       
        
        vector<long long>ways(n,0);
        
        long long maxi = 1e18;
        vector<long long>dist(n,maxi);
        long long mod = 1e9+7;
        
        dist[0]=0;
        ways[0]=1;
        
        
        vector<pair<long long,long long>>adj[n];
        
        for(auto it : roads){
            
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        pq.push({0,0});
        
        while(!pq.empty()){
            
            
            long long dis = pq.top().first;
            long long nd = pq.top().second;
          
            
            pq.pop();
            
            for(auto it : adj[nd]){
                long long adjNode = it.first;
                long long wt = it.second;
                
                if(wt+ dis < dist[adjNode]){
                    dist[adjNode]=wt+dis;
                    ways[adjNode]=ways[nd];
                    pq.push({dist[adjNode],adjNode});
                }
                else if(wt+dis == dist[adjNode]){
                    ways[adjNode]= (ways[adjNode]+ways[nd])%mod;
                }
                
                
            }
            
            
            
        }
        
        return ways[n-1];
    }
};