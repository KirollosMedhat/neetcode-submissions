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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        } else {
            return false;
        }
        
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current -> val == subRoot -> val){
                if(isSameTree(current, subRoot)) return true;
            }
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
      
            if (current->right != nullptr) {
                q.push(current->right);
            }

        }

        return false;
    }
};
