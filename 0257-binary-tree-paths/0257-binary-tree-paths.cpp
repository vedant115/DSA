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
private:
    void dfs(TreeNode* root, string currPath, vector<string>& res){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(currPath+to_string(root->val));
            return;
        }
        dfs(root->left, currPath+to_string(root->val)+"->", res);
        dfs(root->right, currPath+to_string(root->val)+"->", res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
};