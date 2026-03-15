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
    int func(TreeNode* root,int &mx){

        if (root==NULL) return 0;

        int l=func(root->left,mx);
        l=max(0,l);
        int r=func(root->right,mx);
        r=max(0,r);
    
        mx=max(mx,((root->val)+l+r));

        return max(l,r)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int mx=root->val;
        int a = func(root,mx);
        return max(mx,a);
    }
};