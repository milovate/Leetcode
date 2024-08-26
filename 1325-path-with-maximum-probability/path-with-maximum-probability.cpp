class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {




        // dijikstras 

        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        vector<double>dist(n,0);
        priority_queue<pair<double,int>>st;
        st.push({1,start});
        dist[start]=1;
        vector<int> seen(n, 0);


        while(!st.empty()){
            auto t=st.top();
            double prob=t.first;
            int node=t.second;
            st.pop();
            
   if(!seen[node]) {
                seen[node]++;

            for(auto child:adj[node]){
                
                int childnode=child.first;
                double childprob=child.second;
                cout<<childprob<<endl;
                if(childprob*prob>dist[childnode]){
                    dist[childnode]=childprob*prob;
                    st.push({childprob*prob,childnode});
                    // for(int i=0;i<n;i++){
                    //     cout<<dist[i]<<" ";
                    // }cout<<endl;
                }
            }
   }


        }



        return dist[end];
        
    }
};