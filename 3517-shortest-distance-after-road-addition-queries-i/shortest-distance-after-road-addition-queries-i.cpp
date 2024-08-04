class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1});
        }

        int q=queries.size();


vector<int>ans;
for(int i=0;i<q;i++){
        set<pair<int,int>>st;
        st.insert({0,0});
        vector<int>dist(n,1e9);
        // vector<int>vis();
        dist[0]=0;
        adj[queries[i][0]].push_back({queries[i][1],1});
        while(!st.empty()){
            auto t=*(st.begin());
            int node=t.second;
            int d=t.first;
            st.erase(t);

            for(auto child :adj[node]){
                int c=child.first;
                int cwt=child.second;

                if(d+cwt<dist[c]){
                    dist[c]=d+cwt;
                    st.insert({dist[c],c});
                }
            }


        }

        ans.push_back(dist[n-1]);

}





return ans;





    }
};