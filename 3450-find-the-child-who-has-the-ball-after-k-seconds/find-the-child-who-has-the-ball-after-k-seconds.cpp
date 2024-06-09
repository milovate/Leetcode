class Solution {
public:
    int numberOfChild(int n, int k) {
        n--; 
        int rounds = k / n; 
        int rem = k % n; 

        if(rounds % 2 == 0) {
            return rem;
        } else {
            return (n - rem); 
        }
    }
};