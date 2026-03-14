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
    bool check(TreeNode* node){
        if((node->left!=NULL)||(node->right!=NULL)){
            return true;
        }
        return false;
    }
    int subtree(TreeNode* root){
        TreeNode* node=root;
        if (!check(node)) return 1;
        int l=0,r=0;

        if(check(node)){
            if (node->left!=NULL) l+=subtree(node->left);
        }
        if(check(node)){
            if (node->right!=NULL) r+=subtree(node->right);
        }
        return (max(l,r)+1);
    }
    int maxDepth(TreeNode* root) {
        if (root==NULL) return 0;

        return subtree(root);

    }
};