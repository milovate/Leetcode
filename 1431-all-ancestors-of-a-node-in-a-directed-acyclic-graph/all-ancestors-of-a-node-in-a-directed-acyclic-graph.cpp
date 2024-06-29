class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //stores vector of adjacency list with each node having a vector of nodes to which it points 
        vector<int> adj_list[n];   
        
        //stores indegree of each node
        vector<int> indegree(n);
        
        //creating adjacency list and updating indegrees
        for(int i=0;i<edges.size();++i)
        {
            adj_list[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        
        //queue for BFS Traversal
        queue<int> q; 
        
        //adding all the nodes with indegree==0 as they act as the source node
        for(int i=0;i<n;++i)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        set<int> st[n]; //to avoid repetition of parent nodes 
        while(!q.empty())
        {
            
            int cur=q.front(); 
            q.pop();
            
            for(auto it:adj_list[cur])
            {
                //inserting immediate parent node to each child of current node
                st[it].insert(cur); 
                
                //adds all the ancestors of the current node
                for(auto it2:st[cur])
                    st[it].insert(it2);
                 
                //adding to queue if indegree ==0
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        
        //to store ans
        vector<vector<int>> ans(n,vector<int>());
        
        //adding ancestors of each node to final ans vector
        for(int i=0;i<n;++i)
            ans[i]=vector<int>(st[i].begin(),st[i].end());
        
        
        return ans; 
    }
};