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
    bool ismirror(TreeNode* first,TreeNode* second){
        if(first==nullptr || second==nullptr){
            return first==second;
        }
        if(first->val!=second->val){
            return false;
        }

        return ismirror(first->left,second->right) && ismirror(first->right,second->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr ){
            return true ;
        }

        return ismirror(root->left ,root->right);
    }
};