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
        //if mode is =1 take it normal
        //else reverse it than push it into result;
        vector<vector<int>> result;
        if(root==nullptr){
            return result;
        }
        bool rev=false;
        q.push(root);

        while(!q.empty()){
            int loop=q.size();
            vector<int> temp;

            for(int i=0;i<loop;i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);

            }
            if(rev)
                reverse(temp.begin(),temp.end());
            

            rev=!rev;
            

            result.push_back(temp);
        }

        return result;
    }
};