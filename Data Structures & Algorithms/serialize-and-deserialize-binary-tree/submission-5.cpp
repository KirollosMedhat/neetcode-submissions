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

class Codec {
public:

    string serialize(TreeNode* root){
        string serial;
        serializeHelper(root, serial);
        cout<<serial<<endl;
        return serial;
    }
    

    // Encodes a tree to a single string.
    void serializeHelper(TreeNode* root, string& serial) {
        //static string serial = "";
        if(!root){
            serial.append("#,");
            return;
        }

        //serial.append((char)root->val);
        serial += to_string(root->val) + ",";
        serializeHelper(root -> left, serial);
        serializeHelper(root -> right, serial);
    }


    TreeNode* deserialize(string data) {
        int i = 0;
        return deserializeHelper(data, i);
    }

    // Decodes your encoded data to tree.
    /*
    * The code failed when the function was deserializeHelper(string data, int& i){}
    * and also failed when it was deserializeHelper(string& data, int&i){}
    * Submission only worked when it was made TreeNode* deserializeHelper(const string& data, int& i){}
    * As it was taking a lot of time in the first 2 trials.
    *
    *
    *
    **/

    TreeNode* deserializeHelper(string& data, int& i) {
        string currentNode = "";

        for(; data[i] != ','; i++){
            currentNode += data[i];
        }
        i++;

        if(currentNode == "#") return nullptr;


        cout << stoi(currentNode) << endl;


        TreeNode* root = new TreeNode(stoi(currentNode));

        root -> left = deserializeHelper(data, i);
        root -> right = deserializeHelper(data, i);

        return root;
    }
};
