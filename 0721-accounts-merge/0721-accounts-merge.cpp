	class DisjointSet {
		vector<int> rank,parent,size;
		public:
			DisjointSet(int n){
				rank.resize(n+1,0);  // if 1 based indexing
				parent.resize(n+1);
				size.resize(n+1);
				for(int i=0;i<n;i++){
					parent[i] = i;
					size[i] = 1;
				}
			}
			// path compression
			int findUPar(int node){
				if(node == parent[node]){
					return node;
				}
				parent[node] = findUPar(parent[node]);
				return parent[node];
			}
			void unionByRank(int u,int v){
				int ulp_u = findUPar(u);
				int ulp_v = findUPar(v);
				if(ulp_u == ulp_v) return ;
				if(rank[ulp_u] < rank[ulp_v]){
					parent[ulp_u] = ulp_v;
				}
				else if(rank[ulp_v] < rank[ulp_u]){
					parent[ulp_v] = ulp_u;
				}
				// if both have same rank attach anyone with each other
				else {
					parent[ulp_v] = ulp_u;
					rank[ulp_u]++;
				}
			}
			void unionBySize(int u,int v){
				int ulp_u = findUPar(u);
				int ulp_v = findUPar(v);
				if(ulp_u == ulp_v) return ;
				if(size[ulp_u] < size[ulp_v]){
					parent[ulp_u] = ulp_v;
					size[ulp_v] += size[ulp_u];
				}
				else{
					parent[ulp_v] = ulp_u;
					size[ulp_u] += size[ulp_v];
				}
			}
	};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp;
        // 1.put everything in mapp 
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                // if mail is not in map
                // put with index
                if(mp.find(mail) == mp.end()){
                    mp[mail]=i;
                }
                // if it in mapp then connect with i
                else{
                    ds.unionBySize(i,mp[mail]);
                }
            }
        }
        // 2.store mails wrt to index
        vector<string> MergedMail[n];
        for(auto it : mp){
            string mail = it.first;
            int node = ds.findUPar(it.second); // always store the ultimate parent
            MergedMail[node].push_back(mail);
        }
        // 3. sort everything name ans mails
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(MergedMail[i].size()==0) continue; // if empty
            sort(MergedMail[i].begin(),MergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : MergedMail[i]){
                temp.push_back(it);
            }
        ans.push_back(temp);
        }
        return ans;
    }
};