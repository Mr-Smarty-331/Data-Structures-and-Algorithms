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
        int pVal = p->val;
        int qVal = q->val;

        if (qVal<pVal) return lowestCommonAncestor(root,q,p);

        TreeNode* node=root;

        while (true) {
            if (node->val >= pVal && node->val <= qVal) {
                return node;
            }
            else if (pVal < node->val && qVal < node->val) {
                node = node->left;
            }
            else {
                node=node->right;
            }
        }
    }
};