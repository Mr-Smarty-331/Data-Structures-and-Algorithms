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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> vec;
        int v=1;
        if (root==NULL) return vec;
        q.push(root);

        while(!q.empty()){
            int s=q.size();
            vector<int> level;

            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                level.push_back(node->val);
                q.pop();

                if (node->left!=NULL){q.push(node->left);}
                if (node->right!=NULL){q.push(node->right);}
            }

            if (!(v&1)) reverse(level.begin(),level.end());
            v++;

            vec.push_back(level);


        }

        return vec;

    }
};