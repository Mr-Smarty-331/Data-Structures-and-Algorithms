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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack <TreeNode*> st1;
        stack <TreeNode*> st2;

        bool a = search(root,p,st1);
        bool b = search(root,q,st2);

        popper(st1,st2);

        return st1.top();
    }
};