class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        queue<int> q;
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it : graph[node]){
                        // if adj node is not colored 
                     // then give it color opposite of node
                     if(color[it]==-1){
                             color[it] = !color[node];
                              q.push(it);
                }
                // if adj node have same color as parent node
                // someone is alredy give color
                // it is not bipartite
                else if(color[it]==color[node]) return false;
            }
                }
            }
        }
        return true;
    }
};