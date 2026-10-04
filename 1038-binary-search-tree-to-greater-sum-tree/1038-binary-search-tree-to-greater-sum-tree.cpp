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
    int sum=0;
    void reverseinorder(TreeNode* root){
            //you have to go right first
            if(root==nullptr){
                return ;
            }
            if(!root->left && !root->right){
                root->val+=sum;
                sum=root->val;
                return ;
            }
            //goinr right
            reverseinorder(root->right);
            //now i need to process whole thing
            root->val+=sum;
            sum=root->val;
            reverseinorder(root->left);

            return ;

    }
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* temp=root;
        reverseinorder(temp);
        return root;
    }
};