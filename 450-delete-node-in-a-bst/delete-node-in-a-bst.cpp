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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* head=root;
        TreeNode* parent=root;

        while(true){
            if (root==NULL) {
                return head;
            }
            if(root->val < key) {
                parent=root;
                root=root->right;
            }
            else if (root->val > key) {
                parent=root;
                root=root->left;
            }
            else {break;}
        }

        if (root==head) {
            if (root->right&&root->left){
                TreeNode* nr=root->right;
                TreeNode* nl=root->left;

                while (nl->right){
                    nl=nl->right;
                }

                nl->right=nr;
                return root->left;
            }
            else if (!root->right&&!root->left) return nullptr;
            else if (!root->right) {
                return root->left;
            }
            else return root->right;
        }

        if (root->left==NULL&& root->right==NULL){
            if (parent->right==root) parent->right=NULL;
            else parent->left=NULL;
            return head;
        }

        if ((root->left==NULL&&root->right) || (root->right==NULL&&root->left)) {
            TreeNode* node = (root->right)? root->right:root->left;

            if (parent->left==root) {parent->left=node;}
            else {parent->right=node;}
            return head;
        }

        if (root->right) {
            if (parent->left==root){
            parent->left=root->right;
            }
            else parent->right=root->right;

            TreeNode* node=root->right;
            
            while(node->left){
                node=node->left;
            }

            node->left = root->left;
        }
        
        else {
            if (parent->left==root){
                parent->left=root->left;
            }
            else parent->right=root->left;
        }
        return head;
    }
};