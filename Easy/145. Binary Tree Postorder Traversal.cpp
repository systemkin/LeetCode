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
//This function is need for memory save (cause if recursively return vector - we will lost memory)
//Idea about this function came to me after "beats 12%". this beats 76.40%
    void onestep(TreeNode* root) {
        if(root == nullptr)
            return;;
        onestep(root->left);
        onestep(root->right);
        result.emplace_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>{};
        onestep(root->left);
        onestep(root->right);
        result.emplace_back(root->val);
        return result;
    }
private:
    vector<int> result;
};
