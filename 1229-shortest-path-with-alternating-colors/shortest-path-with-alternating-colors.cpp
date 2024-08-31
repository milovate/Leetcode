typedef pair<int, pair<int, bool>> pp;
class Solution {
private:
    // Generates adjacency list.
    void getAdjacencyList(int n, vector<vector<int>>& Edges, vector<int> adj[]){
        for(auto &it: Edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
    }

    // Dijkstra Algorithm
    void dijkstra(priority_queue<pp, vector<pp>, greater<pp>>& pq, int fromRedDist[], int fromBlueDist[],
        vector<int> adjRed[], vector<int> adjBlue[], vector<bool>& color) {
            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();

                // dis: shortest distance travelled so far till node "node".
                // isRedDir: true if next adjacent edge needs to be red else false for blue. 
                int dis = top.first;
                int node = top.second.first;
                bool isRedDir = top.second.second;
                color[node] = isRedDir;

                // For red adjacent edge.
                if(isRedDir){
                    for(auto it : adjRed[node]){
                        int adjNode = it;
                        if(dis + 1 < fromRedDist[adjNode]){
                            fromRedDist[adjNode] = dis + 1;
                            pq.push({fromRedDist[adjNode],{adjNode, !isRedDir}});
                        }
                    }
                }
                // For blue adjacent edge.
                else{
                    for(auto it : adjBlue[node]){
                        int adjNode = it;
                        if(dis + 1 < fromBlueDist[adjNode]){
                            fromBlueDist[adjNode] = dis + 1;
                            pq.push({fromBlueDist[adjNode],{adjNode, !isRedDir}});
                        }
                    }
                }
            }
        return;
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // Generate the Adjacency List for both colored edges in seperate vector arrays.
        vector<int> adjRed[n];
        vector<int> adjBlue[n];
        getAdjacencyList(n, redEdges, adjRed);
        getAdjacencyList(n, blueEdges, adjBlue);

        // Now that we have adjacency list, initialize two distance arrays 
        // fromRedDist is updated when a node is reached via red edge.
        // vice-versa for fromBlueDist
        int fromRedDist[n];
        int fromBlueDist[n];
        for(int i=0; i<n; i++){
            fromRedDist[i] = fromBlueDist[i] = INT_MAX;
        }

        // {dist, {node, isRedDir}} is defined type for pp: pair<int, pair<int,bool>>
        // isRedDir is true if next edge to be traversed is via Red edges.
        // isRedDir is false otherwise.
        // Create a min heap for Dijkstra
        priority_queue<pp, vector<pp>, greater<pp>> pq;

        // Shortest path if traversed starting from Red edge and altering further.
        fromRedDist[0] = 0;
        pq.push({0, {0,true}});
        vector<bool> color1(n, false);
        color1[0] = true;
        dijkstra(pq, fromRedDist, fromBlueDist, adjRed, adjBlue, color1);

        // Shortest path if traversed starting from Blue edge and altering further.
        fromBlueDist[0] = 0;
        pq.push({0, {0, false}});
        vector<bool> color2(n, false);
        dijkstra(pq, fromRedDist, fromBlueDist, adjRed, adjBlue, color2);
        
        // Storing minimum of both traversal in the answer vertor.
        vector<int> answer(n, INT_MAX);
        for(int i=0; i<n; i++){
            answer[i] = min(fromRedDist[i], fromBlueDist[i]);
            if(answer[i] == INT_MAX) answer[i] = -1;
        }

        return answer;

    }
};