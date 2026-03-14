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
        int l=0,r=0;
        if (!check(node)) return 1;

        else if(check(node)){
            if (node->left!=NULL) l+=subtree(node->left);
            if (node->right!=NULL) r+=subtree(node->right);
        }
        if (l==0) return r+1;
        else if (r==0) return l+1;
        else return (min(l,r)+1);
    }

    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        return subtree(root);
    }
};