class Solution {
public:
    
       vector<pair<int, int>> drn{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
       void dfs(int i, int j, int n, vector<vector<int>>& grid, vector<pair<int, int>>&vis)
        {
           
          if (i < 0 || j < 0 || i == n || j == n || grid[i][j] == 0)
            return;

          pair<int, int> p(i, j);
          if (find(vis.begin(), vis.end(), p) != vis.end())
          {
            return;
          }

          vis.push_back({i, j});

          for (auto [a,b] : drn)
          {
            dfs(i + a, j + b, n, grid, vis);
          }
           
        }

        int bfs(vector<vector<int>>& grid, vector<pair<int,int>>&vis )
        {
            
            queue<pair<int,int>>q;
            for(auto p: vis)
                q.push(p);   
    
            int res = 0;
            while(!q.empty())
            {
                int sz = q.size();
             
                while(sz--)
                {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    
                    for(auto [a,b] : drn)
                    {
                        int ni = i + a;
                        int nj = j + b;
                         
                        if(ni >= 0 && nj >= 0 && ni<grid.size() && nj < grid.size())
                        {
                             pair<int, int> p(ni, nj);
                             if (find(vis.begin(), vis.end(), p) == vis.end())
                              {
                                   if(grid[ni][nj] == 1)
                                   return res;

                                   q.push(p);
                                   vis.push_back(p);
                              }                            
                        }
                    }
                }

                res++;
            }
            
            return res;
        }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        for(int i = 0;i<n; i++)
        {
            for(int j = 0;j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                  vector<pair<int,int>>vis;  
                  dfs(i,j,n, grid,vis);
                  return bfs(grid,vis);  
                }
            }
        }
        
        return 0;
    }
};