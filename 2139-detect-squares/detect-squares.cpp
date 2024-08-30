#define pll pair<int,int>
#define ff first 
#define ss second
class DetectSquares {
public:
    map<pll,int>cnt;
    map<int,vector<pll>>slope1;
    map<int,vector<pll>>slope2;
    
    DetectSquares() {
        cnt.clear();
        slope1.clear();
        slope2.clear();
    }
    
    void add(vector<int> point) {
        int x=point[0],y=point[1];
        cnt[{x,y}]++;
        slope1[y-x].push_back({x,y});
        slope2[x+y].push_back({x,y});    
    }
    
    int count(vector<int> point) {
        int x=point[0],y=point[1];
        int ans=0;
        for(auto it:slope1[y-x]){
            if(x==it.ff && y==it.ss)
                continue;
            ans+=cnt[{it.ff,y}]*cnt[{x,it.ss}];
        }
         for(auto it:slope2[x+y]){
            if(x==it.ff && y==it.ss)
                continue;
            ans+=cnt[{it.ff,y}]*cnt[{x,it.ss}];
        }
        return ans;
    }
};