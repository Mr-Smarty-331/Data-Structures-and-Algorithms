/*
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node= new TreeNode(val);
        if (root==NULL) return node;

        TreeNode* head= root;
        TreeNode* prev=nullptr;
        while(true){
            // if (root==NULL) {
            //     break;
            // }
            if (val>root->val) {
                // prev=root;
                // root=root->right;
                if (!root->right){
                    prev=root;
                    break;
                }
                root=root->right;
            }
            else {
                if (!root->left){
                    prev=root;
                    break;
                }
                root=root->left;
            }
        }
        if(prev->val > val){
            prev->left=node;
        }
        else {
            prev->right=node;
        }
        return head;
    }
};