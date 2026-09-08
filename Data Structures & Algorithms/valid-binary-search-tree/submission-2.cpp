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

    bool checkNode(TreeNode* root, int lb, int ub){

        if(root == nullptr){
            return true;
        }

        if(lb < root->val && root->val < ub){
            return checkNode(root->left, lb, root->val) && checkNode(root->right, root->val, ub);

        }else{
            return false;
        }

    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return false;

        return checkNode(root, INT_MIN, INT_MAX);
    }
};
