using namespace std;
class Solution {
public:
    string toBinary(int num) {
        return bitset<32>(num).to_string().substr(bitset<32>(num).to_string().find('1'));
    }
    
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            string binA = toBinary(a);
            string binB = toBinary(b);
            return binA + binB > binB + binA;
        });
        
        string res = "";
        for (int n : nums) {
            res += toBinary(n);
        }

        return bitset<64>(res).to_ullong();
    }
};