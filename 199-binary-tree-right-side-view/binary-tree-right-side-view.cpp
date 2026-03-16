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
    void func(TreeNode* root,vector<int> & v, int & hm, int h){
        if (root==NULL) return;

        if (h>hm) {
            hm=h;
            v.push_back(root->val);
        }

        func(root->right,v,hm,h+1);
        func(root->left,v,hm,h+1);

        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        if (root!=NULL) vec.push_back(root->val);
        int hm=1;
        func(root,vec,hm,1);

        return vec;
    }
};