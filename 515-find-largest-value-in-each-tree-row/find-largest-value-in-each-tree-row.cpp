/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // feels like :
        // bfs -> 
        // map -> to store 
        // unordred_map<int,int>mp;

        

        vector<int>ans;
        if (!root) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        ans.push_back(root->val);


        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* node =temp.first;
            int lvl =temp.second;
            if(ans.size()-1<lvl){
                    ans.push_back(node->val);
                    // cout<<"here"<<endl;
            }
            else ans[lvl]=max(ans[lvl],node->val);

            if (node->left) q.push({node->left,lvl+1});
            if (node->right) q.push({node->right,lvl+1});

        }



        return ans;





    }
};