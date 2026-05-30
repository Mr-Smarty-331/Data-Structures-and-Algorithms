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
    map<TreeNode*,int> memo;
    int recur(TreeNode* node){
        if (node == NULL) return 0;
        if (memo.count(node)!=0) return memo[node];

        int take = 0;
        int nottake = 0;

        if (node->left){
            nottake += recur(node->left);
            if (node->left->left) take += recur(node->left->left);
            if (node->left->right) take += recur(node->left->right);
        }
        
        if (node->right){
            nottake += recur(node->right);
            if (node->right->left) take += recur(node->right->left);
            if (node->right->right) take += recur(node->right->right);
        }

        take += node->val;
        
        return memo[node] = max(take,nottake);
    }
public:
    int rob(TreeNode* root) {
        // TreeNode* prev = new TreeNode(0);
        return recur(root);
    }
};