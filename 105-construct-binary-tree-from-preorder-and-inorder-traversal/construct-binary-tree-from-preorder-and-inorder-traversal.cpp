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
    map<int,int> mp;

    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int preS,int preE, int inS,int inE){
        if (inS>inE || preS>preE) {
            return nullptr;
        }

        TreeNode* node= new TreeNode(preorder[preS]);

        int inRoot = mp[node->val];
        int leftLen = inRoot - inS;

        node->left= builder(preorder,inorder,preS+1, preS+leftLen, inS,inRoot-1);
        node->right= builder(preorder,inorder,preS+leftLen+1, preE, inRoot+1,inE);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int s=inorder.size();

        for (int i=0;i<s;i++) {
            mp[inorder[i]]=i;
        }

        TreeNode* root = builder(preorder,inorder,0,s-1,0,s-1);

        return root;
    }
};