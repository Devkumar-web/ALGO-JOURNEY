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
        bool validtree(TreeNode* root,long long maxval,long long minval){
            if(root==nullptr){
                return true;
            }
            if(root->val<=minval || root->val>=maxval){
                return false;
            }

            return validtree(root->left,root->val,minval)&&validtree(root->right,maxval,root->val);
        }
    bool isValidBST(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        return validtree(root,LLONG_MAX,LLONG_MIN);
    }
};