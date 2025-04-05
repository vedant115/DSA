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
    pair<TreeNode*, int> dfs(TreeNode* root, int depth){
        if(!root) return {NULL, depth};

        auto left = dfs(root->left, depth+1);
        auto right = dfs(root->right, depth+1);

        if(left.second > right.second){
            return {left.first, left.second};
        }
        else if(left.second < right.second){
            return {right.first, right.second};
        }
        return {root, left.second};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root, 0).first;
    }
};