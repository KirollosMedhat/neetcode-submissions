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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;

        TreeNode* current = root;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            vector<int> temp;
            for(int i = 0; i < level; i++){
                if(! q.empty()) current = q.front();
                temp.push_back(current -> val);
                if(current->left) q.push(current->left);

                if(current->right) q.push(current->right);
                q.pop();
            }
            res.push_back(temp);
            level = q.size();
            if(! q.empty()){
                current = q.front();
            } else {
                current = nullptr;
            }


        }


        return res;
        
    }
};
