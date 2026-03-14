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
        if (node->left!=NULL||node->right!=NULL) return true;
        else return false;
    }
    int depth(TreeNode* root){
        TreeNode* node=root;
        if (!check(node)) return 1;
        else{
            int l=0;
            int r=0;

            if (node->left!=NULL) {
                l=depth(node->left);
                if (l==-1) return -1;
            }
            if (node->right!=NULL) {
                r=depth(node->right);
                if (r==-1) return -1;
            }

            if (abs(l-r)>1) return -1;
            else{
                return max(l,r)+1;
            }
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root==NULL) return true;
        if (depth(root)!=-1) return true;
        else return false;
    }
};