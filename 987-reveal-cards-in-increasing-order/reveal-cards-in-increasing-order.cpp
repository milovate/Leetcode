class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>v;
        deque<int>q;
 
        sort(deck.begin(),deck.end(),greater<int>());
        q.push_front(deck[0]);
        for(int i=1;i<n;i++){
            int x=q.back();
            q.pop_back();
            q.push_front(x);
            q.push_front(deck[i]);

        }


        while(!q.empty()){
            int top_element=q.front();
            v.push_back(top_element);
            q.pop_front();
        }

        return v;


    }
};