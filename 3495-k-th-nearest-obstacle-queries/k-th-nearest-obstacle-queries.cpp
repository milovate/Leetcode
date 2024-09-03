class Solution {
public:
vector<int> resultsArray(vector<vector<int>>& queries, int k) {
    vector<int> ans;
    priority_queue<int> pq;
    for(auto q: queries){
        pq.push(abs(q[0]) + abs(q[1]));
        if(pq.size() > k) pq.pop();
        ans.push_back((pq.size() < k)?-1: pq.top());
    }
    return ans;
}
};