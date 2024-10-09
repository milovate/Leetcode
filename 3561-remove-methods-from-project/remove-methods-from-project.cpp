class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>ans;
        vector<int>adj[n];
        for(auto it:invocations){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(n,0);
        dfs(k,adj,vis);
        bool temp=false;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                for(auto it:adj[i]){
                    if(vis[it]){
                        temp=true;
                        break;
                    }
                }
            }
        }
        if(!temp){
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    ans.push_back(i);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};