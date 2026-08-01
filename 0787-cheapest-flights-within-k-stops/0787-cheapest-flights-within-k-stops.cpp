class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        // ({stops,{node,cost}})
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(cost + adjWt < dist[adjNode] && stops<=k){
                    dist[adjNode] = cost + adjWt;
                    q.push({stops+1,{adjNode,cost+adjWt}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};