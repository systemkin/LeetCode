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
    int sumOfLeftLeaves(TreeNode* root) {
        if ((root->left == nullptr) && (root->right == nullptr))
        {
            if (b)
                result += root->val;
            return 0;
        }
            
        if (root->left != nullptr){
            b = true;
            sumOfLeftLeaves(root->left);
        }
        if (root->right != nullptr){
            b = false;
            sumOfLeftLeaves(root->right);
        }
        return result;
    }
private:
    int result = 0;
    bool b = false;
};
