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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;

        q.push({root,{0,0}});
        while(!q.empty()){
            auto qe=q.front();
            q.pop();
            int x=qe.second.first,y=qe.second.second;
            mp[x][y].insert(qe.first->val);

            if (qe.first->left) {
                q.push({qe.first->left,{x-1,y+1}});
            }

            if (qe.first->right) {
                q.push({qe.first->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto m: mp){
            vector<int> col;
            for (auto n:m.second){
                col.insert(col.end(),n.second.begin(),n.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};