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
    TreeNode* build(vector<int> vec,int &i, int bound){
        if(i>=vec.size() || vec[i]>bound) return NULL;

        TreeNode* root= new TreeNode(vec[i++]);

        root->left = build(vec,i,root->val);
        root->right = build(vec,i,bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& vec) {
        int i=0;
        return build(vec,i,1001);
    }
};