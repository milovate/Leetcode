class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int lim = (int)(sqrt(r));

        vector<bool> v(lim + 1, true);
        v[0] = v[1] = false; // 0 and 1 are not prime numbers

        for (int i = 2; i * i <= lim; i++) {
            if (v[i]) {
                for (int j = i * i; j <= lim; j += i) {
                    v[j] = false;
                }
            }
        }

        int cnt = 0;
        for (int i = 2; i <= lim; i++) {
            if (v[i]) {
                int square = i * i;
                if (square >= l && square <= r) {
                    cnt++;
                }
            }
        }

        int totalCount = r - l + 1;

        return totalCount - cnt;
    }
};