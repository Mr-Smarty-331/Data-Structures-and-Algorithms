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
/*
    bool search(TreeNode* root, TreeNode* p, stack<TreeNode*> &st){
        if (root==NULL) return false;
        
        st.push(root);
        if (root==p) return true;
        
        if (search(root->left,p,st)||search(root->right,p,st)){
            return true;
        }

        st.pop();

        return false;
    }

    void popper(stack<TreeNode*>&st1, stack<TreeNode*>& st2){
        if (st1.size()>st2.size()) return popper(st2,st1);

        while(st2.size()>st1.size()) {
            st2.pop();
        }

        while(st1.top()!=st2.top()){
            st1.pop();
            st2.pop();
        }
    }
*/

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if (left==NULL) return right;
        else if (right==NULL) return left;

        // both are non null thus this is the lca and thus we return this and other side would have NULL and we'll just have this side being returned and get the required lca (this ) as answer
        else{
            return root;
        }
    }
};