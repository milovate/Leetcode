#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef pair<int,int> pii;

typedef tree<pii, null_type, less_equal<pii>, rb_tree_tag,
            tree_order_statistics_node_update> oset;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        oset st;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i=n-1; i>=0; i--){
            int x = st.order_of_key({nums[i],-1});
            st.insert({nums[i],i});
            ans[i] = x;
        }
        return ans;
    }
};