/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (root==NULL||root==p||root==q){
        //     return root;
        // }

        // TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // TreeNode* right = lowestCommonAncestor(root->right,p,q);

        // if (left==NULL) return right;
        // else if (right == NULL) return left;
        // else{
        //     return root;
        // }

        int pv=p->val,qv=q->val;

        while(true){
            int rv=root->val;
            if (pv<rv&&qv<rv){
                root=root->left;
            }
            else if(pv>rv&&qv>rv){
                root=root->right;
            }
            else{
                return root;
            }
        }
    }
};