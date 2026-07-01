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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key){
            if (root->left == nullptr){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            TreeNode* par = root;
            TreeNode* temp = root->left;
            while(temp->right){
                par = temp;
                temp = temp->right;
            }
            if (par == root){
                temp->right = root->right;
                delete root;
                return temp;
            }//Now we're at good position to do something crazy 
            else if (temp->left){
                par->right = temp->left;
                root->val = temp->val;
                delete temp;
            }
            else{
                cout << par->val << " " << temp->val << endl;
                root->val = temp->val;
                par->right = nullptr;
                delete temp;
            }
        }else if (root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};