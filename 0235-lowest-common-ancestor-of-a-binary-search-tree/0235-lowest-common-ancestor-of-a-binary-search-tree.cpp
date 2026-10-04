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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while(1){
                //check where p and q would go
                if(p->val<curr->val && q->val<curr->val){
                    //pass down to lower of child
                    curr=curr->left;
                }
                else if(p->val > curr->val && q->val > curr->val){
                    curr=curr->right;
                }
                else{
                    return curr;
                }
            }

            return curr;
    }
};