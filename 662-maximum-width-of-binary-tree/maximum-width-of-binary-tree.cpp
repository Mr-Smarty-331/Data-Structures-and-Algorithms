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
    void level(TreeNode* root,int &mx) {
        queue<pair<TreeNode*,long long>> q;
        long long curr = 0;
        q.push({root,curr});

        while(!q.empty()){
            
            int mn=q.front().second;
            int s=q.size();
            int first=0;
            int last=0;

            for (int i=0;i<s;i++){
                curr=q.front().second-mn;
                
                if (i==0) {
                    first=curr;
                }
                if (i==s-1){
                    last=curr;
                }

                auto p = q.front();
                q.pop();
                
                TreeNode* node= p.first;
                if(node->left) {
                    q.push({node->left,curr*2+1});
                }
                if (node->right) {
                    q.push({node->right,curr*2+2});
                }
            }
            mx=max(mx,last-first+1);
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        int mx=0;

        level(root,mx);

        return mx;
    }
};