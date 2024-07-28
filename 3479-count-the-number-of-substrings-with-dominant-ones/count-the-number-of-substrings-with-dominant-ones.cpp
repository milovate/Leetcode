//c++ solution 

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        int output = 0;
        std::vector<int> prefix(s.length(), 0);
        
        // Calculate the prefix sum array
        for (int i = 0; i < s.length(); ++i) {
            if (i == 0) {
                prefix[i] = (s[i] == '1') ? 1 : 0;
            } else {
                prefix[i] = prefix[i - 1] + ((s[i] == '1') ? 1 : 0);
            }
        }

        // Iterate through the string to find the valid substrings
        for (int i = 0; i < s.length(); ++i) {
            int count = 0, one = 0;
            for (int j = i; j < s.length(); ++j) {
                one = prefix[j] - ((i == 0) ? 0 : prefix[i - 1]);  // count of one
                count = j - i + 1 - one;  // count of zero
                
                // Jump where next solution is possible
                if (count * count > one) {
                    j += (count * count - one - 1);
                }

                // Check if the current substring is valid
                if (count * count <= one) {
                    int kl = static_cast<int>(std::sqrt(one));
                    ++output;

                    // Jump where zero can be greater than one
                    if (kl > count) {
                        output += (j + (kl - count) >= s.length()) ? (s.length() - j - 1) : (kl - count);
                        j = j + (kl - count);
                    }
                }
            }
        }
        return output;
    }
};