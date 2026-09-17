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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;
        TreeNode* temp=root;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        //now we have entered all left now we should traverse while stack is not empty
        while(!st.empty()){
            TreeNode * node=st.top();
            st.pop();

            //now this is leftmost so this is our answer
            result.push_back(node->val);
            node=node->right;
            while(node){
                st.push(node);
                node=node->left;
            }
        }

        return result;
    }
};