class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x<y) {
            swap(x,y);
            reverse(s.begin(),s.end());
        }
        int ans =0,acount =0,bcount= 0;
        for (char c: s) {
            if (c == 'a' ) acount++;
            else if ( c =='b') {
                if (acount >0 ) {
                    --acount;
                    ans += x;
                } else {
                    ++bcount;
                }
            } else {
                ans += min(acount,bcount)*y;
                acount =0;
                bcount =0;
            }
        }
        ans += min(acount,bcount)*y;
        return ans;
    }
};