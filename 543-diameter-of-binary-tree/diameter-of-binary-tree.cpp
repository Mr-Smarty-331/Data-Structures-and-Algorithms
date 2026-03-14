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
    int depth(TreeNode* root, int &mx){
        if (root==NULL) {
            return 0;
        }

        int l=depth(root->left,mx);
        int r=depth(root->right,mx);

        if(mx<l+r) mx=l+r;

        return max(l,r)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int mx=0;
        int a=depth(root,mx);
        return mx;
    }
};