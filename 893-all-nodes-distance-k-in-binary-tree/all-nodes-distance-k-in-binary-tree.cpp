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
    map<TreeNode*,TreeNode*> parent;
    vector<int> ans;

    void lookup(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        parent[root]=nullptr;

        while(!q.empty()){
            int s=q.size();
            
            for(int i=0;i<s;i++){
                TreeNode* node= q.front();
                q.pop();

                if (node->left) {
                    parent[node->left]=node;
                    q.push(node->left);
                }

                if (node->right) {
                    parent[node->right]=node;
                    q.push(node->right);
                }
            }
        }
        for(auto x:parent){
            if (x.second==nullptr) continue;
            cout<<x.first->val<<" "<<x.second->val<<endl;

        }
    }

    void check(TreeNode* target,int k){
        unordered_set<TreeNode*> visited;
        queue <pair<TreeNode*,int>> hell;

        hell.push({target,0});

        while(!hell.empty()){
            int s= hell.size();

            // for (int i=0;i<s;i++){
            TreeNode* node=hell.front().first;
            int dist=hell.front().second;
            visited.insert(node);

            hell.pop();

            if (dist==k) {
                ans.push_back(node->val);
                continue;
            }

            if (node->left!=nullptr && visited.find(node->left)==visited.end()){
                hell.push({node->left,dist+1});
                // visited.insert(node->left);
            }

            if (node->right!=nullptr && visited.find(node->right)==visited.end()){
                hell.push({node->right,dist+1});
                // visited.insert(node->right);
            }

            if (parent[node]!=nullptr && parent.find(node) != parent.end() && visited.find(parent[node])==visited.end()){
                hell.push({parent[node],dist+1});
                // visited.insert(parent[node]);
            }
            
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        lookup(root);
        check(target,k);
        return ans;
    }
};