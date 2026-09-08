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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        queue<TreeNode*> q;

        q.push(root);
        vector<int> vec;
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            vec.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);

            
        }

        sort(vec.begin(),vec.end());

        for (int i:vec){
            cout<<i;
        }

        return vec[k-1];
    }
};
