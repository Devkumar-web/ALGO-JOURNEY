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
        // int recur(TreeNode* root){
        //     if(root==nullptr){
        //         return 0;
        //     }
        //     int left=1+recur(root->left);
        //     int right=1+recur(root->right);

        //     return max(left,right);

        // }
    int maxDepth(TreeNode* root) {
        
        //lets do bfs
        // queue<TreeNode*> q;
        // q.push(root);
        // int count=0;
        // while(!q.empty() && root ){
        //     int loop=q.size();
        //     for(int i=0;i<loop;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         if(node->left)q.push(node->left);
        //         if(node->right)q.push(node->right);

        //     }
        //     count++;
        // }
        // return count;

        stack<pair<TreeNode*,int>> st;
        int ans=0;
        if(root==nullptr){
            return ans;
        }
        //lets see what we can do
        st.push({root,1});
        while(!st.empty()){
            pair<TreeNode*,int> p=st.top();
            ans=max(ans,p.second);
            st.pop();
            if(p.first->left) st.push({p.first->left,p.second+1});
            if(p.first->right) st.push({p.first->right,p.second+1});
        }

        return ans;
    }
};