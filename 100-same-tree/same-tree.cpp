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
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        queue<TreeNode*> q1,q2;

        vector<vector<int>> v1,v2;

        q1.push(t1);
        q2.push(t2);

        while(!q1.empty()){
            int s=q1.size();
            vector<int> level;
            
            for (int i=0;i<s;i++){
                TreeNode* node=q1.front();
                q1.pop();
                if (node==NULL) {
                    level.push_back(INT_MIN);
                    continue;
                }

                level.push_back(node->val);

                if (node->left!=NULL) {q1.push(node->left);}
                else {q1.push(NULL);}

                if (node->right!=NULL) q1.push(node->right);
                else {q1.push(NULL);}

            }
            v1.push_back(level);
        }
        while(!q2.empty()){
            int s=q2.size();
            vector<int> level;
            
            for (int i=0;i<s;i++){

                TreeNode* node=q2.front();
                q2.pop();
                if (node==NULL) {
                    level.push_back(INT_MIN);
                    continue;
                }

                level.push_back(node->val);

                if (node->left!=NULL) {q2.push(node->left);}
                else {q2.push(NULL);}

                if (node->right!=NULL) q2.push(node->right);
                else {q2.push(NULL);}

            }
            v2.push_back(level);
        }
        return (v1==v2);
    }
};