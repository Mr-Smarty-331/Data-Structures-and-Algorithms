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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int s = q.size();
            if ((q.front()!=root)&&(s&1)) return false;
            stack<TreeNode*> st;
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                if(i<=s/2-1){
                    st.push(node);
                }
                else if (s!=1 && i>s/2-1 && i<=s-1){
                    if (st.top()->val != node->val) {
                        return false;
                    }
                    st.pop();
                }
                q.pop();
                if (node->val!=INT_MIN){if (node->left) q.push(node->left);
                else {
                    TreeNode * temp1 = new TreeNode(INT_MIN);
                    q.push(temp1);
                }
                if (node->right) q.push(node->right);
                else {
                    TreeNode * temp2 = new TreeNode(INT_MIN);
                    q.push(temp2);
                }}
            }
        }
        return true;
    }
};