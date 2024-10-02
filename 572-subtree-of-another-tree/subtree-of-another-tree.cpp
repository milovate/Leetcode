
class Solution {
public:
    // Serialize the tree into a string
    string serialize(TreeNode* root) {
        if (!root) return ",#";  // Represent null nodes as ",#"
        return "," + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }

    // Build the LPS (Longest Prefix Suffix) array for KMP algorithm
    vector<int> getLPS(const string& p) {
        int m = p.length();
        vector<int> lps(m, 0);
        int j = 0;
        
        for (int i = 1; i < m; ++i) {
            while (j > 0 && p[i] != p[j]) {
                j = lps[j - 1];
            }
            if (p[i] == p[j]) {
                j++;
                lps[i] = j;
            }
        }
        return lps;
    }

    // KMP algorithm to check if pattern p is a substring of s
    bool kmp(const string& s, const string& p) {
        vector<int> lps = getLPS(p);
        int n = s.length();
        int m = p.length();
        int j = 0;
        
        for (int i = 0; i < n; ++i) {
            while (j > 0 && s[i] != p[j]) {
                j = lps[j - 1];
            }
            if (s[i] == p[j]) {
                j++;
                if (j == m) {
                    return true;  // Substring match found
                }
            }
        }
        return false;  // No match found
    }

    // Main function to check if subRoot is a subtree of root
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootSerial = serialize(root);
        string subRootSerial = serialize(subRoot);
        return kmp(rootSerial, subRootSerial);
    }
};
